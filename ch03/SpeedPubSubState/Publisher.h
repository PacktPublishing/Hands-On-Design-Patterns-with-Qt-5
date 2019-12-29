#ifndef PUBLISHER_H_INCLUDED
#define PUBLISHER_H_INCLUDED

#include "Broker.h"

class Publisher
{
public:
    Publisher();
    virtual ~Publisher() = default;

    virtual Broker *broker() const;
    virtual void setBroker(Broker *broker);

    virtual void notify(Topic topic);

protected:
    Broker* m_broker;
};

#endif
