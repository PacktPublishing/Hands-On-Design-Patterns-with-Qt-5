#include "Signaller.h"

Signaller::Signaller(QObject *parent) : QObject(parent)
{
    // this space for rent
}

void Signaller::SendSimpleSignal()
{
    emit SimpleSignal();
}

void Signaller::CatchSimpleSignal()
{

}
