#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QFileDialog>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>
#include <QBluetoothLocalDevice>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void toInstallEventFilter();
    bool eventFilter(QObject *target, QEvent *event);

    QGraphicsScene *scene;
    QGraphicsRectItem *RectItemR1;
    QGraphicsRectItem *RectItemR2;
    QGraphicsRectItem *RectItemR3;
    QGraphicsRectItem *RectItemR4;
    QGraphicsRectItem *RectItemR5;
    QGraphicsRectItem *RectItemR6;
    QGraphicsRectItem *RectItemR7;
    QGraphicsRectItem *RectItemR8;
    QGraphicsRectItem *RectItemR9;
    QGraphicsRectItem *RectItemR10;
    QGraphicsRectItem *RectItemR11;
    QGraphicsRectItem *RectItemR12;
    QGraphicsRectItem *RectItemR13;
    QGraphicsRectItem *RectItemR14;
    QGraphicsRectItem *RectItemR15;
    QGraphicsRectItem *RectItemR16;

    QGraphicsRectItem *RectItemL1;
    QGraphicsRectItem *RectItemL2;
    QGraphicsRectItem *RectItemL3;
    QGraphicsRectItem *RectItemL4;
    QGraphicsRectItem *RectItemL5;
    QGraphicsRectItem *RectItemL6;
    QGraphicsRectItem *RectItemL7;
    QGraphicsRectItem *RectItemL8;
    QGraphicsRectItem *RectItemL9;
    QGraphicsRectItem *RectItemL10;
    QGraphicsRectItem *RectItemL11;
    QGraphicsRectItem *RectItemL12;
    QGraphicsRectItem *RectItemL13;
    QGraphicsRectItem *RectItemL14;
    QGraphicsRectItem *RectItemL15;
    QGraphicsRectItem *RectItemL16;

    int FindFile2(const QString& _filePath);
    void Delay_MSec(unsigned int msec);

    ~MainWindow();

private slots:
    void on_pushButton_VISUALIZATION_clicked();
    void on_pushButton_2_STOP_clicked();

    void on_pushButton_3_Bluetooth_clicked();
    void on_pushButton_4_Rocord_clicked();

private:
    Ui::MainWindow *ui;

    QString headfilepath = "D:\\GUI\\demo\\ex\\sensordata\\";
    QStringList infolist;
    QVector<QJsonObject> jsonObjects; // to store json data


};
#endif // MAINWINDOW_H
