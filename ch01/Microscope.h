#ifndef MICROSCOPE_H
#define MICROSCOPE_H

#include <QImage>

class Microscope
{
public:
    static Microscope * Instance();
    Microscope(const Microscope &right) = delete;

    QImage CaptureImage();

    double xPos() const;
    void setXPos(double xPos);

    double yPos() const;
    void setYPos(double yPos);

    double focusPoint() const;
    void setFocusPoint(double focusPoint);

private:
    Microscope() = default;

    static Microscope *m_instance;
    double m_xPos;
    double m_yPos;
    double m_focusPoint;

    QImage m_lastImage;

};

#endif // MICROSCOPE_H
