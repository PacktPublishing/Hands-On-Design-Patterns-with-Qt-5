#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include "Subscriber.h"
#include <QLCDNumber>

class Speedometer : public Subscriber, public QLCDNumber
{
public:
    Speedometer(QWidget* parent = nullptr);
    ~Speedometer();

    void setBroker(Broker *broker) final;
    void update(Topic a_topic) final;
};

#endif // SPEEDOMETER_H
