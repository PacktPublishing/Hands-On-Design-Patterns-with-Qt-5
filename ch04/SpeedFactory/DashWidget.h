#ifndef DASHWIDGET_H
#define DASHWIDGET_H

#include <QWidget>
#include "KnowledgeSource.h"
#include "Topic.h"

class DashWidget : public QWidget, public KnowledgeSource
{
    Q_OBJECT

public:
    explicit DashWidget(QWidget *parent = nullptr);

    // virtual void setBlackboard(Blackboard *a_blackboard);
    // virtual void act(Topic a_topic);

protected:
    // virtual void postUpdate(Topic a_topic);

signals:

};

#endif // DASHWIDGET_H
