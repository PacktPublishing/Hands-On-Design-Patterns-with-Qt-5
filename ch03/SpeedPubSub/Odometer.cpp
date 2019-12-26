#include "Odometer.h"
#include "Broker.h"

Odometer::Odometer(QWidget *parent)
    : Subscriber(),
      QLCDNumber(parent)
{
    setDigitCount(7);
    setSmallDecimalPoint(true);
    setDecMode();
}

Odometer::~Odometer()
{
    m_broker->unregisterSub(this, Topic{"speed", QVariant()});
}

void Odometer::setBroker(Broker *broker)
{
    Subscriber::setBroker(broker);  // (Decorator Pattern)
    m_broker->registerSub(this, Topic{"distance", QVariant()});
}

void Odometer::update(Topic a_topic)
{
    auto name = a_topic.name;
    auto val = a_topic.data.value<double>();
    if (name == "distance")
    {
        display(QString::number(val, 'f', 1));
    }
}
