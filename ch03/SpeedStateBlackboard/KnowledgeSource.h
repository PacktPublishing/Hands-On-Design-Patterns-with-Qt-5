#ifndef KNOWLEDGESOURCE_H
#define KNOWLEDGESOURCE_H

#include <QVariant>
#include "Topic.h"

class Blackboard;

class KnowledgeSource
{
public:
    KnowledgeSource() = default;

    virtual void setBlackboard(Blackboard *a_blackboard);
    virtual void act(Topic a_topic);

protected:
    virtual void postUpdate(Topic a_topic);

protected:
    Blackboard *m_blackboard;
};

#endif // KNOWLEDGESOURCE_H
