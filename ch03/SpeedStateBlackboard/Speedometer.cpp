#include "Speedometer.h"
#include "Blackboard.h"

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
}

void Speedometer::act(Topic a_topic)
{
    auto name = a_topic.name;
    auto val = a_topic.data.value<double>();
    if (name == "speed")
    {
        display(QString::number(val, 'f', 1));
    }
}
