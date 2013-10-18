#include <QtWidgets/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFlags<Qt::WindowType> resultFlag(w.windowFlags());
    //resultFlag &=~(Qt::WindowTitleHint|Qt::WindowSystemMenuHint|Qt::WindowMaximizeButtonHint|Qt::WindowMinimizeButtonHint|Qt::FramelessWindowHint);
    //resultFlag |= Qt::CustomizeWindowHint;
    //w.setWindowFlags(resultFlag);
    //w.setWindowFlags(Qt::CustomizeWindowHint);
    //w.setWindowFlags(Qt::FramelessWindowHint);
    w.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    w.show();

    return a.exec();
}
