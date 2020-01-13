#include "HeadlightSwitch.h"

#include "HeadlightStateMachine.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QThread>

HeadlightSwitch::HeadlightSwitch(QWidget *parent)
    : DashWidget(parent)
{
    auto layout = new QHBoxLayout;
    this->setLayout(layout);

    m_modeButton = new QPushButton("Headlignts", this);
    m_highbeamButton = new QPushButton("Toggle\nHigh Beams", this);
    m_highbeamButton->setEnabled(false);

    layout->addWidget(m_modeButton);
    layout->addWidget(m_highbeamButton);

    m_stateMachine = new HeadlightStateMachine;
    m_stateMachine->moveToThread(new QThread);

    connect(m_modeButton, &QPushButton::clicked,
            [this] () { m_stateMachine->submitEvent("next"); });
    connect(m_highbeamButton, &QPushButton::clicked,
            [this] () { m_stateMachine->submitEvent("toggleBeams"); });

    m_stateMachine->connectToState("On", m_highbeamButton, &QPushButton::setEnabled);

    m_stateMachine->start();
}

void HeadlightSwitch::setBlackboard(Blackboard *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);

    connect(m_stateMachine, &QScxmlStateMachine::reachedStableState,
            [this] () {
                this->postUpdate({"headlightState",
                                  m_stateMachine->activeStateNames(false)});
    });
}
