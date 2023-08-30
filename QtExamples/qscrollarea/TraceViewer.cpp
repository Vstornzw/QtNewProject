#include "TraceViewer.h"
#include "ui_TraceViewer.h"

TraceViewer::TraceViewer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TraceViewer)
{
    ui->setupUi(this);
    setWindowTitle("TraceViewer");
    ui->exportButton->setToolTip("Export Html");

    mPixmapSize.setWidth(20);
    mPixmapSize.setHeight(20);

    Init();
}

TraceViewer::~TraceViewer()
{
    delete ui;
}

void TraceViewer::Init()
{
    mTimeLine = QSharedPointer<TimeLine>(new TimeLine(this));
    mTimeLine.data()->setStyleSheet(QString("QScrollArea{ border: 0ppx;}"));
    ui->timelineLayout->addWidget(mTimeLine.data());
    mTimeLine.data()->SetLineHeight(ui->label_2->height());
    connect(ui->resetZoomButton, &QToolButton::clicked, mTimeLine.data(), &TimeLine::OnResetZoomClicked);
    connect(ui->preButton,  &QToolButton::clicked, mTimeLine.data(), &TimeLine::OnFindPrevClicked);
    connect(ui->nextButton,  &QToolButton::clicked, mTimeLine.data(), &TimeLine::OnFindNextClicked);

    HideTextureInfo();
    mTimeLine.data()->Init();
}

void TraceViewer::HideTextureInfo() const
{
    ui->textureIdLabel->hide();
    ui->textureIdNumber->hide();
    ui->readColorLabel->hide();
    ui->readColorShowLabel->hide();
    ui->writeColorLabel->hide();
    ui->writeColorShowLabel->hide();
    ui->clearColorLabel->hide();
    ui->clearColorShowLabel->hide();
}
