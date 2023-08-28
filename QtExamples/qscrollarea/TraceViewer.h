#ifndef TRACEVIEWER_H
#define TRACEVIEWER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TraceViewer; }
QT_END_NAMESPACE

class TraceViewer : public QWidget
{
    Q_OBJECT

public:
    TraceViewer(QWidget *parent = nullptr);
    ~TraceViewer();

private:
    Ui::TraceViewer *ui;
};
#endif // TRACEVIEWER_H
