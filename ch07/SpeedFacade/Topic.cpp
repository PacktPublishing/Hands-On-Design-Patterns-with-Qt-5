#include "Topic.h"

// constructors
Topic::Topic()
    : Topic(QString(), QVariant())
{}

Topic::Topic(const Topic &right)
    : Topic(right.m_name, right.m_data)
{}

Topic::Topic(QString a_name, QVariant(a_data))
    : m_name(a_name), m_data(a_data)
{
    qRegisterMetaType<Topic *>();
};
