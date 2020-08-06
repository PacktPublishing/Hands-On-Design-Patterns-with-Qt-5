#ifndef WEATHERDISPLAY_H
#define WEATHERDISPLAY_H

#include "DashWidget.h"

class QLabel;

class WeatherDisplay : public DashWidget
{

public:
    WeatherDisplay(QWidget *parent = nullptr);

    void setBlackboard(Blackboard *a_blackboard) final;

private slots:
    void doTimedUpdate();

private:
    QLabel  *m_label;
};

#endif // WEATHERDISPLAY_H
