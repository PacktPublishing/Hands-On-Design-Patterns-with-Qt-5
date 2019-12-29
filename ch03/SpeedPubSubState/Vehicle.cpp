#include "Vehicle.h"

#include <QTimer>

Vehicle::Vehicle(QObject *parent)
    : QObject(parent),
      m_speed(0.0),
      m_accel(0.5),
      m_distance(0.0),
      m_heading(0.0)
{
    m_notificationTimer = new QTimer;
    m_notificationTimer->setInterval(1000);
    m_notificationTimer->setSingleShot(false);
    connect(m_notificationTimer, &QTimer::timeout,
            [this] {
                adjustSpeed();
                notify(Topic{"speed",    m_speed});
                notify(Topic{"accel",    m_accel});
                notify(Topic{"distance", m_distance});
                notify(Topic{"heading",  m_heading});
            });
    m_notificationTimer->start();
}


void Vehicle::adjustSpeed()
{
    m_distance += m_speed;  // dist = sum(speed/time)

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

    m_heading += ((qrand() % 8) - 4);
    if (m_heading > 360.0)
    {
        m_heading -= 360.0;
    }
    else if (m_heading < 0.0)
    {
        m_heading += 360.0;
    }
}
