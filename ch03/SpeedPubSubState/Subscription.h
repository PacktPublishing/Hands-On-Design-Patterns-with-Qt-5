#ifndef SUBSCRIPTION_H_INCLUDED
#define SUBSCRIPTION_H_INCLUDED

#include "Topic.h"
#include "Subscriber.h"

class Subscription
{
public:
    Subscription();
    Subscription(Topic a_topic, Subscriber *a_subscriber);
    virtual ~Subscription() = default;

    bool operator==(const Subscription & right) const;

    Topic       topic;
    Subscriber  *subscriber;
};

#endif
