#ifndef TIMELINE_H
#define TIMELINE_H

#include <QScrollArea>
#include <QWidget>
#include <QMap>
#include <QScrollBar>
#include <QPainter>
#include <QWheelEvent>

enum LineType {
    EID = 0,
    DRAW,
    TEXTURE,
    RENDERPASS,
    VIEWPORT,
    PROGRAM
};

class TimeLineScrollBar : public QScrollBar {
    Q_OBJECT
public:
    explicit TimeLineScrollBar(QWidget *parent) : QScrollBar(parent){}
    explicit TimeLineScrollBar(Qt::Orientation ot,QWidget *parent = nullptr) : QScrollBar(ot, parent){}
    virtual ~TimeLineScrollBar();

protected:
    void enterEvent(QEvent *e);

signals:
    void MouseEnterSignal();

private:
    QVector<QPair<QVector<int>,QColor>> mMarkDatas;
    int mMaxEid = 0;
};

class TimeLine : public QScrollArea {
    Q_OBJECT
public:
    TimeLine(QWidget *parent=nullptr);
    void SetLineHeight(const int &LineHeight);
    void Init();
    void SetCurEid(QMouseEvent *e);

public slots:
    void OnFindPrevClicked();
    void OnFindNextClicked();
    void OnResetZoomClicked();

protected:
    void resizeEvent(QResizeEvent *e) override;
    void paintEvent(QPaintEvent *) override;
    void wheelEvent(QWheelEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;

private:
    void Layout();
    //绘制背景色
    void DrawBackGroud(QPainter &p);
    //绘制Eid对应的黑框（左侧缺失的矩形）
    void DrawEidLineBounding(QPainter &p);
    //绘制Eid Label
    void DrawEidLabel(QPainter &p);
    //
    qreal GetPosByValue(qreal i);
    //绘制鼠标光标（鼠标移动时mShowCursor=true,实现EID的Label随着鼠标的移动而变色）
    void DrawCursor(QPainter &p);
    //把小数据转化成整数值
    int GetIntValue(qreal value);
    //
    qreal GetValueByPos(qreal posx);
    //获取当前转
    void UpdateMouseHoverBrickInfo(QString &toopTip);

    //绘制数据
    void DrawDrawAndTexture(QPainter &p);

    //根据EID返回对应的矩形区域
    QRect EidMapToRect(const qreal &eid, LineType lineType);
    //设置画笔颜色
    void SetPenColor(QPainter &p, QColor color);

    //
    void DrawRenderpass(QPainter &p);
    //
    void DrawCurPressedEid(QPainter &p);
    //
    void JumpToEid(int eid);

private:
    uint32_t mMaxEid = 0;
    //eid显示步长（隔了多少显示一个label）
    int mEidAxisLabelStep = 0;
    //缩放比
    qreal mZoom = 1;
    //面板当前值
    qreal mPan = 0;
    //当前viewport的大小
    QRectF mArea;
    // 当前鼠标位置
    QPointF mPos;
    //字长
    qreal mMaxEidWidth;
    //每个像素与eid的数值对比关系
    qreal mPerPixel;
    //是否显示游标
    bool mShowCursor = true;
    QFont mFont;
    QPointF mPressPos;
    bool mPressed = false;

    qreal mCurPressedEid = -1;
    qreal mCurMouseEid = -1;
    //

    int mLineHeight = 0;
    QSharedPointer<TimeLineScrollBar> mScrollBar;
    QVector<uint32_t> mActions;
    //
    QMap<uint32_t, double> mTimes;


    QVector<int> mClearEids;
    QVector<int> mReadEids;
    QVector<int> mWriteEids;
    QVector<int> mAllMarkEids;
    int mCurrentMarkIndex;
    bool mIsFreeModel = true;//自由模式和定位模式，默认是自由模式
    QColor mClearColor;
    QColor mReadColor;
    QColor mWriteColor;
    QColor mHighLightColor;
    QColor mBrickColor;
    QColor mTextHightLightColor;
    QColor mCursorBlackgroundColor;
    QColor mBrickBorderColor;
    QColor mTextColor;
    QColor mEidLaelBackgroudColor;

    int mSelectedResourceRect;

    QRect mPressedEidRect;
};

#endif // TIMELINE_H
