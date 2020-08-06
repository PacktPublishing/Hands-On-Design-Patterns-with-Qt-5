#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // these identify the application (for QSettings)
    a.setOrganizationName("Packt");
    a.setApplicationName("SpeedFactory");

    MainWindow w;
    w.show();
    return a.exec();
}
