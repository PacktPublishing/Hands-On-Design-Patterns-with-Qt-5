#include "Odometer.h"
#include "Blackboard.h"
#include <QTimer>

Odometer::Odometer(QWidget *parent)
    : QLCDNumber(parent),
    KnowledgeSource()
{
    setDigitCount(7);
    setSmallDecimalPoint(true);
    setDecMode();
}

Odometer::~Odometer()
{
}

void Odometer::setBlackboard(Blackboard *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);
    QTimer::singleShot(250, this, &Odometer::doTimedUpdate);
}

void Odometer::doTimedUpdate()
{
    auto val = m_blackboard->inspect("distance").data.toDouble();
    display(QString::number(val, 'f', 1));

    QTimer::singleShot(250, this, &Odometer::doTimedUpdate);
}
