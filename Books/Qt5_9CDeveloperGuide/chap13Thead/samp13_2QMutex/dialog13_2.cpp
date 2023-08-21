#include "dialog13_2.h"
#include "ui_dialog13_2.h"



Dia13_2QMutex::Dia13_2QMutex(QWidget *parent) :    QDialog(parent),    ui(new Ui::Dialog)
{//构造函数
    ui->setupUi(this);

    connect(&threadA,SIGNAL(started()),this,SLOT(onthreadA_started()));
    connect(&threadA,SIGNAL(finished()),this,SLOT(onthreadA_finished()));

    connect(&mTimer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
}

Dia13_2QMutex::~Dia13_2QMutex()
{
    delete ui;
}

void Dia13_2QMutex::closeEvent(QCloseEvent *event)
{//窗口关闭时
    if (threadA.isRunning())
    {
        threadA.stopThread();
        threadA.wait();
    }
    event->accept();
}

void Dia13_2QMutex::onthreadA_started()
{
    ui->LabA->setText(QString::fromLocal8Bit("Thread状态：thread started"));
}

void Dia13_2QMutex::onthreadA_finished()
{
    ui->LabA->setText(QString::fromLocal8Bit("Thread状态：")+QString("thread finished"));
}

void Dia13_2QMutex::onTimeOut()
{ //定时器到时处理槽函数
    int tmpSeq=0,tmpValue=0;
    bool  valid=threadA.readValue(&tmpSeq,&tmpValue); //读取数值
    if (valid && (tmpSeq!=mSeq)) //有效，并且是新数据
    {
        mSeq=tmpSeq;
        mDiceValue=tmpValue;
        QString  str=QString::fromLocal8Bit("第 ")+QString::asprintf("%d",tmpSeq)+
                QString::fromLocal8Bit("次掷骰子，点数为：") + QString::asprintf("%d",tmpValue);
        ui->plainTextEdit->appendPlainText(str);
        QPixmap pic;
        QString filename=QString::asprintf(":/chap13Thead/samp13_2QMutex/images/d%d.jpg",mDiceValue);
        pic.load(filename);
        ui->LabPic->setPixmap(pic);
    }
}

void Dia13_2QMutex::on_btnClear_clicked()
{//清空文本
    ui->plainTextEdit->clear();
}

void Dia13_2QMutex::on_btnStartThread_clicked()
{//启动线程
    mSeq=0;
    threadA.start();

    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);

    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

void Dia13_2QMutex::on_btnStopThread_clicked()
{//结束线程
    threadA.stopThread();//结束线程的run()函数执行
    threadA.wait();//

    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);

    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(false);
}

void Dia13_2QMutex::on_btnDiceBegin_clicked()
{//开始掷骰子
    threadA.diceBegin();
    mTimer.start(100); //定时器100读取一次数据
    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(true);
}

void Dia13_2QMutex::on_btnDiceEnd_clicked()
{//暂停掷骰子
    threadA.diceEnd(); //
    mTimer.stop();//定时器暂停

    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

