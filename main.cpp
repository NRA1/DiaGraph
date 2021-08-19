#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *win = new MainWindow;
    win->show();
    return app.exec();
}
