#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <toolwindowmanager/ToolWindowManager.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionaction_Qt5_9C_DeveloperGuide_triggered();

private:

    ToolWindowManager *mainToolManager();
    ToolWindowManager::AreaReference mainToolArea();
    ToolWindowManager::AreaReference leftToolArea();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
