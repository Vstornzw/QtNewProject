#ifndef TRACEVIEWER_H
#define TRACEVIEWER_H

#include <QWidget>
#include <TimeLine.h>

QT_BEGIN_NAMESPACE
namespace Ui { class TraceViewer; }
QT_END_NAMESPACE

class TraceViewer : public QWidget
{
    Q_OBJECT

public:
    TraceViewer(QWidget *parent = nullptr);
    ~TraceViewer();
    void Init();

private:
    // 隐藏右上侧颜色Lable
    void HideTextureInfo() const;

private:
    Ui::TraceViewer *ui;
    // QSize 类代表一个矩形区域的大小，实现在QtCore共享库中，它可以认为是有一个整型的宽度和高度组合而成的
    QSize mPixmapSize;
    QSharedPointer<TimeLine> mTimeLine;

};
#endif // TRACEVIEWER_H
