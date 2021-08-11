#include "KnowledgeSource.h"
#include "BlackboardFacade.h"

void KnowledgeSource::setBlackboard(BlackboardFacade *a_blackboard)
{
    m_blackboard = a_blackboard;
    connect(this, &KnowledgeSource::sendUpdate, m_blackboard, &BlackboardFacade::handleUpdate);
}

void KnowledgeSource::act(Topic a_topic)
{
    Q_UNUSED(a_topic)
}

void KnowledgeSource::postUpdate(Topic a_topic)
{
    postUpdate(&a_topic);
}

void KnowledgeSource::postUpdate(Topic *a_topic)
{
//    qDebug() << "Emitting "  << a_topic->name() << a_topic->data();
    emit sendUpdate(*a_topic);
}
