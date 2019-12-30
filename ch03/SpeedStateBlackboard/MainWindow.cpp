#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Blackboard.h"
#include "Vehicle.h"
#include "Controller.h"
#include "FuelUsageCalc.h"
#include "FuelUsageDisp.h"
#include "FuelDisplayStateMachine.h"

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

    auto controller = new Controller(this);
    controller->setBlackboard(blackboard);
    controller->setSpeedo(ui->speedo);
    controller->setOdo(ui->odo);
    controller->setFuelUsageCalc(fcalc);
    controller->setFuelUsageDisp(ui->fuelUsage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

