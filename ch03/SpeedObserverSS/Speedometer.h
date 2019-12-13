#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include "Observer.h"
#include <QLCDNumber>

class Speedometer : public Observer, public QLCDNumber
{
public:
    Speedometer(QWidget* parent = nullptr);

public slots:
    void update(QVariant data) final;
};

#endif // SPEEDOMETER_H
