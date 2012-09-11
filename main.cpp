#include <QtGui>

#include "mainwindow.h"

int main(int argv, char *args[])
{
//    Q_INIT_RESOURCE(diagramscene);

    QApplication app(argv, args);
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
