#include "HighBeamIndicator.h"
#include "Blackboard.h"

#include <QLabel>
#include <QPainter>
#include <QHBoxLayout>

HighBeamIndicator::HighBeamIndicator(QWidget *parent)
    : DashWidget(parent)
{    
    this->setLayout(new QHBoxLayout);
    m_label = new QLabel(this);
    this->layout()->addWidget(m_label);
}

void HighBeamIndicator::act(Topic a_topic)
{
    if (a_topic.name == "highbeam")
    {
        QPixmap pix;
        QPainter painter(&pix);
        auto isOnP = a_topic.data.toBool();
        if (isOnP)
        {
            painter.drawText(32, 32, "On");
            painter.drawEllipse(0, 0, 64, 64);
        }
        else
        {
            painter.drawText(32, 32, "Off");
            painter.drawEllipse(0, 0, 64, 64);
        }
        painter.end();
        m_label->setPixmap(pix);

    }
}
