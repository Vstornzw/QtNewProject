#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "Qt5_9CDeveloperGuide_global.h"
#include    "qdicethread13_1.h"

namespace Ui {
class Dialog;
}

class QT5_9CDEVELOPERGUIDE_EXPORT Dlg13_1ThreadSignal : public QDialog
{
    Q_OBJECT

private:
    QDiceThread   threadA;

protected:
    void    closeEvent(QCloseEvent *event);

public:
    explicit Dlg13_1ThreadSignal(QWidget *parent = 0);
    ~Dlg13_1ThreadSignal();

private slots:
    void    onthreadA_started();//线程start时，槽函数接收信号
    void    onthreadA_finished();
    void    onthreadA_newValue(int seq, int diceValue);

    void on_btnClear_clicked();

    void on_btnDiceEnd_clicked();

    void on_btnDiceBegin_clicked();

    void on_btnStopThread_clicked();

    void on_btnStartThread_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
