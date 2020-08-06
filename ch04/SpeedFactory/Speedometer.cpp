#include "Speedometer.h"
#include "Blackboard.h"

#include <QTimer>

Speedometer::Speedometer(QWidget *parent)
    : QLCDNumber(parent),
      KnowledgeSource()
{
    setDigitCount(5);
    setSmallDecimalPoint(true);
    setDecMode();
}

Speedometer::~Speedometer()
{
}

void Speedometer::setBlackboard(Blackboard *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);  // (Decorator Pattern)
    QTimer::singleShot(50, this, &Speedometer::doTimedUpdate);
}

void Speedometer::doTimedUpdate()
{
    auto val = m_blackboard->inspect("speed").data.toDouble();
    display(QString::number(val, 'f', 1));

    QTimer::singleShot(20, this, &Speedometer::doTimedUpdate);
}
