#include "Subscription.h"

Subscription::Subscription()
 : topic(),
   subscriber(nullptr)
{
    // empty method
}

Subscription::Subscription(Topic a_topic, Subscriber * a_subscriber)
    : topic(a_topic),
      subscriber(a_subscriber)
{
    // empty method
}

bool Subscription::operator==(const Subscription &right) const
{
    bool eq = (topic == right.topic) &&
              (subscriber == right.subscriber);
    return eq;
}

#include "Subscription.h"
