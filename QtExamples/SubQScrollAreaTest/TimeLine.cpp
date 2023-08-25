#include "TimeLine.h"
#include  <QtGlobal>
double MAX_ZOOM_RATE = 2500.f;

TimeLine::TimeLine(QWidget *parent) : QScrollArea(parent),
    mPressed(false),
    mShowCursor(false),
    mPan(0)
{

}

TimeLine::~TimeLine()
{

}

void TimeLine::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p(viewport());
    p.setFont(mFont);
    //绘制背景色
    DrawBackGroud(p);

    //绘制Eid对应的黑框（左侧缺失的矩形）
    DrawEidLineBounding(p);
    //绘制Eid的数字
    DrawEidLabel(p);
    //绘制鼠标所在位置的eid背景色
    DrawCursor(p);

    // 绘制数据
    DrawDrawAndTextture(p);
    DrawRenderpass(p);
    DrawViewport(p);
    DrawProgram(p);

    //绘制当前eid的位置
    DrawCurPressedEid(p);
}

void TimeLine::OnResetZoomClicked()
{
    mZoom = 1;
    Layout();
}

void TimeLine::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    Layout();
}

void TimeLine::wheelEvent(QWheelEvent *e)
{
    qreal prevZoom = mZoom;
    qreal maxZoom = INT_MAX / mArea.width();
    /*
    最大缩放比例 INT_MAX_RATE = 2500.0f
    在滚轮时间处理函数中，使用QWheelEvent类的delta()函数获取了滚轮移动的距离，每当滚轮旋转以下，
    默认是15°，这是delta()函数就会返回15*8即整数120.
    当滚轮向远离使用者的方向旋转时，返回正直；否则返回负值
    这样可以利用这个函数返回值来判断滚轮的移动方向，从而进行编辑器中的内容放大或者缩小操作
    */
    float mod = (1.0 + e->delta() / MAX_ZOOM_RATE);
    mZoom = qMax(1.0, mZoom * mod);
    mZoom = qBound(1.0, mZoom, maxZoom);
    qreal zoomDelta = (mZoom / prevZoom);
    qreal newPan = mPan;
    newPan -= (e->x());
    newPan = newPan*zoomDelta;
    newPan += (e->x());
    qreal virtualSize = mArea.width() * mZoom;
    mPan = qBound(-(virtualSize - mArea.width()),newPan, 0.0);
    Layout();

}

void TimeLine::mouseMoveEvent(QMouseEvent *e)
{
    mShowCursor = true;//鼠标移动时mShowCursor=true,实现painter中的label随着鼠标移动而移动变色
    //移动QArea
    if(mPressed)
    {
        QPointF current = e->localPos();
        int distance = current.x() - mPressPos.x();
        mPan += distance;
        qreal virtualSize = mArea.width() * mZoom;
        mPan = qBound(-(virtualSize - mArea.width()), mPan, 0.0);
        mPressPos = current;
    }
    mPos = e->pos();

    mCurMouseEid = GetIntValue(GetValueByPos(mPan.x()));
    //调用painterEvent函数
    viewport()->update();
}

void TimeLine::mousePressEvent(QMouseEvent *e)
{
    if(e->modifiers() == Qt::ControlModifier)//设置键盘按下Ctrl键后 移动QArea
    {
        mPressPos = e->localPos();
        mPressed = true;
    } else {
        if (mPressedEidRect.contains(e->pos()))
        {
            //JumpToEid(mCurrentPressedEid);
            return;
        }
    }
    viewport()->update();
}


void TimeLine::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    mPressed = false;
    viewport()->update();
}
