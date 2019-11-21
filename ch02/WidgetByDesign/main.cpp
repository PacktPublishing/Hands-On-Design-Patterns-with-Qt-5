#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // (1) create a Widgets application
    MainWindow w;               // (2) create the MainWindow
    w.show();                   // (3) show it
    return a.exec();            // (4) start the application
}
