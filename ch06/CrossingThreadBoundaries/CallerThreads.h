#ifndef CALLERTHREADS_H
#define CALLERTHREADS_H

#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTimer>

class ThreadedObject : public QObject
{
    Q_OBJECT

public:
    ThreadedObject(QObject *parent = nullptr);

public:
    void testSlot1(const QString &string);

public slots:
    void outputMessage(const QString &string, Qt::HANDLE cthread);

signals:
    void goDoOutputMessage(const QString &string, Qt::HANDLE cthread);
};


class Caller : public QObject
{
    Q_OBJECT

public:
    Caller(ThreadedObject * tobj, const QString &a_name,
           QObject *parent = nullptr) : QObject(parent), threaded(tobj), name(a_name) {
    }

public slots:
    void runTest();

signals:
    void doOutput(QString message, Qt::HANDLE cthread);

private:
    ThreadedObject *threaded;
    QString         name;
};



#endif // CALLERTHREADS_H
