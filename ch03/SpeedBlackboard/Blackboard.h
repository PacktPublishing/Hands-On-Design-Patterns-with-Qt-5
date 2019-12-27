#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include "Topic.h"
#include <QString>
#include <QHash>

class Blackboard
{
public:
    Blackboard();

    Topic inspect(QString name);
    void update(const Topic &a_topic);

private:
    QHash<QString, Topic>    m_items;
};

#endif // BLACKBOARD_H
