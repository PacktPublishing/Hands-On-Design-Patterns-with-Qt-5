#ifndef ODOMETER_H
#define ODOMETER_H

#include "Subscriber.h"
#include <QLCDNumber>

class Odometer : public Subscriber, public QLCDNumber
{
public:
    Odometer(QWidget* parent = nullptr);
    ~Odometer();

    void setBroker(Broker *broker) final;
    void update(Topic a_topic) final;
};

#endif // ODOMETER_H
