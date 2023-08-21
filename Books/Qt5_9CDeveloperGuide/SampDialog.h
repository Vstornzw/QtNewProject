#ifndef SAMPDIALOG_H
#define SAMPDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QWidget>

class SampDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SampDialog(QWidget *parent = nullptr,QWidget *widget = nullptr);
    ~SampDialog();

private:
    QHBoxLayout *m_HboxLayout;
    QWidget *m_widget;
};

#endif // SAMPDIALOG_H
