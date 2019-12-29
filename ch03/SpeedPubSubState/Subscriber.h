#ifndef SUBSCRIBER_H_INCLUDED
#define SUBSCRIBER_H_INCLUDED

#include "Topic.h"

class Broker;

class Subscriber
{
public:
    Subscriber() = default;
    virtual ~Subscriber() = default;

    virtual void update(Topic a_topic) = 0;

    Broker *broker() const;
    virtual void setBroker(Broker *broker);

protected:
    Broker  *m_broker;
};

#endif
