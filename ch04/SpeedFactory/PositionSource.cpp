#include "PositionSource.h"

#include <QTimer>
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include <QDebug>

PositionSource::PositionSource(QObject *parent)
    : QObject(parent),
      KnowledgeSource()
{
    // for windows 10, see if we have a position source, else fallback
    auto posSources = QGeoPositionInfoSource::availableSources();
    qInfo() << "This system has the following QGeoPositionInfoSources:" << posSources;

    if (posSources.contains("winrt")) {
        m_posSource = QGeoPositionInfoSource::createSource("winrt", this);
    } else {
        m_posSource = QGeoPositionInfoSource::createDefaultSource(this);
    }

    if (m_posSource) {
        connect(m_posSource, &QGeoPositionInfoSource::positionUpdated,
                this, &PositionSource::handlePositionUpdate);
        m_posSource->setUpdateInterval(10 * 1000);
        m_posSource->startUpdates();
    } else {
        qWarning() << "!! No Position Source found. Using default position. !!";
    }
}

void PositionSource::setBlackboard(Blackboard *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);

    // Start Somewhere: 43.1566° N, 77.6088° W
    postUpdate({"GPSLon",    -77.6088});
    postUpdate({"GPSLat",    43.1566});
    postUpdate({"GPSDir",    123.45});
    postUpdate({"GPSSpeed",  0.123});
    postUpdate({"GPSVSpeed", 0.0});
}

void PositionSource::handlePositionUpdate(const QGeoPositionInfo &update)
{
    postUpdate({"GPSLat", update.coordinate().latitude()});
    postUpdate({"GPSLon", update.coordinate().longitude()});
    postUpdate({"GPSDir", update.attribute(QGeoPositionInfo::Direction)});
    postUpdate({"GPSSpeed", update.attribute(QGeoPositionInfo::GroundSpeed)});
    postUpdate({"GPSVSpeed", update.attribute(QGeoPositionInfo::VerticalSpeed)});
}
