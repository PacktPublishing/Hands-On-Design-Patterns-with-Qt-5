#ifndef KNOWLEDGESOURCE_H
#define KNOWLEDGESOURCE_H

#include <QVariant>
#include <QObject>
#include "Topic.h"

class BlackboardFacade;

class KnowledgeSource : public QObject
{
    Q_OBJECT

public:
    KnowledgeSource() : QObject() {}

    virtual void setBlackboard(BlackboardFacade *a_blackboard);
    virtual void act(Topic a_topic);

signals:
    void sendUpdate(Topic a_topic);

protected:
    virtual void postUpdate(Topic a_topic);
    virtual void postUpdate(Topic *a_topic);

protected:
    BlackboardFacade *m_blackboard;
};

#endif // KNOWLEDGESOURCE_H
