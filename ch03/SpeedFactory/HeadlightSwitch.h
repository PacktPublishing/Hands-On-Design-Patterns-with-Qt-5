#ifndef HEADLIGHTSWITCH_H
#define HEADLIGHTSWITCH_H

#include "DashWidget.h"

class HeadlightStateMachine;
class QPushButton;

class HeadlightSwitch : public DashWidget
{
public:
    HeadlightSwitch(QWidget *parent = nullptr);

    void setBlackboard(Blackboard *a_blackboard) final;

private:
    QPushButton     *m_modeButton;
    QPushButton     *m_highbeamButton;

    HeadlightStateMachine  *m_stateMachine;

};

#endif // HEADLIGHTSWITCH_H
