#ifndef VEHICLE_H
#define VEHICLE_H

#include <QObject>
#include <QList>

class QTimer;
class Observer;

class Vehicle : public QObject
{
    Q_OBJECT

public:
    explicit Vehicle(QObject *parent = nullptr);

    void registerObserver(Observer *observer);
    void unregiserObserver(Observer *observer);

    void notify();

signals:
    // Nothing for now

public slots:
    // Nothing for now

private:
    QList<Observer *>   m_observers;
    double              m_speed;
    double              m_accel;

    QTimer *            m_notificationTimer;

    void adjustSpeed();
};

#endif // VEHICLE_H
