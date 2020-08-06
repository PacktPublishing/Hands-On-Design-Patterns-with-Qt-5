#ifndef HIGHBEAMINDICATOR_H
#define HIGHBEAMINDICATOR_H

#include "DashWidget.h"

class QLabel;

class HighBeamIndicator : public DashWidget
{
    Q_OBJECT
public:
    HighBeamIndicator(QWidget *parent = nullptr);

    void setBlackboard(Blackboard *a_blackboard) final;

protected:
    // virtual void postUpdate(Topic a_topic);

private slots:
    void handleHeadlightState(void);

private:
    QLabel  *m_label;
};

#endif // HIGHBEAMINDICATOR_H
