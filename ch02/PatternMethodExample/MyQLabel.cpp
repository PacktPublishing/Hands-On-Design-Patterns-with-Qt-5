#include "MyQLabel.h"

MyQLabel::MyQLabel(QWidget *parent, Qt::WindowFlags f)
    : QLabel(parent, f)
{
    // nothing to see here
}

MyQLabel::MyQLabel(const QString &text, QWidget *parent, Qt::WindowFlags f)
    : QLabel(text, parent, f)
{
    // here, nothing to see is
}

void MyQLabel::paintEvent(QPaintEvent *e)
{
    setText(text().toUpper());
    QLabel::paintEvent(e);
}
