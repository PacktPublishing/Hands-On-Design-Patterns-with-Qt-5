#include "Publisher.h"

Publisher::Publisher()
    : m_broker(nullptr)
{
    // empty method
}

Broker *Publisher::broker() const
{
    return m_broker;
}

void Publisher::setBroker(Broker *broker)
{
    m_broker = broker;
}

void Publisher::notify(Topic a_topic)
{
    m_broker->notify(a_topic);
}
