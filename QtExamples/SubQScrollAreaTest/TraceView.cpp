#include "TraceView.h"
#include "ui_TraceView.h"

TraceView::TraceView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TraceView)
{
    ui->setupUi(this);
}

TraceView::~TraceView()
{
    delete ui;
}

