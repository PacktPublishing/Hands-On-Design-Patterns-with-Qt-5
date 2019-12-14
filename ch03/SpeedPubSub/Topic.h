#ifndef TOPIC_H_INCLUDED
#define TOPIC_H_INCLUDED

#include <QString>
#include <QVariant>

struct Topic
{
    QString     name;
    QVariant    data;

    bool operator==(const Topic & right) const {
        return (name == right.name) && (data == right.data);
    }
};

#endif // TOPIC_H_INCLUDED
