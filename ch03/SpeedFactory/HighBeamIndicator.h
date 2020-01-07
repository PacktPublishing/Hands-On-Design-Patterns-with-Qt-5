#ifndef HIGHBEAMINDICATOR_H
#define HIGHBEAMINDICATOR_H

#include "DashWidget.h"
class QLabel;

class HighBeamIndicator : public DashWidget
{
    Q_OBJECT
public:
    HighBeamIndicator(QWidget *parent = nullptr);

    //void setBlackboard(Blackboard *a_blackboard) final;
    void act(Topic a_topic) final;

protected:
    // virtual void postUpdate(Topic a_topic);

private:
    QLabel  *m_label;
};

#endif // HIGHBEAMINDICATOR_H
