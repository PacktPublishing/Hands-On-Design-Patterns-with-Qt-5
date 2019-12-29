#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "Blackboard.h"
#include "KnowledgeSource.h"
#include "Topic.h"

class QTimer;

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller(QObject *parent = nullptr);

    void setBlackboard(Blackboard *a_blackboard);

    void setSpeedo(KnowledgeSource *speedo);
    void setOdo(KnowledgeSource *odo);
    void setFuelUsageCalc(KnowledgeSource *fuelUsageCalc);
    void setFuelUsageDisp(KnowledgeSource *fuelUsageDisp);

public slots:
    void Observe();
    void Orient();
    void Decide();
    void Act();

private:
    Blackboard *m_blackboard;
    QTimer     *m_timer;

    Topic       mt_speed;
    Topic       mt_distance;
    Topic       mt_fuelUsage;
    Topic       mt_heading;
    Topic       mt_fuelPerDist;

    KnowledgeSource *m_speedo;
    KnowledgeSource *m_odo;
    KnowledgeSource *m_fuelUsageCalc;
    KnowledgeSource *m_fuelUsageDisp;
};

#endif // CONTROLLER_H
