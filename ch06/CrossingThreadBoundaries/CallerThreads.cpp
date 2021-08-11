#include "CallerThreads.h"

ThreadedObject::ThreadedObject(QObject *parent) : QObject(parent)
{
    auto thread = new QThread(this);
    moveToThread(thread);

    thread->start(QThread::NormalPriority);
    thread->setObjectName("Thread 1");

    qDebug() << "Current Thread = " << QThread::currentThreadId() << QThread::currentThread()->objectName();
    qDebug() << "New Thread = " << thread->objectName();

    connect(this, &ThreadedObject::goDoOutputMessage,
            this, &ThreadedObject::outputMessage,
            Qt::QueuedConnection);
}

void ThreadedObject::testSlot1(const QString &string)
{
    qDebug() << "Current Thread = " << QThread::currentThreadId();
    emit goDoOutputMessage(string, QThread::currentThreadId());
}

void ThreadedObject::outputMessage(const QString &string, Qt::HANDLE cthread)
{
    auto thisThread = QThread::currentThreadId();
    qDebug() << string << "-- In thread" << thisThread << ":" << this->thread()->objectName() << Qt::endl
             << "---- Calling thread" << cthread << (cthread == thisThread ? "SAME" : "DIFFERENT");
}

void Caller::runTest()
{
    qDebug() << "Current Thread = " << QThread::currentThreadId();

    threaded->outputMessage(name + "::Direct Call", QThread::currentThreadId());

    emit doOutput(name + "::Signal Emitted", QThread::currentThreadId());
}
