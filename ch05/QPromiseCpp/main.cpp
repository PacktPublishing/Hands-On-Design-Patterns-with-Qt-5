#include <QCoreApplication>
#include <QPromise>
#include <QObject>
#include <QFuture>
#include <QScopedPointer>
#include <QDebug>
#include <QRandomGenerator64>


int sumToN(int n) {
    int sum = 0;
    for (int i = 1; i < n+1; ++i) {
        sum += i;
    }
}

int sumRandom(int loopCount) {
    int sum = 0;
    for (int i = 0; i < loopCount; ++i)
    {
        for (int j = 0; j < loopCount/2; ++j)
        {
            sum += QRandomGenerator64::system()->generate() % 100000;
        }
    }
    return sum;
}


int main(int argc, char *argv[])
{

    QPromise<int>   promise;    // a promise that will return an int
    QFuture<int>    future;     // a future that is an int.

    future = promise.future();

    QScopedPointer<QThread> thread(QThread::create([] (QPromise<int> promise) {
        promise.start();
        for (int i = 0; i < 20; i++) {
            promise.addResult(i);
            if (i == 10) {

            }
        }
        promise.finish();
    }, std::move(promise)));
    thread->start();

    future.waitForFinished();
    qInfo() << future.results();

//    QCoreApplication a(argc, argv);
//
//    return a.exec();
}
