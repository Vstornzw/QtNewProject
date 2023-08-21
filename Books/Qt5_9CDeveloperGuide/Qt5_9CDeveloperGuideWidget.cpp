#include <QAbstractItemView>
#include <QDebug>
#include "Qt5_9CDeveloperGuideWidget.h"
#include "ui_Qt5_9CDeveloperGuideWidget.h"
#include "DGTreeModel.h"
#include "SampDialog.h"
#include "chap13Thead/samp13_1ThreadSignal/dialog13_1.h"
#include "chap13Thead/samp13_2QMutex/dialog13_2.h"


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

    //12
    CTreeItem *item = new CTreeItem(QVariantList()<<QString::fromLocal8Bit("chap12")<<CHAPTER<<1, root);
    // test1
    CTreeItem *item3 = new CTreeItem(QVariantList()<<QString("test1")<<EXAMPLE<<2, item);
    item->addChildItem(item3);
    // test2
    CTreeItem *item4 = new CTreeItem(QVariantList()<<QString("test2")<<EXAMPLE<<2, item);
    item->addChildItem(item4);
    root->addChildItem(item);

    //13
    item = new CTreeItem(QVariantList()<<"chap13"<<CHAPTER<<1, root);
    // 这里第一个要添加类的名哦
    CTreeItem *item1 = new CTreeItem(QVariantList()<<QString("Dlg13_1ThreadSignal")<<EXAMPLE<<2, item);
    item->addChildItem(item1);
    // test2
    CTreeItem *item2 = new CTreeItem(QVariantList()<<QString("Dlg13_2QMutex")<<EXAMPLE<<2, item);
    item->addChildItem(item2);
    root->addChildItem(item);

    ui->treeView->setHeaderHidden(true);

    connect(model, SIGNAL(modelReset()), ui->treeView, SLOT(expandAll()));
    ui->treeView->collapseAll();
}

void Qt5_9CDeveloperGuideWidget::on_treeView_clicked(const QModelIndex &index)
{
    if(!index.isValid())
    {
        return;
    }
    CTreeItem *item = static_cast<CTreeItem*>(index.internalPointer());
    if(item->GetQVariantList().value(1) == TreeNodeType::CHAPTER) {
        qDebug() << "i am CHARTER";
    }
    else if (item->GetQVariantList().value(1) == TreeNodeType::EXAMPLE)
    {
        if (item->GetQVariantList().value(0) == "Dlg13_1ThreadSignal")
        {
            Dlg13_1ThreadSignal dig(this);
            dig.exec();
        } else if (item->GetQVariantList().value(0) == "Dlg13_2QMutex")
        {
            Dia13_2QMutex dig(this);
            dig.exec();
        }
    }
    else
    {
        return ;
    }
}

