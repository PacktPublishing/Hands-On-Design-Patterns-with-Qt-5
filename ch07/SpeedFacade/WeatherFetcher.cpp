#include "WeatherFetcher.h"

#include "BlackboardFacade.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSettings>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QTimer>


#include <QDebug>

WeatherFetcher::WeatherFetcher(QObject *parent) :
    QObject(parent),
    m_updateSecs(5 * 60),
    m_minUpdateSecs(60)
{
    QSettings settings;
    setKey(settings.value("weather/key").toString());
    setUnits(settings.value("weather/units").toString());

    m_updateTimer = new QTimer(reinterpret_cast<QObject*>(this));
    m_updateTimer->setSingleShot(true);
    m_updateTimer->setInterval(m_updateSecs);

    connect(m_updateTimer, &QTimer::timeout, this, &WeatherFetcher::doUpdate);

    m_netMan = new QNetworkAccessManager(reinterpret_cast<QObject*>(this));
    connect(m_netMan, &QNetworkAccessManager::finished,
            this, &WeatherFetcher::handleApiResponse);
}

void WeatherFetcher::setBlackboard(BlackboardFacade *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);
    ForceUpdate();
}

int WeatherFetcher::updateSecs() const
{
    return m_updateSecs;
}

void WeatherFetcher::setUpdateSecs(int updateSecs)
{
    if (updateSecs >= m_minUpdateSecs)
    {
        m_updateSecs = updateSecs;
    }
}

QString WeatherFetcher::location() const
{
    return m_location;
}

void WeatherFetcher::setLocation(const QString &location)
{
    m_location = location;
}

int WeatherFetcher::minUpdateSecs() const
{
    return m_minUpdateSecs;
}

void WeatherFetcher::setMinUpdateSecs(int minUpdateSecs)
{
    m_minUpdateSecs = minUpdateSecs;
}

bool WeatherFetcher::ForceUpdate()
{
    auto currentSecs = QDateTime::currentSecsSinceEpoch();
    auto timeSince = currentSecs - m_lastUpdate.toSecsSinceEpoch();
    bool requestOk = timeSince >= minUpdateSecs();
    if (requestOk)
    {
        doUpdate();
    }
    return requestOk;
}

void WeatherFetcher::handleApiResponse(QNetworkReply *reply)
{
    auto data = reply->readAll();
    //-- qDebug() << data

    QJsonDocument   jDoc = QJsonDocument::fromJson(data);

    auto qObj = jDoc.object();

    QJsonObject mainSection = qObj.value("main").toObject();
    double temp         = mainSection.value("temp").toDouble();
    double lowtemp      = mainSection.value("temp_min").toDouble();
    double hightemp     = mainSection.value("temp_max").toDouble();

    auto weather  = qObj["weather"].toArray();
    QStringList weatherPieces;
    for (auto w : weather)
    {
        auto element = w.toObject();
        weatherPieces << element["main"].toString();
    }
    QString weatherDesc = weatherPieces.join(", ");

    QString forecast;   // data so nothing to set

    reply->deleteLater();

    // post the updated information
    postUpdate({"weatherForecast",  forecast});
    postUpdate({"weatherDesc",      weatherDesc});
    postUpdate({"weatherTemp",      temp});
    postUpdate({"weatherHightemp",  hightemp});
    postUpdate({"weatherLowtemp",   lowtemp});
}

QString WeatherFetcher::key() const
{
    return m_key;
}

void WeatherFetcher::setKey(const QString &key)
{
    m_key = key;
}

QString WeatherFetcher::units() const
{
    return m_units;
}

void WeatherFetcher::setUnits(const QString &units)
{
    if (units.contains("Farenheit"))
    {
        m_units = "imperial";
    }
    else if (units.contains("Celcius"))
    {
        m_units = "metric";
    }
    else
    {
        m_units = "xxx";
    }
}

QDateTime WeatherFetcher::lastUpdate() const
{
    return m_lastUpdate;
}

void WeatherFetcher::start()
{
    doUpdate();
}

void WeatherFetcher::start(int secs)
{
    m_updateSecs = secs;
    doUpdate();
}

void WeatherFetcher::stop()
{
    m_updateTimer->stop();
}

void WeatherFetcher::doUpdate()
{
    int updateTime = m_updateSecs * 1000;

    auto qvarLat = m_blackboard->inspect("GPSLat")->data();
    auto qvarLon = m_blackboard->inspect("GPSLon")->data();

    if (qvarLat.isValid() && qvarLon.isValid()) {
        auto posLat = qvarLat.toDouble();
        auto posLon = qvarLon.toDouble();

        QString query = QStringLiteral("http://api.openweathermap.org/data/2.5/weather?lat=%1&lon=%2&appid=%3&units=%4")
                .arg(posLat).arg(posLon).arg(m_key, m_units);
        // qDebug() << query;

        m_netMan->get(QNetworkRequest(QUrl(query)));

        m_lastUpdate = QDateTime::currentDateTime();
    } else {
        updateTime = 2000;
        qWarning() << "Invalid Position, waiting";
    }

    m_updateTimer->start(updateTime);
}
