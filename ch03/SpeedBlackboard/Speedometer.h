#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include "KnowledgeSource.h"
#include <QLCDNumber>

class Speedometer : public QLCDNumber, public KnowledgeSource
{
public:
    Speedometer(QWidget* parent = nullptr);
    ~Speedometer();

    void setBlackboard(Blackboard *a_blackboard) override;
    void act(Topic a_topic) override;

protected:
    // void postUpdate(Topic a_topic) final;
};

#endif // SPEEDOMETER_H
