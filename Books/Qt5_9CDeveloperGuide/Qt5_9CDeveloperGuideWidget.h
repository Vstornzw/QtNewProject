#ifndef QT5_9CDEVELOPERGUIDEWIDGET_H
#define QT5_9CDEVELOPERGUIDEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
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
private slots:
    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::Qt5_9CDeveloperGuideWidget *ui;
};

#endif // QT5_9CDEVELOPERGUIDEWIDGET_H
