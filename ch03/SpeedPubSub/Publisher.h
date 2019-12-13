#include "Broker.h"

class Publisher
{
public:
    Publisher() : m_broker(nullptr) {}
    virtual ~Publisher() = default;

    Broker *broker() const          { return m_broker; }
    void setBroker(Broker *broker)  { m_broker = broker; }

    void notify(Topic topic);

protected:
    Broker* m_broker;
};


