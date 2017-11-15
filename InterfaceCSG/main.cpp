#include <QApplication>
#include "mainwindow.h"

#include <iostream>
#include <vector.h>
#include <array.h>
#include <matrix33d.h>
#include <image2d.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	return a.exec();
}
