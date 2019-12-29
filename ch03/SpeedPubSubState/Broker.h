#ifndef BROKER_H_INCLUDED
#define BROKER_H_INCLUDED

#include "Subscription.h"
#include "Subscriber.h"
#include "Topic.h"

#include <QList>

class Broker
{
public:
    Broker();
    ~Broker() = default;

    void registerSub(Subscriber *a_subscriber, Topic a_topic);
    void unregisterSub(Subscriber *a_subscriber, Topic a_topic);

    void notify(Topic a_topic);

private:
    QList<Subscription>   m_subscriptions;
};

#endif
