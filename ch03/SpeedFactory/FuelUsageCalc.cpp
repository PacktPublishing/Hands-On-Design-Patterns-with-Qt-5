#include "FuelUsageCalc.h"
#include <QTimer>
#include "Blackboard.h"

FuelUsageCalc::FuelUsageCalc()
    : m_distance(0.0),
      m_fuelUsage(0.0),
      m_startTime()
{
    // nothing to do
}

void FuelUsageCalc::setBlackboard(Blackboard *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);
    m_startTime = QDateTime::currentDateTime();
    QTimer::singleShot(1000, [this] () { doTimedUpdate(); });
}

void FuelUsageCalc::doTimedUpdate()
{
    // fetch the things we need
    auto tdistance  = m_blackboard->inspect("distance");
    auto tfuelUsage = m_blackboard->inspect("fuelUsage");
    auto ttime      = m_blackboard->inspect("time");

    m_distance  = tdistance.data.toDouble();
    m_fuelUsage = tfuelUsage.data.toDouble();

    postUpdate({"fuelPerDist", m_fuelUsage / m_distance});
    postUpdate({"distPerFuel", m_distance / m_fuelUsage});

    auto time   = ttime.data.toDateTime();
    auto secs = time.toSecsSinceEpoch() - m_startTime.toSecsSinceEpoch();
    if (secs != 0) {
        postUpdate({"fuelPerSec", m_fuelUsage / secs});
    }

    // schedule update
    QTimer::singleShot(1000, [this] () { doTimedUpdate(); });
}
