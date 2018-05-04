#include "myspinwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mySPINWindow w;
    w.setStyleSheet("mySPINWindow {background: 'black';}");
    w.show();

    w.start_qmyspin();

    return a.exec();
}
