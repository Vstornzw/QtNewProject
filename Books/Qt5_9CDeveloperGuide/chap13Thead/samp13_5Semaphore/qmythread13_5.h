#ifndef QMYTHREAD_H
#define QMYTHREAD_H

#include "Qt5_9CDeveloperGuide_global.h"
#include    <QThread>

class QT5_9CDEVELOPERGUIDE_EXPORT QThreadDAQ : public QThread
{
    Q_OBJECT

private:
    bool    m_stop; //停止线程
protected:
    void    run() Q_DECL_OVERRIDE;
public:
    QThreadDAQ();
    void    stopThread();
};

class QThreadShow : public QThread
{
    Q_OBJECT
private:
    bool    m_stop; //停止线程
protected:
    void    run() Q_DECL_OVERRIDE;
public:
    QThreadShow();
    void    stopThread();
signals:
    void    newValue(int *data,int count, int seq);
};
#endif // QMYTHREAD_H
