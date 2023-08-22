#ifndef DASHBOARDONE_H
#define DASHBOARDONE_H

#include <QWidget>
#include <QtGui>
#include <QPushButton>
#include "../../Draws/DrawsDll/DrawsDll_global.h"

class DRAWSDLL_EXPORT DashBoardOne : public QWidget
{
    Q_OBJECT
public:
    explicit DashBoardOne(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    virtual void mouseMoveEvent(QMouseEvent *e);

//    QSize sizeHint() const
//    {
//        return QSize(200,200);
//    }

//    QSize minimumSizeHint() const
//    {
//        return QSize(150,150);
//    }

private:
    void drawOuterCircle(QPainter* painter);
    void drawInnerCircle(QPainter* painter);
    void drawColorPies(QPainter* painter);
    void drawCoverLines(QPainter* painter);
    void drawCoverCircle(QPainter* painter);
    void drawMarkAndText(QPainter* painter);
    void drawGraph(QPainter* painter);
    void drawTextRect(QPainter* painter);
    void resetVariables(QPainter* painter);

private:
    qreal m_value;
    qreal m_outerRadius;
    qreal m_innerRadius;
    qreal m_colorPieRadius;
    qreal m_coverCircleRadius;
    qreal m_currentValue;
    qreal m_longHand;
    qreal m_okHand;
    qreal m_shortHand;
    qreal m_space;
    bool m_bReverse;
    QTimer* updateTimer;
    QPointF m_center;
    QRectF m_pieRect;

public slots:
    void setValue(qreal value);
    void onStart();

private slots:
    void UpdateGraph();
private:
    QPushButton *m_button;
};

#endif // DASHBOARDONE_H
