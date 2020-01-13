#include "HeadingIndicator.h"
#include "Blackboard.h"
#include <QTimer>
#include <QLabel>
#include <QHBoxLayout>

HeadingIndicator::HeadingIndicator(QWidget *parent)
    : DashWidget(parent)
{
    this->setLayout(new QHBoxLayout);
    m_label = new QLabel(this);
    m_label->setAlignment(Qt::AlignCenter);
    this->layout()->addWidget(m_label);
}

void HeadingIndicator::setBlackboard(Blackboard *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);
    QTimer::singleShot(1000, this, &HeadingIndicator::doTimedUpdate);
}

void HeadingIndicator::doTimedUpdate()
{
    auto val = m_blackboard->inspect("heading").data.toDouble();
    m_label->setText(tr("Heading\n%1").arg(QString::number(val, 'f', 1)));

    QTimer::singleShot(1000, this, &HeadingIndicator::doTimedUpdate);
}
