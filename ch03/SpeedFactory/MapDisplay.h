#ifndef MAPDISPLAY_H
#define MAPDISPLAY_H

#include "DashWidget.h"

class MapDisplay : public DashWidget
{
    Q_OBJECT
public:
    MapDisplay(QWidget *parent = nullptr);

    // virtual void setBlackboard(Blackboard *a_blackboard);
    // virtual void act(Topic a_topic);

protected:
    // virtual void postUpdate(Topic a_topic);

};

#endif // MAPDISPLAY_H
