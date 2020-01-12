#ifndef VEHICLE_H
#define VEHICLE_H

#include <QList>

class QTimer;
class Observer;

class Vehicle
{
public:
    explicit Vehicle();

    void registerObserver(Observer *observer);
    void unregiserObserver(Observer *observer);

    void notify();

private:
    QList<Observer *>   m_observers;
    double              m_speed;
    double              m_accel;

    QTimer *            m_notificationTimer;

    void adjustSpeed();
};

#endif // VEHICLE_H
