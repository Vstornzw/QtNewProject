/********************************************************************************
** Form generated from reading UI file 'Qt5_9CDeveloperGuideWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT5_9CDEVELOPERGUIDEWIDGET_H
#define UI_QT5_9CDEVELOPERGUIDEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt5_9CDeveloperGuideWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView;
    QLabel *label;

    void setupUi(QWidget *Qt5_9CDeveloperGuideWidget)
    {
        if (Qt5_9CDeveloperGuideWidget->objectName().isEmpty())
            Qt5_9CDeveloperGuideWidget->setObjectName(QString::fromUtf8("Qt5_9CDeveloperGuideWidget"));
        Qt5_9CDeveloperGuideWidget->resize(720, 376);
        horizontalLayout = new QHBoxLayout(Qt5_9CDeveloperGuideWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        treeView = new QTreeView(Qt5_9CDeveloperGuideWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        horizontalLayout->addWidget(treeView);

        label = new QLabel(Qt5_9CDeveloperGuideWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 3);

        retranslateUi(Qt5_9CDeveloperGuideWidget);

        QMetaObject::connectSlotsByName(Qt5_9CDeveloperGuideWidget);
    } // setupUi

    void retranslateUi(QWidget *Qt5_9CDeveloperGuideWidget)
    {
        Qt5_9CDeveloperGuideWidget->setWindowTitle(QApplication::translate("Qt5_9CDeveloperGuideWidget", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Qt5_9CDeveloperGuideWidget: public Ui_Qt5_9CDeveloperGuideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT5_9CDEVELOPERGUIDEWIDGET_H
