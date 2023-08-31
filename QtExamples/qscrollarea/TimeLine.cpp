#include "TimeLine.h"
#include <QToolTip>
#include <QMessageBox>
#include <QPixmap>
#include <qdebug.h>
namespace  {
//字体大小
constexpr   int FONT_SIZE = 12;
//eid显示行的高度
constexpr   int EID_LABEL_COLUMN_HEIGHT = 24;
// 最大缩放比例
constexpr   float MAX_ZOOM_RATE = 2500.0f;
//提示框显示时间
constexpr   int TOOLTIP_DISPLAY_TIME = 5000;
//图片边距
constexpr   int PIXMAP_MARGIN = 5;
}

void TimeLineScrollBar::enterEvent(QEvent *e)
{
    MouseEnterSignal();
}

TimeLine::TimeLine(QWidget *parent) : QScrollArea(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mScrollBar = QSharedPointer<TimeLineScrollBar> (new TimeLineScrollBar(Qt::Orientation::Horizontal));
    setHorizontalScrollBar(mScrollBar.data());

    setMouseTracking(true);
    mFont.setFamily("msyh");
    mFont.setPointSize(FONT_SIZE);
}

void TimeLine::SetLineHeight(const int &LineHeight)
{
    mLineHeight = LineHeight;
}

void TimeLine::Init()
{
    mCursorBlackgroundColor = QColor("#5ABBXCB");
    mTextHightLightColor = Qt::red;
    mReadColor = QColor("#ecad9e");
    mReadColor = QColor("#e6ceac");
    mReadColor = QColor("#f4606c");
    mReadColor = QColor("#19caad");
    mReadColor = QColor("#BBDED6");
    mReadColor = QColor("#62C0BF");
    mReadColor = Qt::black;
    mReadColor = QColor("#E9E7E3");
    mSelectedResourceRect = -1;
    mCurrentMarkIndex = -1;
    mMaxEid = 3000;//这里不是通过函数而是通过直接赋值
    connect(horizontalScrollBar(), &QScrollBar::valueChanged,
            [this](int value) {
        mPan= - value;
        qDebug() <<QString("mPan : %s == ").asprintf(QString::number(mPan).toStdString().c_str());
        qDebug() <<QString("value : %s == ").asprintf(QString::number(value).toStdString().c_str());
        qDebug() <<QString("maximum : %s == ").asprintf(QString::number(horizontalScrollBar()->maximum()).toStdString().c_str());
        qDebug() <<QString("minimum : %s == ").asprintf(QString::number(horizontalScrollBar()->minimum()).toStdString().c_str());
        qDebug() <<QString("pageStep : %s == ").asprintf(QString::number(horizontalScrollBar()->pageStep()).toStdString().c_str());
        viewport()->update();
    });
    connect(mScrollBar.get(), &TimeLineScrollBar::MouseEnterSignal,this, [this](){
        mShowCursor = false;
        viewport()->update();
    });

    Layout();
}

void TimeLine::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    Layout();
    QWidget::resizeEvent(e);
}

void TimeLine::Layout()
{
    //eid的显示步长（隔多少显示一个label）
    mEidAxisLabelStep = 1;

    QFontMetrics fm(mFont);
    //字长留边距
    mMaxEidWidth = fm.horizontalAdvance(QString::number(mMaxEid)) * 2;
    mArea = viewport()->rect();

    //整体缩放比情况下的虚拟宽度
    qreal virtualSize = mArea.width() * mZoom;
    if ( virtualSize == 0) {
        return ;
    }

    int stepSize = 1;
    int stepMagnitude = 1;
    while(virtualSize > 0 && (qreal(mMaxEid) / qreal(mEidAxisLabelStep)) * mMaxEidWidth > virtualSize) {

    }
}





















