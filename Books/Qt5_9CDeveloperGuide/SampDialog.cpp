#include "SampDialog.h"


SampDialog::SampDialog(QWidget *parent,QWidget *widget) :
    QDialog(parent), m_widget(widget)
{
    m_HboxLayout = new QHBoxLayout(this);
    m_HboxLayout->addWidget(m_widget);
    this->setLayout(m_HboxLayout);
}

SampDialog::~SampDialog()
{
    delete m_HboxLayout;
}
