#include "MainWindow.h"

#include <QApplication>
#include "Speedometer.h"
#include "Vehicle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    auto speedo  = new Speedometer;     // (1) create the speedometer object
    auto vehicle = new Vehicle;         // (2) create the vehicle
    vehicle->registerObserver(speedo);  // (3) register speedo with the vehicle

    w.setCentralWidget(speedo);         // (4) put the speed in the MainWindow
    w.show();                           // (5) show the main window

    return a.exec();                    // (6) run the application
}
