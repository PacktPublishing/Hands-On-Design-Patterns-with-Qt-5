#include "FuelUsageDisp.h"
#include "ui_FuelUsageDisp.h"

#include "Blackboard.h"

#include <QScxmlStateMachine>
#include <QTimer>

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
    QTimer::singleShot(1000, [this] () { doTimedUpdate(); });
}

void FuelUsageDisp::doTimedUpdate()
{
    m_perSec  = m_blackboard->inspect("fuelPerSec").data.toDouble();
    m_perDist = m_blackboard->inspect("fuelPerDist").data.toDouble();
    m_total   = m_blackboard->inspect("fuelUsage").data.toDouble();
    m_perFuel = m_blackboard->inspect("distPerFuel").data.toDouble();

    updateMode();   // for re-display

    QTimer::singleShot(1000, [this] () { doTimedUpdate(); });
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

    // Initialize the state machine
    m_modeSM->init();

    // When the state machine changes state, update the display (updateMode)
    connect(m_modeSM, &QScxmlStateMachine::reachedStableState,
            this, &FuelUsageDisp::updateMode);

    // start the state machine
    m_modeSM->start();
}
