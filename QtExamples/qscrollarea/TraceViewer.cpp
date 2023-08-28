#include "TraceViewer.h"
#include "ui_TraceViewer.h"

TraceViewer::TraceViewer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TraceViewer)
{
    ui->setupUi(this);
}

TraceViewer::~TraceViewer()
{
    delete ui;
}

