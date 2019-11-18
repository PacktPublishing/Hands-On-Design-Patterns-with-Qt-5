#ifndef GENERICDECORATOR_H
#define GENERICDECORATOR_H

#include <QDebug>

class Component
{
public:
    Component()              = default;
    virtual ~Component()     = default;

    virtual void operation() = 0;
};

class ConcreteComponent final : public Component
{
public:
    ConcreteComponent()  = default;
    ~ConcreteComponent() = default;

    void operation()    {
        qDebug() << "We are doing our concrete operation!";
    }
};

class Decorator : public Component
{
public:
    Decorator(Component *a_component)
        : m_comp(a_component) {}
    virtual ~Decorator()      = default;

    virtual void operation()  = 0;
protected:
    Component *m_comp;
};

class Decorator1 : public Decorator
{
public:
    Decorator1(Component *a_component)
        : Decorator(a_component) {}
    virtual ~Decorator1() = default;

    virtual void operation()  {
        qDebug() << "Decorator1: Before we call m_comp->opreation()";
        m_comp->operation();
        qDebug() << "Decorator1: After we call m_comp->opreation()";
    }
};

class Decorator2 : public Decorator
{
public:
    Decorator2(Component *a_component)
        : Decorator(a_component) {}
    virtual ~Decorator2() = default;

    virtual void operation()  {
        qDebug() << "Decorator2: Before we call m_comp->opreation()";
        m_comp->operation();
        qDebug() << "Decorator2: After we call m_comp->opreation()";
    }
};

#endif // GENERICDECORATOR_H
