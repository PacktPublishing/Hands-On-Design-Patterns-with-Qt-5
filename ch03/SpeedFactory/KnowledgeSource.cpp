#include "KnowledgeSource.h"
#include "Blackboard.h"

void KnowledgeSource::setBlackboard(Blackboard *a_blackboard)
{
    m_blackboard = a_blackboard;
}

void KnowledgeSource::act(Topic a_topic)
{
    Q_UNUSED(a_topic)
}

void KnowledgeSource::postUpdate(Topic a_topic)
{
    if (m_blackboard) {
        m_blackboard->update(a_topic);
    }
}
