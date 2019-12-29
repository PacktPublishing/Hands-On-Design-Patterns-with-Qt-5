#include "FuelUsageCalc.h"

FuelUsageCalc::FuelUsageCalc()
    : m_distance(0.0),
      m_fuelUsage(0.0),
      m_time()
{
    // nothing to do
}

void FuelUsageCalc::setBlackboard(Blackboard *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);
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
    }
    else if (name == "time")
    {
        auto time = a_topic.data.toDateTime();
        auto secs = time.toSecsSinceEpoch() - m_time.toSecsSinceEpoch();
        m_time = time;
        if (secs != 0) {
            postUpdate({"fuelPerSec", m_fuelUsage / secs});
        }
    }

}
