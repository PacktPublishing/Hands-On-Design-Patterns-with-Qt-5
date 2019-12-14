#include "Subscriber.h"

Broker *Subscriber::broker() const
{
    return m_broker;
}

void Subscriber::setBroker(Broker *broker)
{
    m_broker = broker;
}
