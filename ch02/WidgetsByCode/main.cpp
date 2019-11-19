#include <QApplication>
#include <QMainWindow>
#include <QLabel>

int main(int argc, char *argv[])
{
    // (1) define our Qt (GUI) Application
    QApplication    a(argc, argv);

    // (2) define the window to put the label in
    QMainWindow w;

    auto label = new QLabel;        // (3) create a label
    label->setObjectName("hello");  // (4) assign an id to it
    label->setText("Hello World!"); // (5) set the text of it

    // (6) set the text color by manipulating the palette
    auto palette = label->palette();
    palette.setColor(label->foregroundRole(), Qt::blue);
    label->setPalette(palette);

    // (7) assign the label to the window, w
    w.setCentralWidget(label);

    // (8) show the window
    w.show();

    // (9) start Qt’s event loop and exit when it finishes
    return a.exec();
}
