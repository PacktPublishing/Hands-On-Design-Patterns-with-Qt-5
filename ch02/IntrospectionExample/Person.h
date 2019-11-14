#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QDate>
#include <QString>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);

public:
    // (1) An Enumeration
    enum Genders { MALE, FEMALE, OTHER, UNSPECIFIED };
    Q_ENUM(Genders)

    // (2) Property Definitions
    Q_PROPERTY(QString name     READ name     WRITE setName)
    Q_PROPERTY(QDate   birthday READ birthday WRITE setBirthday)
    Q_PROPERTY(int     heightCm READ heightCm WRITE setHeightCm)
    Q_PROPERTY(Genders gender   READ gender   WRITE setGender)

    // (3) Add Detail about the class
    Q_CLASSINFO("author", "John Werner")
    Q_CLASSINFO("purpose", "Class to store data about a person.")

public:
    // (4) Property Accessor Methods
    QString name() const;
    void setName(const QString &name);

    QDate birthday() const;
    void setBirthday(const QDate &birthday);

    int heightCm() const;
    void setHeightCm(int heightCm);

    Genders gender() const;
    void setGender(Genders gender);

    // (5) Discoverable Methods
    Q_INVOKABLE void CloneFrom(const Person &p);

public slots:
    // (6) Slots
    void OutputToXML(QString *output);
    void ReadFromXML(QString input);

private:
    // (7) Private Attributes (storage for Properties)
    QString     m_name;     ///< name of the person
    QDate       m_birthday; ///< the person's birthday
    int         m_heightCm; ///< the person's height (in cm)
    Genders     m_gender;   ///< the person's gender
};

// Pass QObjects via pointer, or define copy constructor
Q_DECLARE_METATYPE(Person *)

#endif // PERSON_H
