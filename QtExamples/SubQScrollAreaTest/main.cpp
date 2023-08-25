#include "TraceView.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TraceView w;
    w.show();
    return a.exec();
}
