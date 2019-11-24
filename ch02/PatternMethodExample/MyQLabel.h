#ifndef MYQLABEL_H
#define MYQLABEL_H

#include <QLabel>



class MyQLabel : public QLabel
{
public:
    explicit MyQLabel(QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    explicit MyQLabel(const QString &text, QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());

protected:
    void paintEvent(QPaintEvent *) override;

};

#endif // MYQLABEL_H
