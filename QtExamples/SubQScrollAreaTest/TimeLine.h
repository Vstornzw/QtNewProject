#ifndef TIMELINE_H
#define TIMELINE_H

#include <QScrollArea>
#include <QWidget>
#include <QMouseEvent>
#include <QPointF>
#include <QRect>
#include <QPainter>

class TimeLine : public QScrollArea
{
    Q_OBJECT


public:
    TimeLine(QWidget *parent = nullptr);
    ~TimeLine();
    void Layout();
protected:
    void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

    void painterEvent(QPaintEvent *e) Q_DECL_OVERRIDE;

private:
    void OnResetZoomClicked();
private:
    bool mPressed;
    bool mShowCursor;
    QPointF mPressPos;
    QRect mPressedEidRect;
    QPoint mPos;//移动鼠标对应鼠标坐标点
    double mCurMouseEid;

    double mZoom;

    int mPan;
};

#endif // TIMELINE_H
