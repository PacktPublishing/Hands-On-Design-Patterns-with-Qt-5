#ifndef KNOWLEDGESOURCE_H
#define KNOWLEDGESOURCE_H

#include <QVariant>
#include "Topic.h"

class BlackboardFacade;

class KnowledgeSource
{
public:
    KnowledgeSource() = default;

    virtual void setBlackboard(BlackboardFacade *a_blackboard);
    virtual void act(Topic a_topic);

protected:
    virtual void postUpdate(Topic a_topic);
    virtual void postUpdate(Topic *a_topic);

protected:
    BlackboardFacade *m_blackboard;
};

#endif // KNOWLEDGESOURCE_H
