#ifndef MILEAGEDISPLAY_H
#define MILEAGEDISPLAY_H

#include "KnowledgeSource.h"

class FuelUsageDisp : public KnowledgeSource
{
public:
    FuelUsageDisp();

    void setBlackboard(Blackboard *a_blackboard) final;
    void act(Topic a_topic) final;

protected:
    // void postUpdate(Topic a_topic) final;
};

#endif // MILEAGEDISPLAY_H