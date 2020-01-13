#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Blackboard.h"
#include "Vehicle.h"
#include "FuelUsageCalc.h"
#include "FuelUsageDisp.h"
#include "FuelDisplayStateMachine.h"

#include "DashWidgetFactory.h"
#include "HeadingIndicator.h"
#include "HighBeamIndicator.h"
#include "HeadlightSwitch.h"

#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto blackboard = new Blackboard;           // (1) create a Blackboard

    ui->speedo->setBlackboard(blackboard);      // (2) tell speedo about Blackboard
    ui->odo->setBlackboard(blackboard);         // (3) tell odo about Blackboard

    auto vehicle = new Vehicle;
    vehicle->setBlackboard(blackboard);         // (4) tell Blackboard about vehicle

    auto fcalc = new FuelUsageCalc;
    fcalc->setBlackboard(blackboard);

    ui->fuelUsage->setBlackboard(blackboard);
    ui->fuelUsage->setModeSM(new FuelDisplayStateMachine(this));

    ui->throttle->setBlackboard(blackboard);
    ui->throttle->setValue(0);

    // use factories to create the DashWidgets
    ui->dashWidgetFrame->setLayout(new QHBoxLayout);
    auto layout = ui->dashWidgetFrame->layout();
    layout->addWidget(DashWidgetFactory<HeadingIndicator>::
                      createProduct(blackboard, this));
    layout->addWidget(DashWidgetFactory<HeadlightSwitch>::
                      createProduct(blackboard, this));
    layout->addWidget(DashWidgetFactory<HighBeamIndicator>::
                      createProduct(blackboard, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

