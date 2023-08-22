#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_myGauge1 = new myGauge1(this);
    m_button = new QPushButton(this);

    m_vhlayout = new QVBoxLayout(this);
    m_vhlayout->addWidget(m_myGauge1);
    m_vhlayout->addWidget(m_button);
    this->setLayout(m_vhlayout);
}

Widget::~Widget()
{
    delete ui;
}

