#include "PositionSource.h"

#include <QTimer>
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include <QDebug>

PositionSource::PositionSource(QObject *parent)
    : QObject(parent),
      KnowledgeSource()
{
    m_posSource = QGeoPositionInfoSource::createDefaultSource(this);
    if (m_posSource) {
        connect(m_posSource, &QGeoPositionInfoSource::positionUpdated,
                this, &PositionSource::handlePositionUpdate);

        // Start Somewhere: 43.1566° N, 77.6088° W
        postUpdate({"GPSLat",    -77.6088});
        postUpdate({"GPSLon",    43.1566});
        postUpdate({"GPSDir",    123.45});
        postUpdate({"GPSSpeed",  0.123});
        postUpdate({"GPSVSpeed", 0.0});

    } else {
        qWarning() << "!! No Position Source found. Using default. !!";
    }
}

void PositionSource::setBlackboard(Blackboard *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);
}

void PositionSource::handlePositionUpdate(const QGeoPositionInfo &update)
{
    postUpdate({"GPSLat", update.coordinate().latitude()});
    postUpdate({"GPSLon", update.coordinate().longitude()});
    postUpdate({"GPSDir", update.attribute(QGeoPositionInfo::Direction)});
    postUpdate({"GPSSpeed", update.attribute(QGeoPositionInfo::GroundSpeed)});
    postUpdate({"GPSVSpeed", update.attribute(QGeoPositionInfo::VerticalSpeed)});
}
