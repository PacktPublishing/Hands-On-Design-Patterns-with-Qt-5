#ifndef ODOMETER_H
#define ODOMETER_H

#include "KnowledgeSource.h"
#include <QLCDNumber>

class Odometer : public KnowledgeSource, public QLCDNumber
{
public:
    Odometer(QWidget* parent = nullptr);
    ~Odometer();

    void setBlackboard(Blackboard *a_blackboard) final;
    void act(Topic a_topic) final;

protected:
    // void postUpdate(Topic a_topic) final;
};

#endif // ODOMETER_H
