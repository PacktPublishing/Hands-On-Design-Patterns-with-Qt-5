class Broker;
class Topic;

class Subscriber
{
public:
    Subscriber() = default;
    virtual ~Subscriber() = default;

    virtual void update(Topic a_topic) = 0;

    Broker *broker() const          { return m_broker; }
    void setBroker(Broker *broker)  { m_broker = broker; }

protected:
    Broker  *m_broker;
};
