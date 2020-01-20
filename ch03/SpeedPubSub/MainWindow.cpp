#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Broker.h"
#include "Vehicle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto broker = new Broker;           // (1) create a broker

    ui->speedo->setBroker(broker);      // (2) tell speedo about broker
    ui->odo->setBroker(broker);         // (3) tell odo about broker

    auto vehicle = new Vehicle;
    vehicle->setBroker(broker);         // (4) tell vehicle about broker
}

MainWindow::~MainWindow()
{
    delete ui;
}

