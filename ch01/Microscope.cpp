#include "Microscope.h"

Microscope *Microscope::m_instance = nullptr;

//Microscope::Microscope()
//{
//}

double Microscope::focusPoint() const
{
    return m_focusPoint;
}

void Microscope::setFocusPoint(double focusPoint)
{
    m_focusPoint = focusPoint;
}

double Microscope::yPos() const
{
    return m_yPos;
}

void Microscope::setYPos(double yPos)
{
    m_yPos = yPos;
}

Microscope *Microscope::Instance()
{
    if (!m_instance) {
        m_instance = new Microscope();
    }
    return m_instance;
}

double Microscope::xPos() const
{
    return m_xPos;
}

void Microscope::setXPos(double xPos)
{
    m_xPos = xPos;
}
