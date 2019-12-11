#include "Speedometer.h"

Speedometer::Speedometer(QWidget *parent)
    : Observer(),
      QLCDNumber(parent)
{
    setDigitCount(5);
    setSmallDecimalPoint(true);
    setDecMode();
}

void Speedometer::update(QVariant data)
{
    auto val = data.value<double>();
    display(val);
}
