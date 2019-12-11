#ifndef OBSERVER_H
#define OBSERVER_H

#include <QVariant>


class Observer
{
public:
    Observer() = default;
    virtual ~Observer() = default;

    virtual void update(QVariant data) = 0;
};

#endif // OBSERVER_H
