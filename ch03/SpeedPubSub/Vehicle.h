#ifndef VEHICLE_H
#define VEHICLE_H

#include "Publisher.h"

class QTimer;
class Observer;

class Vehicle : public Publisher
{
public:
    explicit Vehicle();

private:
    double              m_speed;
    double              m_accel;
    double              m_distance;
    double              m_heading;

    QTimer *            m_notificationTimer;

    void adjustSpeed();
};

#endif // VEHICLE_H
