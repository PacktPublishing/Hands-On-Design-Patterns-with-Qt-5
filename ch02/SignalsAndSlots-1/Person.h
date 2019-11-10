#ifndef CUSTOMDATA_H
#define CUSTOMDATA_H

#include <QDate>
#include <QString>
#include <QMetaType>

class Person
{
public:
    Person();
    Person(QString a_name, QDate a_birthday, int a_heightCm);
    Person(const Person &right);

    Person &operator=(const Person &right);

    // * Accessors *
    QString name() const;
    void setName(const QString &name);

    QDate birthday() const;
    void setBirthday(const QDate &birthday);

    int heightCm() const;
    void setHeightCm(int heightCm);

private:
    QString     m_name;     ///< name of the person
    QDate       m_birthday; ///< the person's birthday
    int         m_heightCm; ///< the person's height (in cm)
};

Q_DECLARE_METATYPE(Person);

#endif // CUSTOMDATA_H
