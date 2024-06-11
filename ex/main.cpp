#include "mainwindow.h"

#include <QApplication>

#include <QUiLoader>
#include <QFile>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QColor>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


