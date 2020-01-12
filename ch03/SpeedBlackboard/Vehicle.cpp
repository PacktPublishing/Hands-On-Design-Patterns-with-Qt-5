#include "Vehicle.h"

#include <QTimer>
#include <QDateTime>

Vehicle::Vehicle()
    : m_speed(0.0),
      m_accel(0.5),
      m_distance(0.0),
      m_heading(0.0),
      m_fuelUsage(0.0)
{
    // setup a timer to adjustSpeed and the postUpdate()
    m_notificationTimer = new QTimer;
    m_notificationTimer->setInterval(1000);
    m_notificationTimer->setSingleShot(false);
    QTimer::connect(m_notificationTimer, &QTimer::timeout,
                    [this] {
                        adjustSpeed();
                        postUpdate(Topic{"speed",    m_speed});
                        postUpdate(Topic{"accel",    m_accel});
                        postUpdate(Topic{"distance", m_distance});
                        postUpdate(Topic{"heading",  m_heading});
                        postUpdate(Topic{"fuelUsage", m_fuelUsage});
                    });
    m_notificationTimer->start();

    qsrand(QDateTime::currentSecsSinceEpoch());
}

void Vehicle::setBlackboard(Blackboard *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);
}

void Vehicle::act(Topic a_topic)
{
    KnowledgeSource::act(a_topic);
}

void Vehicle::postUpdate(Topic a_topic)
{
    KnowledgeSource::postUpdate(a_topic);
}


void Vehicle::adjustSpeed()
{
    m_distance += m_speed;  // dist = sum(speed/time)
    m_fuelUsage += 0.23;

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
