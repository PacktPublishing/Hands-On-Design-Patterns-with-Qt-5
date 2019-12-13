#include "Vehicle.h"
#include "Observer.h"

#include <QTimer>

Vehicle::Vehicle(QObject *parent)
    : QObject(parent),
      m_speed(0.0),
      m_accel(0.5)
{
    m_notificationTimer = new QTimer;
    m_notificationTimer->setInterval(1000);
    m_notificationTimer->setSingleShot(false);
    connect(m_notificationTimer, &QTimer::timeout,
            [this] {
                adjustSpeed();
                notify();
            });
    m_notificationTimer->start();
}

void Vehicle::registerObserver(Observer *observer)
{
    connect(this, &Vehicle::speedNotification, observer, &Observer::update,
            Qt::UniqueConnection);
}

void Vehicle::unregiserObserver(Observer *observer)
{
    disconnect(this, &Vehicle::speedNotification, observer, &Observer::update);
}

void Vehicle::notify()
{
    emit speedNotification(QVariant(m_speed));
}

void Vehicle::adjustSpeed()
{
    m_accel += ((qrand() % 41) - 20) / 20.0;
    m_speed += m_accel;
    if (m_speed < 0.0)
    {
        m_speed = 0.0;
    }
    else if (m_speed > 200.0)
    {
        m_speed = 200.0;
    }
}
