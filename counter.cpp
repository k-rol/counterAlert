#include "counter.h"
#include <QTimer>
#include <QtNetwork/QNetworkAccessManager>
#include <QDebug>

counter::counter(QObject* parent) : QObject(parent)
{
    passwordCounter = 1;
}

void counter::startAll()
{
    QTimer* timer = new QTimer();
    timer->setObjectName("GetPassword");
    timer->setSingleShot(true);
    timer->start(1000);

    bool ok = connect(timer, SIGNAL(timeout()),this,SLOT(counting()));

    Q_ASSERT(ok);
    Q_UNUSED(ok);
}

void counter::counting()
{
    QTimer* timer = qobject_cast<QTimer*>(sender());


        qDebug() << "request aborting...";
        qDebug() << timer->objectName();


        qDebug() << "Aborted";

        if (timer->objectName() == "GetPassword")
        {
            if (passwordCounter == 3)
            {
                //stop timer and bring retry dialog
                //emit passwordfailedDialog();
                qDebug() << "Bring up dialog";
                //emit timerTimesOut("GetPassword");
            }

            else {
                passwordCounter++;
                //retry get password timer
                //GetPassword();
                qDebug() << "GetPassword()";
            }
        }

        else if (timer->objectName() == "StatRequest") {
            //emit timerTimesOut("neverconected");
            //powerbutton at off
        }

        qDebug() << passwordCounter;

}
