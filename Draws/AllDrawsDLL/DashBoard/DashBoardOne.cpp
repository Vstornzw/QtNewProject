#include "DashBoardOne.h"
#include <QToolTip>
#include <QDebug>
DashBoardOne::DashBoardOne(QWidget *parent) :
        QWidget(parent)
{
    resize(640,480);
    m_value=0;
    m_currentValue=0;
    m_bReverse=false;
    updateTimer=new QTimer(this);
    updateTimer->setInterval(10);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(UpdateGraph()));
    //通过阅读qt源码，这里是默认值 qwdget.cpp 1046行
    int w = width();//640
    int h = height();//480
    m_outerRadius=width()>height() ? height()/2 : width()/2;//240
    m_innerRadius=0.8*m_outerRadius;//192
    m_colorPieRadius=m_outerRadius*0.7;//168
    m_coverCircleRadius=0.7*m_colorPieRadius;//117.6
    m_center=rect().center();//(319,219)
    m_longHand=(qreal)m_outerRadius/20;//12
    m_okHand=0.7*m_longHand;//8.399
    m_shortHand=0.5*m_longHand;//6
    m_space=0.1*m_longHand;//1.2

    m_button = new QPushButton(this);
    m_button->setObjectName(QString::fromUtf8("labValue1"));
    m_button->setText("button");
    m_button->setGeometry(QRect(540, 400, 100, 28));
    m_button->setStyleSheet(QString::fromUtf8(""));
    connect(m_button,SIGNAL(clicked()),this,SLOT(onStart()));
    setMouseTracking(true);
}

void DashBoardOne::onStart()
{
    qDebug() << "1";
    int value=qrand()%100;
    setValue(value);
}


void DashBoardOne::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);

    // 如果窗口大小发生变化，此处根据width()、height()从新绘图
    resetVariables(&painter);
    drawOuterCircle(&painter);    // 由中心辐射绘制外出背景色
    drawInnerCircle(&painter);    // 由中心辐射绘制内部背景色
    drawColorPies(&painter);      //在内部绘制出率、黄、红三扇形色
    drawGraph(&painter);          //用“半圆环”来挡住绘制好的的三扇形；使其仅露出边缘一点点;且以扇形与数据交互
    drawCoverLines(&painter);     //绘制六条粉色线
    drawCoverCircle(&painter);    //将本来扇形的图形变化 变为 圆环形变化（覆盖）
    drawMarkAndText(&painter);    //绘制数字和刻度
    drawTextRect(&painter);

    painter.end();
}

void DashBoardOne::resetVariables(QPainter *painter)
{
    m_outerRadius=width()>height() ? height()/2 : width()/2;//240
    m_innerRadius=0.8*m_outerRadius;//192
    m_center=rect().center();//(319,219)    中心点
    m_colorPieRadius=m_outerRadius*0.7;//168    扇形半径
    m_coverCircleRadius=0.7*m_colorPieRadius;//117.6
    m_longHand=(qreal)m_outerRadius/20;//12
    m_okHand=0.7*m_longHand;//8.399
    m_shortHand=0.5*m_longHand;//6
    m_space=0.1*m_longHand;//1.2
}

void DashBoardOne::mouseMoveEvent(QMouseEvent *e)
{
    QToolTip::showText(e->pos(), QString::number(e->pos().x())+QString(" ")+ QString::number(e->pos().y()),this);
}

void DashBoardOne::drawOuterCircle(QPainter* painter)
{
    painter->save();

    // 创建了一个QRadialGradient对象实例，参数分别为中心坐标，半径长度和焦点坐标,如果需要对称那么中心坐标和焦点坐标要一致
    QRadialGradient outerGradient(m_center,m_outerRadius,m_center);//(319,219) 240 (319,219)
    // 深灰色
    outerGradient.setColorAt(0.0,QColor(130,130,130));
    outerGradient.setColorAt(0.9,QColor(130,130,130));
    // 浅灰色
    outerGradient.setColorAt(0.95,QColor(200,200,200));
    outerGradient.setColorAt(1.0,QColor(130,130,130));

    painter->setPen(Qt::NoPen);
    painter->setBrush(outerGradient);
    painter->drawEllipse(m_center,m_outerRadius,m_outerRadius);

    painter->restore();
}

void DashBoardOne::drawInnerCircle(QPainter* painter)
{
    painter->save();

    QRadialGradient innerGradient(m_center,m_innerRadius,m_center);//(319,219) 192 (319,219)
    innerGradient.setColorAt(0.0,QColor(180,180,180));
    innerGradient.setColorAt(1.0,QColor(130,130,130));

    painter->setPen(Qt::NoPen);
    painter->setBrush(innerGradient);
    painter->drawEllipse(m_center,m_innerRadius,m_innerRadius);

    painter->restore();
}

void DashBoardOne::drawColorPies(QPainter* painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    // pieRectTopLeftPot(151.0,71.0) m_center(319,219) m_colorPieRadius:168
    QPointF pieRectTopLeftPot(m_center.x()-m_colorPieRadius,m_center.y()-m_colorPieRadius);
    // pieRectBottomRightPot(487.0, 407.0)
    QPointF pieRectBottomRightPot(m_center.x()+m_colorPieRadius,m_center.y()+m_colorPieRadius);

    // m_pieRect = 336.0x336.0+151.0+71.0
    m_pieRect=QRectF(pieRectTopLeftPot,pieRectBottomRightPot);
    //draw green pie
    painter->setBrush(Qt::green);
    // 起始72°，旋转108°
    painter->drawPie(m_pieRect,72*16,108*16);
    // draw yellow pie
    painter->setBrush(Qt::yellow);
    // 起始36°，旋转36°
    painter->drawPie(m_pieRect,36*16,36*16);
    // draw blue pie
    painter->setBrush(Qt::red);
    // 起始0°，旋转36°
    painter->drawPie(m_pieRect,0*16,36*16);
    painter->restore();
}

// m_currentValue值得变化引起扇形上值得变化
void DashBoardOne::drawGraph(QPainter* painter)
{
    qreal increment=(qreal)180/100;
    painter->save();
    painter->setPen(Qt::NoPen);

    // m_center(319,219) m_colorPieRadius:168:扇形半径
    // 是中心辐射造成了“半圆环（假的）；真实是绘制了扇形”
    QRadialGradient graphGradient(m_center,m_colorPieRadius,m_center);
    graphGradient.setColorAt(0.0,QColor(180,180,180));
    graphGradient.setColorAt(0.7,QColor(150,150,150));
    graphGradient.setColorAt(0.85,QColor(180,180,180));
    graphGradient.setColorAt(1.0,QColor(150,150,150));
    painter->setBrush(graphGradient);
    // 以扇形与数据交互
    painter->drawPie(m_pieRect,0,180*16-m_currentValue*increment*16);

    painter->restore();
}

void DashBoardOne::drawCoverLines(QPainter* painter)
{
    painter->save();

    qreal startAngle=90;
    qreal dAngle=(qreal)180/5;
    // 以m_center为中心
    /*
    为了读懂下面的代码就要搞清楚translate(QPointF)和retate
    可以参考Qt5.9C++开发指南
    translate是移动直QPointF处作为原点
    retate是旋转坐标系
    下面依次是从左向右开始画粉色线！
    */
    painter->translate(m_center);
    // 粉色
    painter->setPen(QColor(255,0,127));
    for(int i=0;i<=5;i++)
    {
        painter->save();
        //顺时针旋转90°
        painter->rotate(startAngle);
        // topPot(0.0,168.0)
        QPointF topPot(0,m_colorPieRadius);
        // bottomPot(0.0, 117.6)
        QPointF bottomPot(0,m_coverCircleRadius);
        painter->drawLine(topPot,bottomPot);
        painter->restore();
        startAngle+=dAngle;
    }
    painter->restore();
}


// 这个函数的意义是：将本来扇形的图形变化 变为 圆环形变化（覆盖）
void DashBoardOne::drawCoverCircle(QPainter* painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QRadialGradient coverGradient(m_center,m_coverCircleRadius,m_center);
    coverGradient.setColorAt(0.0,QColor(180,180,180));
    coverGradient.setColorAt(1.0,QColor(150,150,150));

    painter->setBrush(coverGradient);
    painter->drawEllipse(m_center,m_coverCircleRadius,m_coverCircleRadius);

    painter->restore();
}

void DashBoardOne::drawMarkAndText(QPainter* painter)
{
    painter->save();
    //translate——坐标变换；坐标系统平移一定的偏移量，坐标原点平移到新的点
    painter->translate(m_center);

    int value=0;
    QString strValue;
    qreal startAngle=90;
    qreal increment=(qreal)180/100;

    for(int i=0;i<=100;i++)
    {
        painter->save();
        //rotate:坐标系统顺时针旋转一个角度
        painter->rotate(startAngle);
        if(i%10==0)
        {
            // 深蓝色
            painter->setPen(QColor(16,49,98));
            QPointF bottomPot(0,m_colorPieRadius+m_space);
            QPointF topPot(0,m_colorPieRadius+m_space+m_longHand);
            painter->drawLine(bottomPot,topPot);

            strValue=tr("%1").arg(value);
            /*value : texWidth :texHeight
             * 0  : 12 : 24
             * 30 : 24 : 24
             * 40 : 24 : 24
             * 100: 36 : 24
             */
            qreal textWidth=fontMetrics().width(strValue);
            qreal textHeight=fontMetrics().height();
            // m_colorPieRadius = 116.61
            // m_space = 1.19
            // m_longHand = 11.9
            // txtPot(-6, 204.88)
            QPointF textPot(-textWidth/2,m_colorPieRadius+2*m_space+m_longHand+textHeight);
            painter->save();
            painter->translate(textPot);
            painter->rotate(180);
            painter->drawText(QPointF(-textWidth,textHeight/2),strValue);
            painter->restore();
            value+=10;

        }
        else if(i%5==0)
        {

            // 青色
            painter->setPen(QColor(0,255,17));
            QPointF bottomPot(0,m_colorPieRadius+m_space);
            QPointF topPot(0,m_colorPieRadius+m_space+m_okHand);
            painter->drawLine(bottomPot,topPot);
        }
        else
        {
            // 橙色
            painter->setPen(QColor(255,170,0));
            QPointF bottomPot(0,m_colorPieRadius+m_space);
            QPointF topPot(0,m_colorPieRadius+m_space+m_shortHand);
            painter->drawLine(bottomPot,topPot);
        }
        startAngle+=increment;
        painter->restore();
    }
    painter->restore();
}

void DashBoardOne::drawTextRect(QPainter* painter)
{
    painter->save();
    qreal rectWidth=(m_colorPieRadius-m_coverCircleRadius)/2;

    /*将绘制器的不透明度设置为不透明度。
     * 该值应在0.0到1.0的范围内，
     * 其中0.0是完全透明的，1.0是完全不透明的。
     */
    painter->setOpacity(0.7);
    QPointF topLeftPot(m_center.x()-rectWidth,m_center.y()-rectWidth);
    QPointF bottomRightPot(m_center.x()+rectWidth,m_center.y()+rectWidth);
    QRectF textRect(topLeftPot,bottomRightPot);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::cyan);
    painter->drawRoundRect(textRect,rectWidth*2,rectWidth*2);

    painter->setOpacity(1.0);
    painter->setPen(Qt::black);
    qreal fontSize=rectWidth*0.75;
    QFont font;
    font.setPointSize(fontSize);
    painter->setFont(font);
    painter->drawText(textRect,Qt::AlignVCenter|Qt::AlignHCenter,tr("%1").arg(m_value));
    painter->restore();
}

void DashBoardOne::setValue(qreal value)
{
    if(value>m_value)
    {
        m_bReverse=false;//表示绘制时正向绘制
        m_value=value;
    }
    else if(value<m_value)
    {
        m_bReverse=true;//reserse:反向
        m_value=value;
    }
    else
    {
        return ;
    }
    updateTimer->start();
}

void DashBoardOne::UpdateGraph()
{
    qDebug() << "1";
    if(m_bReverse)
    {
        m_currentValue-=0.5;

        if(m_currentValue<=m_value)
        {
            updateTimer->stop();
        }
    }
    else
    {
        m_currentValue+=0.5;

        if(m_currentValue>=m_value)
        {
            updateTimer->stop();
        }
    }
    update();
}
