#include "dialog13_1.h"
#include "ui_dialog13_1.h"

Dlg13_1ThreadSignal::Dlg13_1ThreadSignal(QWidget *parent) : QDialog(parent),  ui(new Ui::Dialog)
{//构造函数
    ui->setupUi(this);
    connect(&threadA,SIGNAL(started()),this,SLOT(onthreadA_started()));
    connect(&threadA,SIGNAL(finished()),this,SLOT(onthreadA_finished()));

    connect(&threadA,SIGNAL(newValue(int,int)),this,SLOT(onthreadA_newValue(int,int)));
}

Dlg13_1ThreadSignal::~Dlg13_1ThreadSignal()
{
    delete ui;
}

void Dlg13_1ThreadSignal::closeEvent(QCloseEvent *event)
{ //窗口关闭事件，必须结束线程
    if (threadA.isRunning())
    {
        threadA.stopThread();
        threadA.wait();
    }
    event->accept();
}

void Dlg13_1ThreadSignal::onthreadA_started()
{//线程的started()信号的响应槽函数
    ui->LabA->setText(QString::fromLocal8Bit("Thread状态：")+QString("thread started"));
}

void Dlg13_1ThreadSignal::onthreadA_finished()
{//线程的 finished()信号的响应槽函数
    ui->LabA->setText("Thread状态：thread finished");
}

void Dlg13_1ThreadSignal::onthreadA_newValue(int seq,int diceValue)
{//QDiceThread的newValue()信号的响应槽函数，显示骰子次数和点数
    QString  str=QString::fromLocal8Bit("第 ")+QString::asprintf("%d",seq)+
            QString::fromLocal8Bit("次掷骰子，点数为：") + QString::asprintf("%d",diceValue);
    ui->plainTextEdit->appendPlainText(str);

    QPixmap pic; //图片显示
    QString filename=QString::asprintf(":/chap13Thead/samp13_1ThreadSignal/images/d%d.jpg",diceValue);
    pic.load(filename);
    ui->LabPic->setPixmap(pic);
}

void Dlg13_1ThreadSignal::on_btnClear_clicked()
{ //清空文本 按钮
    ui->plainTextEdit->clear();
}

void Dlg13_1ThreadSignal::on_btnDiceEnd_clicked()
{//暂停 掷骰子按钮
    threadA.dicePause();
    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

void Dlg13_1ThreadSignal::on_btnDiceBegin_clicked()
{//开始 掷骰子按钮
    threadA.diceBegin();
    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(true);
}

void Dlg13_1ThreadSignal::on_btnStopThread_clicked()
{//结束线程 按钮
    threadA.stopThread();//结束线程的run()函数执行
    threadA.wait();//

    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);

    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(false);
}

void Dlg13_1ThreadSignal::on_btnStartThread_clicked()
{//启动线程 按钮
    threadA.start();

    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);

    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}
