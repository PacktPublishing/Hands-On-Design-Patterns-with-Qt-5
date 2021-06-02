#ifndef POSITIONSOURCE_H
#define POSITIONSOURCE_H

#include "KnowledgeSource.h"
#include <QObject>

class QGeoPositionInfo;
class QGeoPositionInfoSource;

class PositionSource : public QObject, public KnowledgeSource
{
    Q_OBJECT

public:
    PositionSource(QObject *parent = nullptr);

    virtual void setBlackboard(BlackboardFacade *a_blackboard);

private slots:
    void handlePositionUpdate(const QGeoPositionInfo &update);

private:
    QGeoPositionInfoSource  *m_posSource;
};

#endif // POSITIONSOURCE_H
