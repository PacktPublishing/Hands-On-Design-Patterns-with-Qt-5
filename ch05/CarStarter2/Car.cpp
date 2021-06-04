#include "Car.h"

#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <QDebug>
#include <QRandomGenerator64>

Car::Car(int carNum, QMutex *mutex, QWaitCondition *condition, QObject *parent)
    : QObject(parent),
      m_carNumber(carNum),
      m_trackMutex(mutex),
      m_condition(condition)
{
    // sponsorship opportunities available. Inquire within!
}

int Car::carNumber() const
{
    return m_carNumber;
}

void Car::setCarNumber(int carNumber)
{
    m_carNumber = carNumber;
}

QMutex *Car::trackMutex() const
{
    return m_trackMutex;
}

void Car::setTrackMutex(QMutex *trackMutex)
{
    m_trackMutex = trackMutex;
}

void Car::run()
{
    QRandomGenerator64  rand;
    QTextStream qcout(stdout);
    qcout << "Car is running.";
    forever {
        m_trackMutex->lock();
        m_condition->wait(m_trackMutex);
        m_trackMutex->unlock();
        qcout << "-> Starting Car #" << m_carNumber << Qt::endl;
        QThread::sleep((rand.generate() % 5) + 2);
        qcout << "-< Car #" << m_carNumber << " finished." << Qt::endl;
    }
}

QWaitCondition *Car::condition() const
{
    return m_condition;
}

void Car::setCondition(QWaitCondition *condition)
{
    m_condition = condition;
}
