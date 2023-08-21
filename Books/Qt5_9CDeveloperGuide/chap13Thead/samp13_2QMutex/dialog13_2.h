#ifndef DIALOG13_2_H
#define DIALOG13_2_H

#include <QDialog>
#include <QTimer>
#include "Qt5_9CDeveloperGuide_global.h"
#include "qdicethread13_2.h"
namespace Ui {
class Dialog;
}

class QT5_9CDEVELOPERGUIDE_EXPORT Dia13_2QMutex : public QDialog
{
    Q_OBJECT

private:
    int mSeq,mDiceValue;

    QDiceThread13_2   threadA;
    QTimer  mTimer;//定时器
protected:
    void    closeEvent(QCloseEvent *event);
public:
    explicit Dia13_2QMutex(QWidget *parent = 0);
    ~Dia13_2QMutex();

private slots:
    void onthreadA_started();
    void onthreadA_finished();

    void onTimeOut(); //定期器处理槽函数
    void on_btnClear_clicked();
    void on_btnStartThread_clicked();//启动线程
    void on_btnStopThread_clicked();//结束线程
    void on_btnDiceBegin_clicked();//开始掷骰子
    void on_btnDiceEnd_clicked();//暂停掷骰子

private:
    Ui::Dialog *ui;
};

#endif // DIALOG13_2_H
