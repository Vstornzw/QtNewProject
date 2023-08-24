#ifndef DIALOG13_5_H
#define DIALOG13_5_H

#include    <QDialog>
#include    <QTimer>
#include "Qt5_9CDeveloperGuide_global.h"
#include  "qmythread13_5.h"

namespace Ui {
class Dialog;
}

class QT5_9CDEVELOPERGUIDE_EXPORT Dlg13_5Semaphore : public QDialog
{
    Q_OBJECT

private:
    QThreadDAQ   threadProducer;
    QThreadShow   threadConsumer;
protected:
    void    closeEvent(QCloseEvent *event);
public:
    explicit Dlg13_5Semaphore(QWidget *parent = 0);
    ~Dlg13_5Semaphore();

private slots:
    void    onthreadA_started();
    void    onthreadA_finished();

    void    onthreadB_started();
    void    onthreadB_finished();

    void    onthreadB_newValue(int *data, int count, int bufNo);


    void on_btnClear_clicked();

    void on_btnStopThread_clicked();

    void on_btnStartThread_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG13_5_H
