#ifndef TOPIC_H_INCLUDED
#define TOPIC_H_INCLUDED

#include <QString>
#include <QVariant>

struct Topic
{
    QString     name;
    QVariant    data;

    // constructors
    Topic() : Topic(QString(), QVariant())                               {};
    Topic(const Topic &right) : Topic(right.name, right.data)            {};
    Topic(QString a_name, QVariant(a_data)) : name(a_name), data(a_data) {};
    ~Topic() = default;

    bool operator==(const Topic & right) const {
        return (name == right.name) && (data == right.data);
    }

    bool isEmpty() { return name.isEmpty(); }
    bool isValid() { return name.isEmpty(); }
};

#endif // TOPIC_H_INCLUDED
