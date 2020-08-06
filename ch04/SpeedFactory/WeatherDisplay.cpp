#include "WeatherDisplay.h"
#include "Blackboard.h"
#include <QTimer>
#include <QLabel>
#include <QHBoxLayout>


WeatherDisplay::WeatherDisplay(QWidget *parent)
    : DashWidget(parent)
{
    this->setLayout(new QHBoxLayout);
    m_label = new QLabel(this);
    m_label->setAlignment(Qt::AlignCenter);
    this->layout()->addWidget(m_label);
}

void WeatherDisplay::setBlackboard(Blackboard *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);
    QTimer::singleShot(1000, this, &WeatherDisplay::doTimedUpdate);
}

void WeatherDisplay::doTimedUpdate()
{

    auto wForecast = m_blackboard->inspect("weatherForecast").data.toString();
    auto wDesc     = m_blackboard->inspect("weatherDesc"    ).data.toString();
    auto wTemp     = m_blackboard->inspect("weatherTemp"    ).data.toString();
    auto wHightemp = m_blackboard->inspect("weatherHightemp").data.toString();
    auto wLowtemp  = m_blackboard->inspect("weatherLowtemp" ).data.toString();


    m_label->setText(tr("Weather\n%1\n%2").arg(wDesc).arg(wTemp));

    QTimer::singleShot(1000, this, &WeatherDisplay::doTimedUpdate);
}
