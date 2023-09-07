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
        p.drawText(mouseTextRect,Qt::AlignCenter,QString::number(GetIntValue(GetValueByPos(mPos.x()))));
        p.restore();
    }
}

int TimeLine::GetIntValue(qreal value)
{
    if(value - int(value) > 0.5) {
        return int(value) + 1;
    } else {
        return (int)value;
    }
}

qreal TimeLine::GetValueByPos(qreal posx)
{
    posx = posx - mPan;
    qreal value = posx * mPerPixel;
    return value;
}

void TimeLine::wheelEvent(QWheelEvent *e)
{
    // delta(),新版的Qt已经将其废除，它的返回值相当于angleDelte()的返回值y
    qreal prevZoom = mZoom;
    qreal maxZoom = INT_MAX / mArea.width();
    float mod = (1.0 + e->delta() / MAX_ZOOM_RATE);
    mZoom = qMax(1.0, mZoom * mod);
    mZoom = qBound(1.0, mZoom, maxZoom);
    qreal zoomDelta = (mZoom / prevZoom);
    qreal newPan = mPan;
    newPan -= (e->x());
    newPan = newPan * zoomDelta;
    newPan += (e->x());
    qreal virtualSize = mArea.width() * mZoom;
    mPan = qBound(-(virtualSize - mArea.width()),newPan, 0.0);

    Layout();
}

void TimeLine::mouseMoveEvent(QMouseEvent *e)
{
    mShowCursor = true;//鼠标移动时mShowCursor=true,实现painter中的label随着鼠标移动而移动变色
    if(mPressed) {
        QPointF current = e->localPos();
        int distance = current.x() - mPressPos.x();
        mPan += distance;
        qreal virtualSize = mArea.width() * mZoom;
        mPan = qBound(-(virtualSize - mArea.width()), mPan, 0.0);
        mPressPos = current;
        //static int a = 0;
        //QMessageBox::information(this, "title", QString::number(a++));
        QToolTip::showText(e->globalPos(),QString::number(e->globalPos().x())+QString("/")+QString::number(e->globalPos().y()),this);
        horizontalScrollBar()->setValue(-mPan);

    }
    mPos = e->pos();

    mCurMouseEid = GetIntValue(GetValueByPos(mPos.x()));
    QString toolTipl;
    //获取当前块
    UpdateMouseHoverBrickInfo(toolTipl);
    if(!toolTipl.isNull()) {
        QToolTip::showText(e->globalPos(),toolTip(), this);
    }

    //调用painterEvent函数
    viewport()->update();
}

void TimeLine::UpdateMouseHoverBrickInfo(QString &toolTip)
{
    if(mLineHeight == 0) {
        return;
    }
    int type = mPos.y() / mLineHeight;
    auto lineType = static_cast<LineType>(type);
    switch (lineType) {
        case DRAW:{
            toolTip = QString("DRAW");
            break;
        }
        case TEXTURE:{
            toolTip = QString("TEXTURE");
            break;
        }
        case RENDERPASS:{
            toolTip = QString("RENDERPASS");
            break;
        }
        case VIEWPORT:{
            toolTip = QString("VIEWPORT");
            break;
        }
        case PROGRAM:{
            toolTip = QString("VIEWPORT");
            break;
        }
        default:
            break;
    }
}

void TimeLine::SetCurEid(QMouseEvent *e)
{
    qreal eid = (qreal)GetIntValue(GetValueByPos(e->pos().x()));
    if(eid != mCurMouseEid) {
        mCurMouseEid = eid;
        if(!mIsFreeModel) {
            JumpToEid();
        }
        else {
            viewport()->update();
        }
    }
}

void TimeLine::mousePressEvent(QMouseEvent *e)
{
    if(e->modifiers() == Qt::ControlModifier) {
        mPressPos = e->localPos();
        mPressed = true;
    } else {

        qDebug() << QString::number(mPressedEidRect.x()) << QString::number(mPressedEidRect.y()) << QString::number(mPressedEidRect.width())<< QString::number(mPressedEidRect.height());
        qDebug() << QString::number(e->pos().x());
        if(mPressedEidRect.contains(e->pos())){
            JumpToEid(mCurPressedEid);
        }
        mCurPressedEid = (qreal)GetIntValue(GetValueByPos(e->pos().x()));
        //JumpToEid(mCurPressedEid);
    }
    viewport()->update();
}

void TimeLine::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    mPressed = false;
    viewport()->update();
}

void TimeLine::DrawDrawAndTexture(QPainter &p)
{
    p.save();
    uint32_t drawIndex = 0;
    for(int i = 0; i < 3000; i++) {
        QString showStr = QString::number(i);
        //绘制draw
        QRect rect = EidMapToRect(i, DRAW);
        if(i % 4 == 0) {
            p.setBrush(mClearColor);
        } else if (i % 4 == 1) {
            p.setBrush(mReadColor);
        }  else if (i % 4 == 2) {
            p.setBrush(mWriteColor);
        } else {
            p.setBrush(mBrickColor);
        }


        SetPenColor(p, mBrickBorderColor);
        p.drawRect(rect);

        QFontMetrics fm = p.fontMetrics();
        SetPenColor(p, mTextColor);
        if (rect.width() > fm.width(showStr)) {
            p.drawText(rect,Qt::AlignCenter,showStr);
        } else {
            p.drawText(rect, Qt::AlignVCenter, showStr);
        }
    }
}

QRect TimeLine::EidMapToRect(const qreal &eid, LineType lineType)
{
    qreal pos = GetPosByValue(eid);
    // 1:计算两个相邻eid之间的距离
    qreal cursorLabelWidth = GetPosByValue(1) - GetPosByValue(0);
    if (cursorLabelWidth <= 0) {
        cursorLabelWidth = 1;
    }
    QRect rect(pos, mLineHeight * (int)lineType,cursorLabelWidth,EID_LABEL_COLUMN_HEIGHT);
    // 2:从中点偏移一半
    rect = rect.adjusted(-cursorLabelWidth / 2, 0, -cursorLabelWidth / 2,0);
    rect.adjust(1,-6,-1,-6);
    if(rect.width() < 0){
        rect.setWidth(0);
    }
    return rect;
}

void TimeLine::SetPenColor(QPainter &p, QColor color)
{
    QPen pen = p.pen();
    pen.setColor(color);
    p.setPen(pen);
}

void TimeLine::DrawRenderpass(QPainter &p)
{
    p.save();
    p.setBrush(mBrickColor);

    QRect beginRect20 = EidMapToRect(20,RENDERPASS);
    QRect endRect35 = EidMapToRect(2500,RENDERPASS);
    QRect renderpassRect = beginRect20.united(endRect35);
    if(renderpassRect.x() < 0) {
        renderpassRect.setX(0);
    }

    SetPenColor(p,mBrickBorderColor);
    renderpassRect.adjust(0,-10,0,-10);
    p.drawRect(renderpassRect);
}

void TimeLine::DrawCurPressedEid(QPainter &p)
{
    //初始化时不画这个
    if(mCurPressedEid < 0) {
        return;
    }
    p.save();;
    qreal curEidPos = GetPosByValue(mCurMouseEid);
    qreal showStartEid = GetIntValue(GetValueByPos(0));
    qreal showEndEid = GetIntValue(GetValueByPos(viewport()->width()));
    mPressedEidRect = QRect();
    QPixmap pixmap;
    if(!pixmap.load("images/save.png")) {
        QToolTip::showText(mPressPos.toPoint(),QString("Error"), this);
        return;
    }

    qreal maxMarkFlagWidth = mMaxEidWidth + pixmap.width() + PIXMAP_MARGIN * 2;
    if(mCurMouseEid >= showStartEid && mCurPressedEid <= showEndEid) {
        qreal unitLabelWidth = GetPosByValue(1) - GetPosByValue(0);
        if(unitLabelWidth >= maxMarkFlagWidth) {
            maxMarkFlagWidth = unitLabelWidth;
        }
        //偏移一半的宽度
        mPressedEidRect = QRect(curEidPos - maxMarkFlagWidth / 2,0,maxMarkFlagWidth,EID_LABEL_COLUMN_HEIGHT);
    } else {
        if(mCurMouseEid < showStartEid) {
            mPressedEidRect = QRect(0,0,maxMarkFlagWidth,EID_LABEL_COLUMN_HEIGHT);
        } else {
            mPressedEidRect = QRect(viewport()->width() - maxMarkFlagWidth,0,
                                    maxMarkFlagWidth,EID_LABEL_COLUMN_HEIGHT);
        }
    }
    //绘制竖线
    if(curEidPos >0 && curEidPos < viewport()->width()) {
        p.drawLine(curEidPos,EID_LABEL_COLUMN_HEIGHT,curEidPos,viewport()->height());
    }
    p.fillRect(mPressedEidRect,Qt::white);
    p.drawRect(mPressedEidRect);
    //图片偏移一半的宽度
    p.drawPixmap(mPressedEidRect.x() + PIXMAP_MARGIN, mPressedEidRect.height() / 2 - pixmap.height() / 2,
                 pixmap.width(),pixmap.height(),pixmap);

    p.drawText(mPressedEidRect.adjusted(pixmap.width() + PIXMAP_MARGIN * 2, 0, 0, 0), Qt::AlignCenter,
               QString::number(mCurPressedEid));
    p.restore();
}

void TimeLine::JumpToEid(int eid)
{

}
















