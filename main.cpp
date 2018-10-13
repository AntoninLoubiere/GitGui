#include "main_window.h"
#include <QApplication>

#include <QDebug>

#include <status_getter.h>

#ifdef Q_OS_UNIX
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
#endif
