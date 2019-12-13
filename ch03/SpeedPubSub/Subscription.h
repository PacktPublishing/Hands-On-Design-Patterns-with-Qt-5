#include "Topic.h"
#include "Subscriber.h"

class Subscription
{
public:
    Subscription() : topic(), subscriber(nullptr)   {}
    virtual ~Subscription() = default;

    Topic       topic;
    Subscriber  *subscriber;
};
