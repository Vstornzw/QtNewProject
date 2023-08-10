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

CTreeItem *DGTreeModel::itemFromIndex(const QModelIndex &index) const
{
    if (index.isValid())
    {
        CTreeItem *item = static_cast<CTreeItem*>(index.internalPointer());
        return item;
    }
    return m_rootItem;
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
        return item->data(index.column());
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
    if (item)
        return createIndex(row, column, item);
    else
        return QModelIndex();
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

Qt::ItemFlags DGTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    CTreeItem* item = (CTreeItem*)index.internalPointer();
    if (item)
    {
        if (item->data(2).toInt() == 1)
        {
            Qt::ItemFlags flag = QAbstractItemModel::flags(index);
            return flag | Qt::ItemIsDropEnabled;
        }
    }
    Qt::ItemFlags flag = QAbstractItemModel::flags(index);
    return flag | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;

//    return Qt::ItemIsEditable; // FIXME: Implement me!
}

//QMimeData *DGTreeModel::mimeData(const QModelIndexList &indexes) const
//{
//    if (indexes.count() <= 0)
//        return 0;

//    QMimeData* mimeData = QAbstractItemModel::mimeData(indexes);

//    QModelIndex index = indexes.at(0);

//    CTreeItem* item = (CTreeItem*)index.internalPointer();
//    mimeData->setData("name", item->data(0).toByteArray());
//    mimeData->setData("type", item->data(1).toByteArray());
//    mimeData->setData("level", item->data(1).toByteArray());

//    return mimeData;

//}

//bool DGTreeModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
//{
//    int type = data->data("type").toInt();
//    QString name = data->data("name");

//    CTreeItem *item = static_cast<CTreeItem*>(parent.internalPointer());
//    int ptype = item->data(1).toInt();
//    int plevel = item->data(2).toInt();

//    switch (plevel)
//    {
//    case 1:
//    {
//        if (type == ptype)
//            item->addChildItem(new CTreeItem(QVariantList()<<name<<type<<2, item));
//        break;
//    }
//    case 2:
//    {
//        if (type == ptype)
//            item->parent()->addChildItem(new CTreeItem(QVariantList()<<name<<type<<2, item->parent()));
//        break;
//    }
//    default:
//        break;
//    }

//    beginResetModel();
//    endResetModel();

//    return true;
//}

//QStringList DGTreeModel::mimeTypes() const
//{
//    QStringList types;
//    types << "drag";
//    return types;
//}
