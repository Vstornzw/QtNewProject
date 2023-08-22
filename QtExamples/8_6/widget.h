#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "mygauge1.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QVBoxLayout *m_vhlayout;
    QPushButton *m_button;
    myGauge1 *m_myGauge1;

    Ui::Widget *ui;
};
#endif // WIDGET_H
