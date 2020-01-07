#ifndef DASHWIDGETFACTORY_H
#define DASHWIDGETFACTORY_H

class DashWidget;
class Blackboard;
class QWidget;

class DashWidgetFactory
{
public:
    DashWidgetFactory();
    virtual ~DashWidgetFactory() = default;

    virtual DashWidget *createProduct(Blackboard *a_blackboard, QWidget *parent = nullptr) = 0;
};

#endif // DASHWIDGETFACTORY_H
