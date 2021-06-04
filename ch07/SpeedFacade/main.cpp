#include <QGuiApplication>
#include <QQmlApplicationEngine>


#include <QScopedPointer>
#include <QQmlContext>
#include "BlackboardFacade.h"
#include "Vehicle.h"
#include "FuelUsageCalc.h"
#include "PositionSource.h"
#include "WeatherFetcher.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    // (1) Build the vehicle data sources
    QScopedPointer<BlackboardFacade> facade(new BlackboardFacade(nullptr));

    QScopedPointer<Vehicle, QScopedPointerDeleteLater> vehicle(new Vehicle);
    vehicle->setBlackboard(facade.data());

    QScopedPointer<FuelUsageCalc, QScopedPointerDeleteLater> fuelUsageCalc(new FuelUsageCalc);
    fuelUsageCalc->setBlackboard(facade.data());

    QScopedPointer<PositionSource, QScopedPointerDeleteLater> positionSource(new PositionSource);
    positionSource->setBlackboard(facade.data());

    QScopedPointer<WeatherFetcher, QScopedPointerDeleteLater> weather(new WeatherFetcher);
    weather->setBlackboard(facade.data());


    // (2) Instantiate the QML Engine and add the facade class to the engine's root context
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("theBlackboardFacade", facade.get());

    // (3) Load the main qml file
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();

    // (4) Clean up in order
    qDebug() << "---- Cleaning Up ----";
//    weather->deleteLater();
//    positionSource->deleteLater();
//    fuelUsageCalc->deleteLater();
//    vehicle->deleteLater();
}
