#include "HighBeamIndicator.h"
#include "Blackboard.h"

#include <QLabel>
#include <QPainter>
#include <QHBoxLayout>
#include <QScxmlStateMachine>
#include <QTimer>

HighBeamIndicator::HighBeamIndicator(QWidget *parent)
    : DashWidget(parent)
{    
    this->setLayout(new QHBoxLayout);
    m_label = new QLabel(this);
    m_label->setAlignment(Qt::AlignCenter);
    this->layout()->addWidget(m_label);
}

void HighBeamIndicator::setBlackboard(Blackboard *a_blackboard)
{
    m_blackboard = a_blackboard;
    QTimer::singleShot(50, this, &HighBeamIndicator::handleHeadlightState);
}

void HighBeamIndicator::handleHeadlightState()
{
    auto topic = m_blackboard->inspect("headlightState");
    auto states = topic.data.toStringList();

    m_label->setText(states.join("\n"));

    QTimer::singleShot(50, this, &HighBeamIndicator::handleHeadlightState);
}

