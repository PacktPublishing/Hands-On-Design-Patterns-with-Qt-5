#include "Controller.h"

#include <QTimer>
#include <QDateTime>

Controller::Controller(QObject *parent)
    : QObject(parent),
      m_blackboard(nullptr),
      mt_speed(),
      mt_distance(),
      m_speedo(nullptr),
      m_odo(nullptr),
      m_fuelUsageCalc(nullptr),
      m_fuelUsageDisp(nullptr)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(500);
    m_timer->setSingleShot(false);

    connect(m_timer, &QTimer::timeout, this, &Controller::Observe);
}

void Controller::setBlackboard(Blackboard *a_blackboard)
{
    m_blackboard = a_blackboard;
    m_timer->start();
}

void Controller::setOdo(KnowledgeSource *odo)
{
    m_odo = odo;
}

void Controller::setSpeedo(KnowledgeSource *speedo)
{
    m_speedo = speedo;
}

void Controller::Observe()
{
    if (m_blackboard)
    {
        mt_speed         = m_blackboard->inspect("speed");
        mt_distance      = m_blackboard->inspect("distance");
        mt_heading       = m_blackboard->inspect("heading");
        mt_fuelUsage     = m_blackboard->inspect("fuelUsage");
        mt_fuelPerDist   = m_blackboard->inspect("fuelPerDist");
    }
    // call the next stage after a tiny wait
    QTimer::singleShot(1, this, &Controller::Orient);
}

void Controller::Orient()
{

    // call the next stage after a tiny wait
    QTimer::singleShot(1, this, &Controller::Decide);
}

void Controller::Decide()
{

    // call the next stage after a tiny wait
    QTimer::singleShot(1, this, &Controller::Act);
}

void Controller::Act()
{
    auto now = QDateTime::currentDateTime();

    if (m_speedo) {
        m_speedo->act(mt_speed);
    }
    if (m_odo) {
        m_odo->act(mt_distance);
    }
    if (m_fuelUsageCalc) {
        m_fuelUsageCalc->act(mt_distance);
        m_fuelUsageCalc->act(mt_fuelUsage);
        m_fuelUsageCalc->act({"time", now});
    }
    if (m_fuelUsageDisp) {
        m_fuelUsageDisp->act(mt_fuelPerDist);
    }
}

void Controller::setFuelUsageDisp(KnowledgeSource *fuelUsageDisp)
{
    m_fuelUsageDisp = fuelUsageDisp;
}

void Controller::setFuelUsageCalc(KnowledgeSource *fuelUsageCalc)
{
    m_fuelUsageCalc = fuelUsageCalc;
}

