#ifndef POSITIONSOURCE_H
#define POSITIONSOURCE_H

#include "KnowledgeSource.h"
#include <QObject>

class QGeoPositionInfo;
class QGeoPositionInfoSource;

class PositionSource : public KnowledgeSource
{
    Q_OBJECT

public:
    PositionSource();

    virtual void setBlackboard(BlackboardFacade *a_blackboard);

public slots:
    void InitSelf();

private slots:
    void handlePositionUpdate(const QGeoPositionInfo &update);

private:
    QGeoPositionInfoSource  *m_posSource;
};

#endif // POSITIONSOURCE_H
