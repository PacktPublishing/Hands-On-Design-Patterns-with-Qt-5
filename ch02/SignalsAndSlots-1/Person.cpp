#include "Person.h"

Person::Person()
    : m_name(),
      m_birthday(),
      m_heightCm()
{
    // tell the metaobject system about our type
    qRegisterMetaType<Person>();
}

Person::Person(QString a_name, QDate a_birthday, int a_heightCm)
    : m_name(a_name),
      m_birthday(a_birthday),
      m_heightCm(a_heightCm)
{
    // tell the metaobject system about our type
    qRegisterMetaType<Person>();
}

Person::Person(const Person &right)
    : m_name(right.m_name),
      m_birthday(right.m_birthday),
      m_heightCm(right.m_heightCm)
{
    // rent this space!
}

Person &Person::operator=(const Person &right)
{
    if (this != &right)
    {
        m_name      = right.m_name;
        m_birthday  = right.m_birthday;
        m_heightCm  = right.m_heightCm;
    }
    return *this;
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
