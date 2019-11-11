#include "Person.h"

Person::Person(QObject *parent) : QObject(parent)
{

}

QString Person::name() const
{
    return m_name;
}

void Person::setName(const QString &name)
{
    m_name = name;
}

QDate Person::birthday() const
{
    return m_birthday;
}

void Person::setBirthday(const QDate &birthday)
{
    m_birthday = birthday;
}

int Person::heightCm() const
{
    return m_heightCm;
}

void Person::setHeightCm(int heightCm)
{
    m_heightCm = heightCm;
}

Person::SexEnum Person::sex() const
{
    return m_sex;
}

void Person::setSex(Person::SexEnum sex)
{
    m_sex = sex;
}
