#ifndef HEADINGINDICATOR_H
#define HEADINGINDICATOR_H

#include "DashWidget.h"

class HeadingIndicator : public DashWidget
{
    Q_OBJECT
public:
    HeadingIndicator(QWidget *parent = nullptr);

    // virtual void setBlackboard(Blackboard *a_blackboard);
    // virtual void act(Topic a_topic);

protected:
    // virtual void postUpdate(Topic a_topic);

};

#endif // HEADINGINDICATOR_H
