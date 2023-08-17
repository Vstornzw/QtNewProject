#include "DGTreeModel.h"
#include <QMimeData>
#include <QByteArray>
CTreeItem::CTreeItem(const QVariantList &data, CTreeItem *parent)
{
    m_parentItem = parent;
    m_itemData = data;
}

CTreeItem::~CTreeItem()
{
    qDeleteAll(m_childItems);
    m_childItems.clear();
}

void CTreeItem::addChildItem(CTreeItem *item)
{
    m_childItems.append(item);
}

CTreeItem *CTreeItem::child(int row)
{
    if (row > -1 && row < m_childItems.count())
        return m_childItems.value(row);
    return NULL;
}

int CTreeItem::childCount() const
{
    return m_childItems.count();
}

int CTreeItem::columnCount() const
{
    return m_itemData.count();
}

QVariant CTreeItem::data(int column) const
{
    if (column > -1 && column < m_itemData.count())
        return m_itemData.value(column);
    return QVariant();
}

bool CTreeItem::setData(const int &column, const QVariant &value)
{
    int ret = false;

    if (column > -1 && column < columnCount())
    {
        m_itemData.replace(column, value);
        ret = true;
    }
    if (columnCount() == column)
    {
        m_itemData.append(value);
        ret = true;
    }

    return ret;
}

CTreeItem *CTreeItem::parent()
{
    return m_parentItem;
}

int CTreeItem::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<CTreeItem*>(this));

    return 0;
}

void CTreeItem::clear()
{
    for (auto child : m_childItems)
    {
        child->clear();
    }
    qDeleteAll(m_childItems);
    m_childItems.clear();
}


DGTreeModel::DGTreeModel(const QStringList& headers, QObject *parent)
    : QAbstractItemModel(parent)
{
    m_headers = headers;
    m_rootItem = new CTreeItem(QVariantList());
}

DGTreeModel::~DGTreeModel()
{
    delete m_rootItem;
}

// 获取表头数据
QVariant DGTreeModel::headerData(int section, Qt::Orientation orientation,int role) const
{
    if (orientation == Qt::Horizontal)
    {
        if(role == Qt::DisplayRole)
        {
            return m_headers.at(section);
        }
    }
    return QVariant();
}

// 获取index.row行，index.column列数据
QVariant DGTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    CTreeItem *item = itemFromIndex(index);
    if (role == Qt::DisplayRole)
    {
        return item->data(index.column());//本次界面只有一列，故只返回名称
    }
    return QVariant();
}

// 在parent节点下，第row行，第column列位置上创建索引
QModelIndex DGTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    CTreeItem *parentItem = itemFromIndex(parent);
    CTreeItem *item = parentItem->child(row);
    if (item) {
        //与CTreeItem *item = static_cast<CTreeItem*>(index.internalPointer());对应
        return createIndex(row, column, item);
    } else {
        return QModelIndex();
    }
}

// 创建index的父索引
QModelIndex DGTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    CTreeItem *item = itemFromIndex(index);
    CTreeItem *parentItem = item->parent();

    if (parentItem == m_rootItem)
        return QModelIndex();
    return createIndex(parentItem->row(), 0, parentItem);
}

// 获取索引parent下有多少行
int DGTreeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.column() > 0)
        return 0;

    CTreeItem* item = itemFromIndex(parent);
    return item->childCount();
}

// 返回索引parent下有多少列
int DGTreeModel::columnCount(const QModelIndex &parent) const
{
    return m_headers.size();
}

bool DGTreeModel::hasChildren(const QModelIndex &parent) const
{
    bool ret = false;
    if (parent.column() > 0)
        return ret;

    CTreeItem *item = itemFromIndex(parent);
    if (item->childCount() > 0)
        ret = true;
    return ret;
}

void DGTreeModel::updateTree()
{
    beginResetModel();
    m_rootItem->clear();
    endResetModel();
}

CTreeItem *DGTreeModel::itemFromIndex(const QModelIndex &index) const
{
    if (index.isValid())
    {
        CTreeItem *item = static_cast<CTreeItem*>(index.internalPointer());
        return item;
    }
    return m_rootItem;
}

