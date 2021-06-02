#include "Vehicle.h"

#include <QTimer>
#include <QDateTime>
#include <QRandomGenerator64>
#include "BlackboardFacade.h"

Vehicle::Vehicle(QObject *parent)
    : QObject(parent),
      m_speed(0.0),
      m_accel(0.5),
      m_distance(0.0),
      m_heading(0.0),
      m_fuelUsage(0.0)
{
    m_notificationTimer = new QTimer;
    m_notificationTimer->setInterval(10);
    m_notificationTimer->setSingleShot(false);
    connect(m_notificationTimer, &QTimer::timeout,
            [this] {
                adjustSpeed();
                postUpdate(Topic{"speed",    m_speed});
                postUpdate(Topic{"accel",    m_accel});
                postUpdate(Topic{"distance", m_distance});
                postUpdate(Topic{"heading",  m_heading});
                postUpdate(Topic{"fuelUsage", m_fuelUsage});
            });
    m_notificationTimer->start();
}

void Vehicle::setBlackboard(BlackboardFacade *a_blackboard)
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
    m_distance += m_speed/1000;  // dist = sum(speed/time)

    auto throttleTopic = m_blackboard->inspect("throttle");
    auto throttle = (throttleTopic != nullptr) ? throttleTopic->data().toDouble() : 0.0;
    m_fuelUsage += 0.01 + ((throttle > 0) ? throttle : 0.0);

    m_accel = throttle;
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
