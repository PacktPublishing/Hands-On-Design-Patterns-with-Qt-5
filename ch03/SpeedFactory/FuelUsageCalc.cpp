#include "FuelUsageCalc.h"

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
}

void FuelUsageCalc::act(Topic a_topic)
{
    auto name = a_topic.name;
    if (name == "distance") {
        m_distance = a_topic.data.toDouble();
    }
    else if (name == "fuelUsage") {
        m_fuelUsage = a_topic.data.toDouble();
        postUpdate({"fuelPerDist", m_fuelUsage / m_distance});
        postUpdate({"distPerFuel", m_distance / m_fuelUsage});
    }
    else if (name == "time")
    {
        auto time = a_topic.data.toDateTime();
        auto secs = time.toSecsSinceEpoch() - m_startTime.toSecsSinceEpoch();
        if (secs != 0) {
            postUpdate({"fuelPerSec", m_fuelUsage / secs});
        }
    }

}
