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
    auto result = this->value(name).value<Topic *>();
    return result;
}

void BlackboardFacade::update(Topic *a_topic)
{
    insert(a_topic->name(), QVariant::fromValue<Topic *>(a_topic));
}

void BlackboardFacade::update(const QString &name, const QVariant &data)
{
    update(new Topic(name, data));
}

void BlackboardFacade::handleUpdate(Topic a_topic)
{
    auto tp = new Topic(a_topic);
    update(tp);
}
