#ifndef VEHICLE_H
#define VEHICLE_H

#include <QObject>
#include "KnowledgeSource.h"

class QTimer;
class Observer;

/// @note QObject must be first in inheritance tree!
class Vehicle : public QObject, public KnowledgeSource
{
    Q_OBJECT

public:
    explicit Vehicle(QObject *parent = nullptr);

    void setBlackboard(Blackboard *a_blackboard) final;
    void act(Topic a_topic) final;

protected:
    void postUpdate(Topic a_topic) final;

signals:
    // Nothing for now

public slots:
    // Nothing for now

private:
    double              m_speed;
    double              m_accel;
    double              m_distance;
    double              m_heading;
    double              m_fuelUsage;

    QTimer *            m_notificationTimer;

    void adjustSpeed();
};

#endif // VEHICLE_H
