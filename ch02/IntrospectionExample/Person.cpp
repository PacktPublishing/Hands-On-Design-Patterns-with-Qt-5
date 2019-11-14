#include "Person.h"
#include <QVariant>

Person::Person(QObject *parent)
    : QObject(parent),
      m_name(),
      m_birthday(),
      m_heightCm(),
      m_gender(UNSPECIFIED)
{
    // tell the metaobject system about our type
    qRegisterMetaType<Person *>();
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

Person::Genders Person::gender() const
{
    return m_gender;
}

void Person::setGender(Person::Genders sex)
{
    m_gender = sex;
}

void Person::CloneFrom(const Person &p)
{
    m_name     = p.m_name;
    m_birthday = p.m_birthday;
    m_heightCm = p.m_heightCm;
    m_gender      = p.m_gender;
}

void Person::OutputToXML(QString *output)
{
    /// @todo Implement Me!
}

void Person::ReadFromXML(QString input)
{
    /// @todo Implement Me!
}
