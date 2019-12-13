#ifndef OBSERVER_H
#define OBSERVER_H

#include <QVariant>
#include <QObject>

class Observer : public QObject
{
    Q_OBJECT

public:
    Observer() = default;
    virtual ~Observer() = default;

public slots:
    virtual void update(QVariant data) = 0;
};

#endif // OBSERVER_H
