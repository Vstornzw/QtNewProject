#include <QAbstractItemView>
#include <QDebug>
#include "Qt5_9CDeveloperGuideWidget.h"
#include "ui_Qt5_9CDeveloperGuideWidget.h"
#include "DGTreeModel.h"
#include "chap13Thead/samp13_1ThreadSignal/dialog13_1.h"


Qt5_9CDeveloperGuideWidget::Qt5_9CDeveloperGuideWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qt5_9CDeveloperGuideWidget)
{
    ui->setupUi(this);

    initTree();
    ui->treeView->setMouseTracking(true);

}

Qt5_9CDeveloperGuideWidget::~Qt5_9CDeveloperGuideWidget()
{
    delete ui;
}

void Qt5_9CDeveloperGuideWidget::initTree()
{
    DGTreeModel* model = new DGTreeModel(QStringList()<<"header", ui->treeView);
    ui->treeView->setModel(model);
    CTreeItem *root =model->rootItem();


    CTreeItem *item = new CTreeItem(QVariantList()<<QString::fromLocal8Bit("chap12")<<CHAPTER<<1, root);
    // test1
    CTreeItem *item3 = new CTreeItem(QVariantList()<<QString("test1")<<EXAMPLE<<2, item);
    item->addChildItem(item3);
    // test2
    CTreeItem *item4 = new CTreeItem(QVariantList()<<QString("test2")<<EXAMPLE<<2, item);
    item->addChildItem(item4);
    root->addChildItem(item);

    item = new CTreeItem(QVariantList()<<"chap13"<<CHAPTER<<1, root);
    // test1
    CTreeItem *item1 = new CTreeItem(QVariantList()<<QString("1ThreadSignal")<<EXAMPLE<<2, item);
    item->addChildItem(item1);
    // test2
    CTreeItem *item2 = new CTreeItem(QVariantList()<<QString("test2")<<EXAMPLE<<2, item);
    item->addChildItem(item2);
    root->addChildItem(item);

    ui->treeView->setHeaderHidden(true);

    connect(model, SIGNAL(modelReset()), ui->treeView, SLOT(expandAll()));
    ui->treeView->collapseAll();
}

void Qt5_9CDeveloperGuideWidget::mousePressEvent(QMouseEvent *e)
{
   qDebug() << "0";
    if( e->button() == Qt::LeftButton )          //是否左键按下
    {
        QModelIndex index = ui->treeView->indexAt(e->pos());  //取出按下点的元素索引index
        if(!index.parent().isValid())
        {
            return;
        }
        qDebug() << "1";
        CTreeItem *item = static_cast<CTreeItem*>(index.internalPointer());
        if (item->GetQVariantList().value(1) == TreeNodeType::CHAPTER) {
            qDebug() << "i an CHAPTER";
        } else if (item->GetQVariantList().value(1) == TreeNodeType::EXAMPLE) {
            Dialog13_1 dig(this);
            dig.exec();
            qDebug() << "i an EXAMPLE";
        }

    }
}

void Qt5_9CDeveloperGuideWidget::on_pushButton_clicked()
{
    Dialog13_1 dig(this);
    dig.exec();
}

