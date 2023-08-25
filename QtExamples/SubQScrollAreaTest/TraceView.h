#ifndef TRACEVIEW_H
#define TRACEVIEW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TraceView; }
QT_END_NAMESPACE

class TraceView : public QWidget
{
    Q_OBJECT

public:
    TraceView(QWidget *parent = nullptr);
    ~TraceView();

private:
    Ui::TraceView *ui;
};
#endif // TRACEVIEW_H
