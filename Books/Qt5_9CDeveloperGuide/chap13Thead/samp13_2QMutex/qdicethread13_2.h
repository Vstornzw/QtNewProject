#ifndef QDICETHREAD13_2_H
#define QDICETHREAD13_2_H

//#include    <QObject>
#include    <QThread>
#include    <QMutex>

#include "Qt5_9CDeveloperGuide_global.h"

class QT5_9CDEVELOPERGUIDE_EXPORT QDiceThread13_2 : public QThread
{
    Q_OBJECT

private:
    QMutex  mutex;
    int     m_seq=0;
    int     m_diceValue;
    bool    m_paused=true;
    bool    m_stop=false;
protected:
    void    run() Q_DECL_OVERRIDE;
public:
    QDiceThread13_2();

    void    diceBegin();
    void    diceEnd();//
    void    stopThread();

    bool    readValue(int *seq, int *diceValue);
};

#endif // QDICETHREAD13_2_H
