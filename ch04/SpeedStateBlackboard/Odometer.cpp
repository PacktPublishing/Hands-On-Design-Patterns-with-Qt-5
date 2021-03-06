#include "Odometer.h"
#include "Blackboard.h"

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
}

void Odometer::act(Topic a_topic)
{
    auto name = a_topic.name;
    auto val = a_topic.data.value<double>();
    if (name == "distance")
    {
        display(QString::number(val, 'f', 1));
    }
}
