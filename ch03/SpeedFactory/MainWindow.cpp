#include "MainWindow.h"

#include "ui_MainWindow.h"
#include "Blackboard.h"
#include "FuelUsageDisp.h"
#include "FuelDisplayStateMachine.h"

#include "KnowledgeSourceFactory.h"
#include "FuelUsageCalc.h"
#include "Vehicle.h"
#include "PositionSource.h"
#include "WeatherFetcher.h"

#include "DashWidgetFactory.h"
#include "HeadingIndicator.h"
#include "HighBeamIndicator.h"
#include "HeadlightSwitch.h"
#include "WeatherDisplay.h"

#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto blackboard = new Blackboard;

    // setup the fixed ui components
    ui->speedo->setBlackboard(blackboard);
    ui->odo->setBlackboard(blackboard);

    ui->fuelUsage->setBlackboard(blackboard);
    ui->fuelUsage->setModeSM(new FuelDisplayStateMachine(this));

    ui->throttle->setBlackboard(blackboard);
    ui->throttle->setValue(0);

    // Use KnowledegeSourceFactories to create pure Knowledge Sources
    KnowledgeSourceFactory<Vehicle>::createProduct(blackboard);
    KnowledgeSourceFactory<FuelUsageCalc>::createProduct(blackboard);
    KnowledgeSourceFactory<PositionSource>::createProduct(blackboard);
    KnowledgeSourceFactory<WeatherFetcher>::createProduct(blackboard);

    // use factories to create the DashWidgets
    ui->dashWidgetFrame->setLayout(new QHBoxLayout);
    auto layout = ui->dashWidgetFrame->layout();
    layout->addWidget(DashWidgetFactory<HeadingIndicator>::
                      createProduct(blackboard, this));
    layout->addWidget(DashWidgetFactory<HeadlightSwitch>::
                      createProduct(blackboard, this));
    layout->addWidget(DashWidgetFactory<HighBeamIndicator>::
                      createProduct(blackboard, this));
    layout->addWidget(DashWidgetFactory<WeatherDisplay>::
                      createProduct(blackboard, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

