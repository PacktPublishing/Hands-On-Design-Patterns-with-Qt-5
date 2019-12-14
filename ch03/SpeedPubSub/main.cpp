#include "MainWindow.h"
#include "Speedometer.h"
#include "Vehicle.h"
#include "Broker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    auto broker = new Broker;           // (1) create a broker

    auto speedo = new Speedometer;      // (2) create the speedometer object
    speedo->setBroker(broker);          // (3) tell speedo about broker

    auto vehicle = new Vehicle;         // (4) create the vehicle
    vehicle->setBroker(broker);         // (5) tell broker about vehicle

    w.setCentralWidget(speedo);         // (6) put the speed in the MainWindow
    w.show();                           // (7) show the main window

    return a.exec();                    // (8) set the application
}
