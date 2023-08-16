#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "Qt5_9CDeveloperGuideWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(4000,2000);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_Qt5_9C_DeveloperGuide_triggered()
{
    Qt5_9CDeveloperGuideWidget *qt5_9CDeveloperGuideWidget = new Qt5_9CDeveloperGuideWidget(this);

    if(ui->toolWindowManager->toolWindows().contains(qt5_9CDeveloperGuideWidget))
        ToolWindowManager::raiseToolWindow(qt5_9CDeveloperGuideWidget);
      else
        ui->toolWindowManager->addToolWindow(qt5_9CDeveloperGuideWidget, leftToolArea());
}

ToolWindowManager *MainWindow::mainToolManager()
{
  return ui->toolWindowManager;
}

ToolWindowManager::AreaReference MainWindow::mainToolArea()
{
  return ToolWindowManager::AreaReference(ToolWindowManager::LastUsedArea);
}

ToolWindowManager::AreaReference MainWindow::leftToolArea()
{
  return ToolWindowManager::AreaReference(ToolWindowManager::LastUsedArea);
}

