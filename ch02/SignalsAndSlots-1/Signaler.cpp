#include "Signaler.h"
#include <QDebug>
#include <QTimer>

Signaler::Signaler(QObject *parent) : QObject(parent)
{

    // ** Conncet Examples **

    connect(this, &Signaler::SimpleSignal,          // sender
            this, &Signaler::CatchSimpleSignal);    // receiver

    connect(this, &Signaler::IntSignal,             // sender
            this, &Signaler::CatchIntSignal);       // receiver

    // ** This will fail to *compile* because the signature (parameters)
    //    of the signal do not match the parameters of the slot.
#ifdef MISMATCHED_PARAMS
    connect(this, &Signaler::IntSignal,             // sender
            this, &Signaler::CatchSimpleSignal);    // receiver
#endif

    // ** This old-style connect will compile, but fail to make the connection
    //    at run time because the check is done at runtime.
    connect(this, SIGNAL(IntSignal()),
            this, SLOT(CatchSimpleSignal()));
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

void Signaler::CatchSimpleSignal()
{
    qDebug() << "Got SimpleSignal";
}

void Signaler::CatchIntSignal(int v)
{
    qDebug() << "Got IntSignal with value" << v;
}

void Signaler::DoSendSignals()
{
    // send the signals
    SendSimpleSignal();
    SendIntSignal();

    // Use a single shot timer to re-invoke this method after a while
    QTimer::singleShot(5000, this, &Signaler::DoSendSignals);
}
