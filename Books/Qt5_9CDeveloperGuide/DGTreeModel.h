#ifndef DGTREEMODEL_H
#define DGTREEMODEL_H

#include <QAbstractItemModel>
#include "Qt5_9CDeveloperGuide_global.h"
#include <QVariant>
class QT5_9CDEVELOPERGUIDE_EXPORT CTreeItem
{
public:
    CTreeItem(const QVariantList &data, CTreeItem *parent = NULL);
    ~CTreeItem();

    void addChildItem(CTreeItem *item);
    CTreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    bool setData(const int &column, const QVariant &value);
    CTreeItem *parent();
    int row() const;
    void clear();
    bool setInternalData(void *ptr)
    {
        m_dataPtr = ptr;
        return true;
    }
    void *getInternalData()
    {
        return m_dataPtr;
    }
    QVariantList GetQVariantList() {return m_itemData;}
private:
    CTreeItem *m_parentItem;//无需在析构函数中释放
    QVariantList m_itemData;//无需在析构函数中释放
    QList<CTreeItem*> m_childItems;
    void *m_dataPtr;  // 用来存储复杂数据，使用强制类型转换可通过此变量获取存入的数据
};



#include <QAbstractItemModel>
enum TreeNodeType
{
    ROOT = -1,
    CHAPTER,
    EXAMPLE
};

class QT5_9CDEVELOPERGUIDE_EXPORT DGTreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit DGTreeModel(const QStringList& headers = QStringList(), QObject *parent = nullptr);
    ~DGTreeModel();

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    CTreeItem *rootItem() {return m_rootItem;}

    void updateTree();

private:
    CTreeItem *itemFromIndex(const QModelIndex &index) const;

private:
    CTreeItem *m_rootItem;
    QStringList m_headers;
};

#endif // DGTREEMODEL_H
