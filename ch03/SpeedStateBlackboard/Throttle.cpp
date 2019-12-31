#include "Throttle.h"

Throttle::Throttle(QWidget *parent)
    : Throttle(Qt::Vertical, parent)
{
    // nothing here
}

Throttle::Throttle(Qt::Orientation orientation, QWidget *parent)
    : QSlider(orientation, parent),
      KnowledgeSource(),
      m_value(0.0)
{
    setPageStep(10);
    setRange(-100, 100);
    connect(this, &QSlider::valueChanged, [this](int value) {
        postUpdate({"throttle", value});
    });

    setValue(0.0);
}

