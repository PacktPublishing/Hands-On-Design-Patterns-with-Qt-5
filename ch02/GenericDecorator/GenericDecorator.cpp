/**
 * A Generic example of using a decorator
 */

#include "GenericDecorator.h"

void GenericDecoratorUsage()
{
    // Create the ConcreteComponent object that will do our work
    auto cc = new ConcreteComponent();

    // Create Decorator 1, passinging the concrete component
    auto cd1 = new Decorator1(cc);

    // Create Decorator 2 and chain it to decoractor 1
    auto cd2 = new Decorator2(cd1);

    qDebug() <<  "* Invoke Decorator 1 *";
    cd1->operation();

    qDebug() <<  "* Invoke Decorator 2 *";
    cd2->operation();

}
