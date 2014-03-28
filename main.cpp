#include <QCoreApplication>
#include "counter.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    counter mycounter;

    mycounter.startAll();

    return a.exec();
}
