#ifndef VEHICLE_H
#define VEHICLE_H

#include <QObject>
#include "Publisher.h"

class QTimer;
class Observer;

/// @note QObject must be first in inheritance tree!
class Vehicle : public QObject, public Publisher
{
    Q_OBJECT

public:
    explicit Vehicle(QObject *parent = nullptr);

signals:
    // Nothing for now

public slots:
    // Nothing for now

private:
    double              m_speed;
    double              m_accel;
    double              m_distance;
    double              m_heading;

    QTimer *            m_notificationTimer;

    void adjustSpeed();
};

#endif // VEHICLE_H
