#ifndef TOPIC_H_INCLUDED
#define TOPIC_H_INCLUDED

#include <QObject>
#include <QString>
#include <QVariant>
#include <QMetaType>
#include <PropertyClassTemplates.h>

struct Topic : public QObject
{
    Q_OBJECT

    NOTIFYING_PROPERTY(QString,   name)
    NOTIFYING_PROPERTY(QVariant,  data)

public:
    // constructors
    Topic();
    Topic(const Topic &right);
    Topic(QString a_name, QVariant(a_data));

    ~Topic() = default;

    bool operator==(const Topic & right) const {
        return (m_name == right.m_name) && (m_data == right.m_data);
    }

    Topic &operator=(const Topic &right) {
        if (this != &right) {
            m_name = right.m_name;
            m_data = right.m_data;
        }
        return *this;
    }

    bool isEmpty() { return m_name.isEmpty(); }
    bool isValid() { return m_name.isEmpty(); }
};

Q_DECLARE_METATYPE(Topic *)
Q_DECLARE_METATYPE(Topic)

#endif // TOPIC_H_INCLUDED
