#ifndef THROTTLE_H
#define THROTTLE_H

#include <QSlider>
#include "KnowledgeSource.h"

class Throttle : public QSlider, public KnowledgeSource
{
    Q_OBJECT

public:
    explicit Throttle(QWidget *parent = nullptr);
    explicit Throttle(Qt::Orientation orientation, QWidget *parent = nullptr);

    // void setBlackboard(Blackboard *a_blackboard) final;
    // void act(Topic a_topic) final;

protected:
    // void postUpdate(Topic a_topic) final;

private:
    double  m_value;

};

#endif // THROTTLE_H
