#ifndef QT5_9CDEVELOPERGUIDEWIDGET_H
#define QT5_9CDEVELOPERGUIDEWIDGET_H

#include <QWidget>
#include "Qt5_9CDeveloperGuide_global.h"

namespace Ui {
class Qt5_9CDeveloperGuideWidget;
}

class QT5_9CDEVELOPERGUIDE_EXPORT Qt5_9CDeveloperGuideWidget : public QWidget
{
    Q_OBJECT

public:
    explicit Qt5_9CDeveloperGuideWidget(QWidget *parent = nullptr);
    ~Qt5_9CDeveloperGuideWidget();

protected:
    void initTree();
protected slots:
    void onTreeViewClick(QModelIndex &index);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Qt5_9CDeveloperGuideWidget *ui;
};

#endif // QT5_9CDEVELOPERGUIDEWIDGET_H
