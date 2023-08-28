#include "TraceViewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TraceViewer w;
    w.show();
    return a.exec();
}
