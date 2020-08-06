#include "Blackboard.h"
#include <QDebug>

Blackboard::Blackboard()
    : m_items()
{
    // this space is blank
}

Topic Blackboard::inspect(QString name)
{
    Topic   topic;
    if (m_items.contains(name))
    {
        topic = m_items[name];
    }
    return topic;
}

void Blackboard::update(const Topic &a_topic)
{
    // qInfo() << a_topic.name << ":" << a_topic.data;

    if (m_items.contains(a_topic.name))
    {
        m_items[a_topic.name] = a_topic;
    }
    else
    {
        m_items.insert(a_topic.name, a_topic);
    }
}
