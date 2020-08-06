#include "FuelUsageDisp.h"
#include "ui_FuelUsageDisp.h"

#include <QScxmlStateMachine>

FuelUsageDisp::FuelUsageDisp(QWidget *parent)
    : QWidget(parent),
      KnowledgeSource(),
      ui(new Ui::FuelUsageDisp),
      m_modeSM(nullptr),
      m_perSec(0.0),
      m_perDist(0.0),
      m_total(0.0),
      m_perFuel(0.0)
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

    if (name == "fuelPerSec") {
        m_perSec = val;
    }
    else if (name == "fuelPerDist") {
        m_perDist = val;
    }
    else if (name == "fuelUsage") {
        m_total = val;
    }
    else if (name == "distPerFuel") {
        m_perFuel = val;
    }
    updateMode();   // for re-display
}

void FuelUsageDisp::nextMode()
{
    if (m_modeSM)
    {
        m_modeSM->submitEvent("Next");
    }
}

void FuelUsageDisp::updateMode()
{
    if (m_modeSM)
    {
        auto mode = m_modeSM->activeStateNames();
        ui->fuelBox->setTitle(mode.first());

        QString numText = "----";
        if (mode.contains("PerDistance"))
        {
            numText = QString::number(m_perDist, 'f', 4);
        }
        else if (mode.contains("PerSecond"))
        {
            numText = QString::number(m_perSec, 'f', 4);

        }
        else if (mode.contains("Total"))
        {
            numText = QString::number(m_total, 'f', 6);
        }
        else if (mode.contains("DistPerFuel"))
        {
            numText = QString::number(m_perFuel, 'f', 6);
        }
        ui->lcdNumber->display(numText);
    }
}


QScxmlStateMachine *FuelUsageDisp::modeSM() const
{
    return m_modeSM;
}

void FuelUsageDisp::setModeSM(QScxmlStateMachine *modeSM)
{
    m_modeSM = modeSM;
    m_modeSM->init();
    connect(m_modeSM, &QScxmlStateMachine::reachedStableState,
            this, &FuelUsageDisp::updateMode);
    m_modeSM->start();
}
