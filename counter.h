#ifndef COUNTER_H
#define COUNTER_H
#include <QObject>

class counter : public QObject
{
    Q_OBJECT
public:
    counter(QObject* parent = 0);
    void startAll();

public Q_SLOTS:
    void counting();

private:
    int passwordCounter;
};

#endif // COUNTER_H
