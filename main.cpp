#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss("./resources/qss/blue.qss");
    if (qss.open(QFile::ReadOnly))
    {
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }
    //QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    MainWindow w;
    w.show();
//    w.showFullScreen();

    return a.exec();
}
