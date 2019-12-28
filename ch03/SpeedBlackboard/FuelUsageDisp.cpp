#include "FuelUsageDisp.h"
#include "ui_FuelUsageDisp.h"

FuelUsageDisp::FuelUsageDisp(QWidget *parent)
    : QWidget(parent),
      KnowledgeSource(),
      ui(new Ui::FuelUsageDisp),
      m_mode(FuelUsageDisp::Overall)
{
    ui->setupUi(this);
    ui->lcdNumber->setDecMode();
    ui->lcdNumber->setDigitCount(5);
    ui->lcdNumber->setSmallDecimalPoint(true);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);

    connect(ui->modeButton, &QPushButton::clicked,
            this, &FuelUsageDisp::nextMode);
}

void FuelUsageDisp::setBlackboard(Blackboard *a_blackboard)
{
    KnowledgeSource::setBlackboard(a_blackboard);
}

void FuelUsageDisp::act(Topic a_topic)
{
    auto val = a_topic.data.toDouble();
    auto name = a_topic.name;

    QString text = "-999.99";
    text = QString::number(val, 'f', 4);

    if ((name == "fuelPerSec") && (m_mode == PerSec)) {
        text = QString::number(val, 'f', 6);
    }
    else if ((name == "fuelPerdist") && (m_mode == Overall)) {
        text = QString::number(val, 'f', 6);
    }
    ui->lcdNumber->display(text);
}

void FuelUsageDisp::nextMode()
{
    QString boxText = "unknown";
    switch(m_mode)
    {
    case FuelUsageDisp::Overall:
        m_mode = PerSec;
        boxText = "Fuel / Sec";
        break;

    case FuelUsageDisp::PerSec:
        m_mode = Overall;
        boxText = "Fuel / Dist";
        break;
    }

    ui->modeButton->setText(QVariant::fromValue(m_mode).toString());
    ui->fuelBox->setTitle(boxText);
}
