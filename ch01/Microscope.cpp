#include "Microscope.h"
#include <QDebug>

Microscope *Microscope::m_instance = nullptr;

Microscope *Microscope::Instance()
{
    if (!m_instance) {
        m_instance = new Microscope();
    }
    return m_instance;
}

double Microscope::focusPoint() const
{
    return m_focusPoint;
}

void Microscope::setFocusPoint(double focusPoint)
{
    m_focusPoint = focusPoint;
    qDebug() << __FUNCTION__ << ": FocusPoint = " << m_focusPoint;
}

double Microscope::yPos() const
{
    return m_yPos;
}

void Microscope::setYPos(double yPos)
{
    m_yPos = yPos;
    qDebug() << __FUNCTION__ << ": YPos = " << m_yPos;
}

double Microscope::xPos() const
{
    return m_xPos;
}

void Microscope::setXPos(double xPos)
{
    m_xPos = xPos;
    qDebug() << __FUNCTION__ << ": XPos = " << m_xPos;
}
