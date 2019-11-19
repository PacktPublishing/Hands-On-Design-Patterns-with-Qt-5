#include <QApplication>
#include <QMainWindow>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication    a(argc, argv);

    // define our window with a label
    QMainWindow w;

    auto label = new QLabel;
    label->setObjectName("hello");
    label->setText("Hello World!");

    // set the color
    auto palette = label->palette();
    palette.setColor(label->foregroundRole(), Qt::blue);
    label->setPalette(palette);

    // assign to the window, w
    w.setCentralWidget(label);

    w.show();

    return a.exec();
}
