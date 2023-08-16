#include <QAbstractItemView>

#include "Qt5_9CDeveloperGuideWidget.h"
#include "ui_Qt5_9CDeveloperGuideWidget.h"
#include "DGTreeModel.h"


Qt5_9CDeveloperGuideWidget::Qt5_9CDeveloperGuideWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qt5_9CDeveloperGuideWidget)
{
    ui->setupUi(this);

    initTree();

}

Qt5_9CDeveloperGuideWidget::~Qt5_9CDeveloperGuideWidget()
{
    delete ui;
}

void Qt5_9CDeveloperGuideWidget::initTree()
{
//    DGTreeModel* model = new DGTreeModel(QStringList()<<"header", ui->treeView);
//    ui->treeView->setModel(model);
//    CTreeItem *root =model->rootItem();

//    CTreeItem *item = new CTreeItem(QVariantList()<<"班级"<<CLASS<<1, root);
//    for (int i = 0; i < 5; i++)
//    {
//        CTreeItem *item1 = new CTreeItem(QVariantList()<<QString("计12%1").arg(i)<<CLASS<<2, item);
//        item->addChildItem(item1);
//    }
//    root->addChildItem(item);
//    item = new CTreeItem(QVariantList()<<"课程"<<COURSE<<1, root);
//    root->addChildItem(item);

//    for (int i = 0; i < 5; i++)
//    {
//        CTreeItem *item1 = new CTreeItem(QVariantList()<<QString("课程%1").arg(i)<<COURSE<<2, item);
//        item->addChildItem(item1);
//    }

//    ui->treeView->setHeaderHidden(true);




//    ui->treeView->setDragEnabled(true);   // 接受drag
//    ui->treeView->setAcceptDrops(true); 				//接受放置数据
//    ui->treeView->setDropIndicatorShown(true);		//显示放置位置
//    ui->treeView->setDragDropMode(QAbstractItemView::DragDrop);   //设置拖放模式为支持拖放

//    connect(model, SIGNAL(modelReset()), ui->treeView, SLOT(expandAll()));
//    ui->treeView->expandAll();


    DGTreeModel* model = new DGTreeModel(QStringList()<<"header", ui->treeView);
    ui->treeView->setModel(model);
    CTreeItem *root =model->rootItem();

    CTreeItem *item = new CTreeItem(QVariantList()<<"chap3"<<CLASS<<1, root);

    // test1
    CTreeItem *item1 = new CTreeItem(QVariantList()<<QString("test1")<<COURSE<<2, item);
    item->addChildItem(item1);

    // test2
    CTreeItem *item2 = new CTreeItem(QVariantList()<<QString("test2")<<COURSE<<2, item);
    item->addChildItem(item2);

    root->addChildItem(item);



    item = new CTreeItem(QVariantList()<<QString::fromLocal8Bit("chap4")<<COURSE<<1, root);
    // test1
    CTreeItem *item3 = new CTreeItem(QVariantList()<<QString("test1")<<COURSE<<2, item);
    item->addChildItem(item3);

    // test2
    CTreeItem *item4 = new CTreeItem(QVariantList()<<QString("test2")<<COURSE<<2, item);
    item->addChildItem(item4);
    root->addChildItem(item);


    ui->treeView->setHeaderHidden(true);




    //ui->treeView->setDragEnabled(true);   // 接受drag
    //ui->treeView->setAcceptDrops(true); 				//接受放置数据
    //ui->treeView->setDropIndicatorShown(true);		//显示放置位置
    //ui->treeView->setDragDropMode(QAbstractItemView::DragDrop);   //设置拖放模式为支持拖放



    connect(model, SIGNAL(modelReset()), ui->treeView, SLOT(expandAll()));
    connect(ui->treeView, SIGNAL(clicked(QModelIndex)),
            this,SLOT(onTreeViewClick(QModelIndex)));
    ui->treeView->collapseAll();
}

void Qt5_9CDeveloperGuideWidget::onTreeViewClick(QModelIndex &index)
{

}
