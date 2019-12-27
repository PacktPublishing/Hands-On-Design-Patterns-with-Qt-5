#ifndef MILEAGECALCULATOR_H
#define MILEAGECALCULATOR_H

#include "KnowledgeSource.h"

#include <QDateTime>

class FuelUsageCalc : public KnowledgeSource
{
public:
    FuelUsageCalc();

    void setBlackboard(Blackboard *a_blackboard) final;
    void act(Topic a_topic) final;

protected:
    // void postUpdate(Topic a_topic) final;

private:
    double  m_distance;
    double  m_fuelUsage;
    QDateTime   m_time;
};

#endif // MILEAGECALCULATOR_H
