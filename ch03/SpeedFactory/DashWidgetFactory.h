#ifndef DASHWIDGETFACTORY_H
#define DASHWIDGETFACTORY_H

class DashWidget;
class Blackboard;
class QWidget;

template <class T>
class DashWidgetFactory
{
public:
//    DashWidgetFactory();
//    ~DashWidgetFactory() = default;

    static DashWidget *createProduct(Blackboard *a_blackboard, QWidget *parent = nullptr) {
        auto obj = new T(parent);
        obj->setBlackboard(a_blackboard);
        return obj;
    }
};

#endif // DASHWIDGETFACTORY_H
