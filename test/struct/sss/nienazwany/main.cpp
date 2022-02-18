#include "mainwindow.h"
#include <iostream>
#include <vector>
//#include "classs.h"

using namespace std;

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    cout<<"fsdfsfs";
    return a.exec();

}
