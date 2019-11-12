#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QDate>
#include <QString>

class Person : public QObject
{
    Q_OBJECT

public:
    // (1) An Enumeration
    enum SexEnum { MALE, FEMALE, OTHER, UNSPECIFIED };
    Q_ENUM(SexEnum)

    // (2) Property Definitions
    Q_PROPERTY(QString name     READ name     WRITE setName)
    Q_PROPERTY(QDate   birthday READ birthday WRITE setBirthday)
    Q_PROPERTY(int     heightCm READ heightCm WRITE setHeightCm)
    Q_PROPERTY(SexEnum sex      READ sex      WRITE setSex)

public:
    explicit Person(QObject *parent = nullptr);

    // (3) Property Accessor Methods
    QString name() const;
    void setName(const QString &name);

    QDate birthday() const;
    void setBirthday(const QDate &birthday);

    int heightCm() const;
    void setHeightCm(int heightCm);


    SexEnum sex() const;
    void setSex(SexEnum sex);

private:
    // (4) Private Attributes (storage for Properties)
    QString     m_name;     ///< name of the person
    QDate       m_birthday; ///< the person's birthday
    int         m_heightCm; ///< the person's height (in cm)
    SexEnum     m_sex;      ///< the person's sex
};

// Pass QObjects via pointer, or define copy constructor
Q_DECLARE_METATYPE(Person *)

#endif // PERSON_H
