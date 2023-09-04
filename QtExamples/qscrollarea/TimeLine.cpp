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
        //label的步长为1,2,5,10,20,50,100
        if(stepSize == 1) {
            stepSize = 2;
        } else if (stepSize == 2) {
            stepSize = 5;
        }else if (stepSize == 5) {
            stepSize = 1;
            stepMagnitude *= 10;
        }
        mEidAxisLabelStep = stepSize * stepMagnitude;
    }

    //每一个像素与eid数值对比关系
    mPerPixel = mMaxEid / virtualSize;
    qreal savedPan = mPan;
    horizontalScrollBar()->setRange(0,virtualSize - mArea.width());
    horizontalScrollBar()->setValue(-savedPan);
    horizontalScrollBar()->setPageStep(mEidAxisLabelStep);
    qDebug() <<"mPan---"<<mPan;
}

void TimeLine::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p(viewport());
    p.setFont(mFont);

    //绘制背景色
    DrawBackGroud(p);
    //绘制EID对应的黑色框
    DrawEidLineBounding(p);
    //绘制eid 的数字
    DrawEidLabel(p);
    //鼠标光标位置停靠在eid行应画的动态黑框
    DrawCursor(p);

    //绘制数据
    DrawDrawAndTexture(p);
    DrawRenderpass(p);

    //绘制当前eid的位置
    DrawCurPressedEid(p);
}

void TimeLine::DrawBackGroud(QPainter &p)
{
    p.fillRect(viewport()->rect(),Qt::white);
}

void TimeLine::DrawEidLineBounding(QPainter &p)
{
    QPainterPath path;
    path.moveTo(0,0);
    path.lineTo(this->width(), 0);
    path.lineTo(this->width(),mLineHeight - 6);
    path.lineTo(0,mLineHeight - 6);\
    p.drawPath(path);
}

void  TimeLine::DrawEidLabel(QPainter &p)
{
    p.save();
    QRect labelRect(0,1,viewport()->width(),EID_LABEL_COLUMN_HEIGHT - 1);
    p.fillRect(labelRect, mEidLaelBackgroudColor);
    for(uint32_t i = 0; i < mMaxEid; i += mEidAxisLabelStep){
        qreal pos = GetPosByValue(i);
        QRect rc(pos, 0, mMaxEidWidth,EID_LABEL_COLUMN_HEIGHT);
        if(rc.right() < 0) {
            continue;
        }
        //偏移一半的宽度
        rc = rc.adjusted(-mMaxEidWidth / 2, 0, -mMaxEidWidth / 2, 0);//需要按这个调整，否则最大的eid出不来
        if(rc.left() > viewport()->width()) {
            break;
        }
        p.drawText(rc,Qt::AlignCenter,QString::number(i));
    }
    p.restore();
}

qreal TimeLine::GetPosByValue(qreal i)
{
    return qreal(i) / mPerPixel + mPan;
}

void TimeLine::DrawCursor(QPainter &p)
{
    if(mShowCursor) {
        p.save();
        qreal pos = GetPosByValue(GetIntValue(GetValueByPos(mPos.x())));
        p.setBrush(QBrush(mCursorBlackgroundColor));
        qreal cursorLabelWidth = GetPosByValue(1) - GetPosByValue(0);
        if(cursorLabelWidth < mMaxEidWidth) {
            cursorLabelWidth = mMaxEidWidth;
        }
        QRectF mouseTextRect(pos,0,cursorLabelWidth,EID_LABEL_COLUMN_HEIGHT);
        mouseTextRect = mouseTextRect.adjusted(-cursorLabelWidth / 2, 0, -cursorLabelWidth / 2, 0);
        p.drawRect(mouseTextRect);
    }
}





















