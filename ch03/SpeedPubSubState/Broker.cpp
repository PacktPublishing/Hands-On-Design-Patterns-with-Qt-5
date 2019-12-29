#include "Broker.h"

Broker::Broker()
    : m_subscriptions()
{
    // nothing to do here
}

void Broker::registerSub(Subscriber *a_subscriber, Topic a_topic)
{
    Subscription sub{a_topic, a_subscriber};
    bool found = false;
    for (const auto &i : m_subscriptions)
    {
        found = (i == sub);
    }
    if (!found)
    {
        m_subscriptions.append(sub);
    }
}

void Broker::unregisterSub(Subscriber *a_subscriber, Topic a_topic)
{
    Subscription sub{a_topic, a_subscriber};
    m_subscriptions.removeAll(sub);
}

void Broker::notify(Topic a_topic)
{
    auto name = a_topic.name;
    for (const auto &i : m_subscriptions)
    {
        if (name == i.topic.name)
        {
            i.subscriber->update(a_topic);
        }
    }
}
