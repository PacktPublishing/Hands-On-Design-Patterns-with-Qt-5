#include "Person.h"
#include <QString>
#include <QMetaProperty>
#include <QMetaMethod>
#include <QDebug>

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
    qDebug() << p.name() << ":" << p.sex() << ":" << p.birthday()
             << ":" << p.heightCm();

    qDebug() << "\n-- retrieve properties by property names --";
    qDebug() << p.property("name") << ":" << p.property("sex")
             << ":" << p.property("birthday")
             << ":" << p.property("heightCm")
             << ":" << p.property("nickname");

    qDebug() << "\n-- retrieve properties using Introspection --";
    // static properties
    auto metaObject = p.staticMetaObject;
    auto propCount = metaObject.propertyCount();
    for (int i = 0; i < propCount; ++i)
    {
        auto prop = metaObject.property(i);
        auto propName = prop.name();
        auto propValue = prop.read(&p);

        qDebug() << propName << "=" << propValue;
    }
    // dynamic properties
    for (auto propName : p.dynamicPropertyNames())
    {
        auto propValue = p.property(propName);
        qDebug() << propName << "=" << propValue;
    }

    qDebug() << "\n-- Discover Enumerations usng introspection --";
    auto enumCount = metaObject.enumeratorCount();
    for (int i = 0; i < enumCount; ++i)
    {
        auto metaEnum = metaObject.enumerator(i);
        auto name = metaEnum.name();
        auto keyCount = metaEnum.keyCount();
        QStringList keypairs;
        for (int j = 0; j < keyCount; ++j)
        {
            auto key = metaEnum.key(j);
            auto value = metaEnum.value(j);
            keypairs << QString("%1 = %2").arg(key).arg(value);
        }
        qDebug() << QString("%1 {%2}").arg(name).arg(keypairs.join(", "));
    }

    qDebug() << "\n-- Discover methods using introspection --";
    auto className = metaObject.className();
    auto methodCount = metaObject.methodCount();
    for (int i = 0; i < methodCount; ++i)
    {
        auto metaMethod = metaObject.method(i);
        auto signature = metaMethod.methodSignature();

        qDebug() << QString("%1::%2")
                        .arg(className)
                        .arg(QString(signature));
    }

    qDebug() << "\n-- Discover Class Info using Introspection --";
    auto ciCount = metaObject.classInfoCount();
    for (int i = 0; i < ciCount; ++i)
    {
        auto classInfo = metaObject.classInfo(i);
        qDebug() << classInfo.name() << ":" << classInfo.value();
    }
}
