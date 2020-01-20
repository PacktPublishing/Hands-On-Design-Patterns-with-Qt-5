#include "MainWindow.h"
#include "Speedometer.h"
#include "Odometer.h"
#include "Vehicle.h"
#include "Broker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
