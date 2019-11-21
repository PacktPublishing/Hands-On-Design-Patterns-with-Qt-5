// (1) The includes for a QML application
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    // (2) Prepare for High DPI display
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // (3) Start a GUI (QML) Application
    QGuiApplication app(argc, argv);

    // (4) Instantiate a QML Engine to run QML
    QQmlApplicationEngine engine;

    // (5) Specify the QML to use.
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    // (6) Load the QML code in the QML engine
    engine.load(url);

    // (7) Start the Qt app running
    return app.exec();
}
