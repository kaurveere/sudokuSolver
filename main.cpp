#include "mainwindow.h"

#include <QApplication>

// Starts the application
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
