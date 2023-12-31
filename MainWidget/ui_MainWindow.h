/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <toolwindowmanager/ToolWindowManager.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Qt5_9C_DeveloperGuide;
    QAction *action_DashBoardOne;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    ToolWindowManager *toolWindowManager;
    QMenuBar *menubar;
    QMenu *menuBooks;
    QMenu *menuCodeFiles;
    QMenu *menuDraws;
    QMenu *menuMVC;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action_Qt5_9C_DeveloperGuide = new QAction(MainWindow);
        action_Qt5_9C_DeveloperGuide->setObjectName(QString::fromUtf8("action_Qt5_9C_DeveloperGuide"));
        action_DashBoardOne = new QAction(MainWindow);
        action_DashBoardOne->setObjectName(QString::fromUtf8("action_DashBoardOne"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        toolWindowManager = new ToolWindowManager(centralwidget);
        toolWindowManager->setObjectName(QString::fromUtf8("toolWindowManager"));

        verticalLayout_3->addWidget(toolWindowManager);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuBooks = new QMenu(menubar);
        menuBooks->setObjectName(QString::fromUtf8("menuBooks"));
        menuCodeFiles = new QMenu(menubar);
        menuCodeFiles->setObjectName(QString::fromUtf8("menuCodeFiles"));
        menuDraws = new QMenu(menubar);
        menuDraws->setObjectName(QString::fromUtf8("menuDraws"));
        menuMVC = new QMenu(menubar);
        menuMVC->setObjectName(QString::fromUtf8("menuMVC"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBooks->menuAction());
        menubar->addAction(menuCodeFiles->menuAction());
        menubar->addAction(menuDraws->menuAction());
        menubar->addAction(menuMVC->menuAction());
        menuBooks->addAction(action_Qt5_9C_DeveloperGuide);
        menuDraws->addAction(action_DashBoardOne);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_Qt5_9C_DeveloperGuide->setText(QApplication::translate("MainWindow", "Qt5.9C++DeveloperGuide", nullptr));
#ifndef QT_NO_TOOLTIP
        action_Qt5_9C_DeveloperGuide->setToolTip(QApplication::translate("MainWindow", "action_Qt5.9C++DeveloperGuide", nullptr));
#endif // QT_NO_TOOLTIP
        action_DashBoardOne->setText(QApplication::translate("MainWindow", "DashBoardOne", nullptr));
#ifndef QT_NO_TOOLTIP
        action_DashBoardOne->setToolTip(QApplication::translate("MainWindow", "action_DashBoardOne", nullptr));
#endif // QT_NO_TOOLTIP
        menuBooks->setTitle(QApplication::translate("MainWindow", "Books", nullptr));
        menuCodeFiles->setTitle(QApplication::translate("MainWindow", "ClassApplicate", nullptr));
        menuDraws->setTitle(QApplication::translate("MainWindow", "Draws", nullptr));
        menuMVC->setTitle(QApplication::translate("MainWindow", "MVC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
