#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTimer>

#include "CallerThreads.h"


int main(int argc, char *argv[])
{
    qDebug() << "Main Thread:" << QThread::currentThreadId();

    QCoreApplication a(argc, argv);

    auto threaded = new ThreadedObject();
    auto queued = new Caller(threaded, "Queued");
    auto direct = new Caller(threaded, "Direct");

    QObject::connect(queued, &Caller::doOutput, threaded, &ThreadedObject::outputMessage, Qt::QueuedConnection);
    QObject::connect(direct, &Caller::doOutput, threaded, &ThreadedObject::outputMessage, Qt::DirectConnection);


    qDebug() << "=== Launching QTimer ===";
    QTimer::singleShot(20, [queued, direct, threaded] () {
        qDebug() << "QTimer Thread:" << QThread::currentThreadId();
        qDebug() << "---- DIRECT CONNECTION ----";
        direct->runTest();

        qDebug() << "---- QUEUD CONNECTION ----";
        queued->runTest();

        qDebug() << "---- DIRECT CALL ----";
        threaded->testSlot1("Direct call");
    });

    return a.exec();
}
