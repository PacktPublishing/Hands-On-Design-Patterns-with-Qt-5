#include "Signaler.h"
#include <QDebug>
#include <QTimer>

Signaler::Signaler(QObject *parent) : QObject(parent)
{
    // ** Connect Examples **
    connect(this, &Signaler::SimpleSignal,          // sender
            this, &Signaler::CatchSimpleSignal);    // receiver

    connect(this, &Signaler::IntSignal,             // sender
            this, &Signaler::CatchIntSignal);       // receiver

    connect(this, &Signaler::PersonSignal,          // sender
            this, &Signaler::CatchPerson);          // reciever

    connect(this, &Signaler::PersonSignal,          // sender
            [](Person p) {                          // lambda signal handler
                qDebug() << "I caught" << p.name();
            });
}

void Signaler::SendSimpleSignal()
{
    emit SimpleSignal();
}

void Signaler::SendIntSignal()
{
    static int i = 0;
    emit IntSignal(++i);
}

void Signaler::SendPerson()
{
    Person p("Martin", QDate(1996, 4, 20), 180);
    emit PersonSignal(p);
}

void Signaler::CatchSimpleSignal()
{
    qDebug() << "Got SimpleSignal";
}

void Signaler::CatchIntSignal(int v)
{
    qDebug() << "Got IntSignal with value" << v;
}

void Signaler::CatchPerson(Person p)
{
    qDebug() << "Got Person:" << p.name() << p.birthday() << p.heightCm();
}

void Signaler::DoSendSignals()
{
    // send the signals
    SendSimpleSignal();
    SendIntSignal();
    SendPerson();

    // Use a single shot timer to re-invoke this method after a while
    QTimer::singleShot(5000, this, &Signaler::DoSendSignals);
}
