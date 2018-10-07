#include "mainwindow.h"
#include <QApplication>

#include <statusgetter.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    StatusGetter sg;

    sg.runStatusCommand();

    return a.exec();
}
