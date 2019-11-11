#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QDate>
#include <QString>

class Person : public QObject
{
    Q_OBJECT

public:
    enum SexEnum {
        MALE,
        FEMALE
    };

    Q_ENUM(SexEnum)

    Q_PROPERTY(QString name     READ name     WRITE setName)
    Q_PROPERTY(QDate   birthday READ birthday WRITE setBirthday)
    Q_PROPERTY(int     heightCm READ heightCm WRITE setHeightCm)
    Q_PROPERTY(SexEnum sex      READ sex      WRITE setSex)

public:
    explicit Person(QObject *parent = nullptr);


    QString name() const;
    void setName(const QString &name);

    QDate birthday() const;
    void setBirthday(const QDate &birthday);

    int heightCm() const;
    void setHeightCm(int heightCm);

    SexEnum sex() const;
    void setSex(SexEnum sex);

signals:

public slots:

private:
    QString     m_name;     ///< name of the person
    QDate       m_birthday; ///< the person's birthday
    int         m_heightCm; ///< the person's height (in cm)
    SexEnum     m_sex;      ///< the person's sex

};

#endif // PERSON_H
