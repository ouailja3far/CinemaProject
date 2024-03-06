#include "loginwindow.h"
#include "RegisterWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RegisterWindow w;
    w.show();
    return a.exec();
}
