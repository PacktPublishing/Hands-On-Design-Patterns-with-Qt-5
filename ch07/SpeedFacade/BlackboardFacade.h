#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include "Topic.h"
#include <QQmlPropertyMap>
#include <QString>
#include <QHash>

#include <PropertyClassTemplates.h>

class BlackboardFacade : public QQmlPropertyMap
{
    Q_OBJECT

public:
    BlackboardFacade(QObject *parent = nullptr);

    Q_INVOKABLE Topic *inspect(const QString &name);
    Q_INVOKABLE void update(Topic *a_topic);
    Q_INVOKABLE void update(const QString &name, const QVariant &data);
};

Q_DECLARE_METATYPE(BlackboardFacade *)

#endif // BLACKBOARD_H
