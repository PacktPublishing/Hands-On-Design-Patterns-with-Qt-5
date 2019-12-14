#include "Speedometer.h"
#include "Broker.h"

Speedometer::Speedometer(QWidget *parent)
    : Subscriber(),
      QLCDNumber(parent)
{
    setDigitCount(5);
    setSmallDecimalPoint(true);
    setDecMode();
}

Speedometer::~Speedometer()
{
    m_broker->unregisterSub(this, Topic{"speed", QVariant()});
}

void Speedometer::setBroker(Broker *broker)
{
    Subscriber::setBroker(broker);  // (Use Method Pattern)
    m_broker->registerSub(this, Topic{"speed", QVariant()});
}

void Speedometer::update(Topic a_topic)
{
    auto name = a_topic.name;
    auto val = a_topic.data.value<double>();
    if (name == "speed")
    {
        display(val);
    }
}
