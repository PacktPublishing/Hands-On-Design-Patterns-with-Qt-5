#include "Signaller.h"
#include <QDebug>

Signaller::Signaller(QObject *parent) : QObject(parent)
{
    // connect SimpleSignal (signal) to CatchSimpleSignal (slot)
    connect(this, &Signaller::SimpleSignal,         // sender
            this, &Signaller::CatchSimpleSignal);   // receiver
}

void Signaller::SendSimpleSignal()
{
    emit SimpleSignal();
}

void Signaller::CatchSimpleSignal()
{
    qDebug() << "Got SimpleSignal";
}
