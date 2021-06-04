#include "BlackboardFacade.h"
#include <QDebug>
#include "Topic.h"


BlackboardFacade::BlackboardFacade(QObject *parent)
    : QQmlPropertyMap(this, parent)
{
    qRegisterMetaType<BlackboardFacade *>();
    qRegisterMetaType<Topic *>();
}

Topic *BlackboardFacade::inspect(const QString &name)
{
    return value(name).value<Topic *>();
}

void BlackboardFacade::update(Topic *a_topic)
{
    insert(a_topic->name(), QVariant::fromValue<Topic *>(a_topic));
}

void BlackboardFacade::update(const QString &name, const QVariant &data)
{
    update(new Topic(name, data));
}
