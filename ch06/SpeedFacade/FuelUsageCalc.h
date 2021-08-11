#ifndef MILEAGECALCULATOR_H
#define MILEAGECALCULATOR_H

#include "KnowledgeSource.h"

#include <QDateTime>
#include <QObject>

class FuelUsageCalc : public KnowledgeSource
{
    Q_OBJECT

public:
    FuelUsageCalc();

    void setBlackboard(BlackboardFacade *a_blackboard) final;
    // void act(Topic a_topic) final;

protected:
    // void postUpdate(Topic a_topic) final;

private:
    double  m_distance;
    double  m_fuelUsage;
    QDateTime   m_startTime;

    void doTimedUpdate();
};

#endif // MILEAGECALCULATOR_H
