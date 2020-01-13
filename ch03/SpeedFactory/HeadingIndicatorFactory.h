#ifndef HEADINGINDICATORFACTORY_H
#define HEADINGINDICATORFACTORY_H

#include "DashWidgetFactory.h"
#include "HeadingIndicator.h"

class HeadingIndicatorFactory : public DashWidgetFactory
{
public:
    DashWidget *createProduct(Blackboard *a_blackboard, QWidget *parent = nullptr) final {
        auto obj = new HeadingIndicator(parent);
        obj->setBlackboard(a_blackboard);
        return obj;
    }
};


#endif // HEADINGINDICATORFACTORY_H
