#include "Person.h"
#include <QString>
#include <QMetaProperty>
#include <QDebug>


/// Dump the properties of a QObject
template <typename T>
void DumpProperties(const T *obj)
{
    auto propCount = obj->staticMetaObject.propertyCount();
    for (int i = 0; i < propCount; ++i)
    {
        auto prop = obj->staticMetaObject.property(i);
        auto propName = prop.name();
        auto propValue = prop.read(obj);

        qDebug() << propName << "=" << propValue;
    }
    for (auto propName : obj->dynamicPropertyNames())
    {
        auto propValue = obj->property(propName);
        qDebug() << propName << "=" << propValue;
    }
}


int main(int argc, char *argv[])
{
    Q_UNUSED(argc)  // tell the compiler argc is unused
    Q_UNUSED(argv)  // tell the compiler argv is unused

    Person p;
    p.setName("John");
    p.setBirthday(QDate::currentDate());
    p.setHeightCm(45);
    p.setSex(Person::MALE);

    // add a dynamic property to the person
    p.setProperty("nickname", "Johnboy");

    qDebug() << "-- retrieve properties via read methods --";
    qDebug() << p.name() << ":" << p.sex() << ":" << p.birthday() << ":" << p.heightCm();

    qDebug() << "-- retrieve properties by property names --";
    qDebug() << p.property("name") << ":" << p.property("sex") << ":" << p.property("birthday")
             << ":" << p.property("heightCm") << ":" << p.property("nickname");

    qDebug() << "-- dump all of the properties of a person --";
    DumpProperties(&p);
}
