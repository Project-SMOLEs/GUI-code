#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QString>
#include <QListView>
#include <QStringListModel>
#include <QStringList>
#include <QFile>
#include <QTextBrowser>
#include <QTextStream>
#include <QMessageBox>
#include <string>
#include <typeinfo>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QFileDialog>
#include <QTimer>
#include <QBluetoothLocalDevice>
#include <QBluetoothAddress>
#include <QBluetoothDeviceInfo>
#include <QGraphicsPixmapItem>
#include <QLowEnergyCharacteristic>
#include <QLowEnergyService>


using namespace std;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    toInstallEventFilter();
    FindFile2(headfilepath);

    scene = new QGraphicsScene(this);//set the scene
    scene->setSceneRect(0,0,600,600);
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->graphicsView->setScene(scene);//add the scene into graphview

    QPixmap pixmap("D:\\GUI\\demo\\ex\\image\\image.png");
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);

    // set the picture position
    item->setPos(50, 50);

    QRectF sceneRect = scene->sceneRect();
    QSizeF sceneSize = sceneRect.size();
    QSize imageSize = pixmap.size();

    qreal scaleX = sceneSize.width() / imageSize.width();
    qreal scaleY = sceneSize.height() / imageSize.height();
    qreal scale = qMin(scaleX, scaleY);
    item->setScale(scale);
    scene->addItem(item);

    RectItemL1 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL1->setBrush(QColor(0,0,255));
    RectItemL2 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL2->setBrush(QColor(0,0,255));
    RectItemL3 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL3->setBrush(QColor(0,0,255));
    RectItemL4 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL4->setBrush(QColor(0,0,255));
    RectItemL5 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL5->setBrush(QColor(0,0,255));
    RectItemL6 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL6->setBrush(QColor(0,0,255));
    RectItemL7 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL7->setBrush(QColor(0,0,255));
    RectItemL8 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL8->setBrush(QColor(0,0,255));
    RectItemL9 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL9->setBrush(QColor(0,0,255));
    RectItemL10 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL10->setBrush(QColor(0,0,255));
    RectItemL11 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL11->setBrush(QColor(0,0,255));
    RectItemL12 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL12->setBrush(QColor(0,0,255));
    RectItemL13 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL13->setBrush(QColor(0,0,255));
    RectItemL14 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL14->setBrush(QColor(0,0,255));
    RectItemL15 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL15->setBrush(QColor(0,0,255));
    RectItemL16 = new QGraphicsRectItem(0, 0, 30, 30);RectItemL16->setBrush(QColor(0,0,255));

    RectItemR1 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR1->setBrush(QColor(0,0,255));
    RectItemR2 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR2->setBrush(QColor(0,0,255));
    RectItemR3 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR3->setBrush(QColor(0,0,255));
    RectItemR4 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR4->setBrush(QColor(0,0,255));
    RectItemR5 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR5->setBrush(QColor(0,0,255));
    RectItemR6 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR6->setBrush(QColor(0,0,255));
    RectItemR7 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR7->setBrush(QColor(0,0,255));
    RectItemR8 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR8->setBrush(QColor(0,0,255));
    RectItemR9 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR9->setBrush(QColor(0,0,255));
    RectItemR10 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR10->setBrush(QColor(0,0,255));
    RectItemR11 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR11->setBrush(QColor(0,0,255));
    RectItemR12 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR12->setBrush(QColor(0,0,255));
    RectItemR13 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR13->setBrush(QColor(0,0,255));
    RectItemR14 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR14->setBrush(QColor(0,0,255));
    RectItemR15 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR15->setBrush(QColor(0,0,255));
    RectItemR16 = new QGraphicsRectItem(0, 0, 30, 30);RectItemR16->setBrush(QColor(0,0,255));//设置传感器图形和其大小、颜色

    scene->addItem(RectItemR1);scene->addItem(RectItemL1);
    scene->addItem(RectItemR2);scene->addItem(RectItemL2);
    scene->addItem(RectItemR3);scene->addItem(RectItemL3);
    scene->addItem(RectItemR4);scene->addItem(RectItemL4);
    scene->addItem(RectItemR5);scene->addItem(RectItemL5);
    scene->addItem(RectItemR6);scene->addItem(RectItemL6);
    scene->addItem(RectItemR7);scene->addItem(RectItemL7);
    scene->addItem(RectItemR8);scene->addItem(RectItemL8);
    scene->addItem(RectItemR9);scene->addItem(RectItemL9);
    scene->addItem(RectItemR10);scene->addItem(RectItemL10);
    scene->addItem(RectItemR11);scene->addItem(RectItemL11);
    scene->addItem(RectItemR12);scene->addItem(RectItemL12);
    scene->addItem(RectItemR13);scene->addItem(RectItemL13);
    scene->addItem(RectItemR14);scene->addItem(RectItemL14);
    scene->addItem(RectItemR15);scene->addItem(RectItemL15);
    scene->addItem(RectItemR16);scene->addItem(RectItemL16);

    RectItemR1->setPos(275,105);RectItemL1->setPos(110,100);//传感器图形位置
    RectItemR2->setPos(335,105);RectItemL2->setPos(170,100);
    RectItemR3->setPos(270,180);RectItemL3->setPos(80,180);
    RectItemR4->setPos(315,180);RectItemL4->setPos(130,180);
    RectItemR5->setPos(370,180);RectItemL5->setPos(180,180);
    RectItemR6->setPos(270,260);RectItemL6->setPos(70,260);
    RectItemR7->setPos(320,260);RectItemL7->setPos(125,260);
    RectItemR8->setPos(380,260);RectItemL8->setPos(180,260);
    RectItemR9->setPos(275,350);RectItemL9->setPos(80,350);
    RectItemR10->setPos(320,350);RectItemL10->setPos(130,350);
    RectItemR11->setPos(370,350);RectItemL11->setPos(170,350);
    RectItemR12->setPos(290,430);RectItemL12->setPos(90,430);
    RectItemR13->setPos(325,430);RectItemL13->setPos(125,430);
    RectItemR14->setPos(360,430);RectItemL14->setPos(165,430);
    RectItemR15->setPos(300,540);RectItemL15->setPos(100,540);
    RectItemR16->setPos(345,540);RectItemL16->setPos(155,540);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::toInstallEventFilter()
{
    ui->pushButton_VISUALIZATION->installEventFilter(this);
    ui->pushButton_2_STOP->installEventFilter(this);
    ui->pushButton_3_Bluetooth->installEventFilter(this);
    ui->pushButton_4_Rocord->installEventFilter(this);
}


bool MainWindow::eventFilter(QObject *target, QEvent *event) //change the buttom form with mouse movemoents
{
    if(target == ui->pushButton_VISUALIZATION)
    {
        if(event->type() == QEvent::HoverEnter)
        {
            ui->pushButton_VISUALIZATION->setStyleSheet("QPushButton#pushButton_VISUALIZATION{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: #e7e7e7;color: black;border: 2px solid #e7e7e7;}");
        }

        if(event->type() == QEvent::HoverLeave)
        {
            ui->pushButton_VISUALIZATION->setStyleSheet("QPushButton#pushButton_VISUALIZATION{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: white;color: black;border: 2px solid #e7e7e7;}");
        }

        if(event->type() == QEvent::MouseButtonPress)
        {
            ui->pushButton_VISUALIZATION->setStyleSheet("QPushButton#pushButton_VISUALIZATION{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: #06AD56;color: black;border: 2px solid #e7e7e7;}");
        }
    }

    if(target == ui->pushButton_2_STOP)
    {
        if(event->type() == QEvent::HoverEnter)
        {
             ui->pushButton_2_STOP->setStyleSheet("QPushButton#pushButton_2_STOP{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: #e7e7e7;color: black;border: 2px solid #e7e7e7;}");
        }

        if(event->type() == QEvent::HoverLeave)
        {
            ui->pushButton_2_STOP->setStyleSheet("QPushButton#pushButton_2_STOP{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: white;color: black;border: 2px solid #e7e7e7;}");
        }

        if(event->type() == QEvent::MouseButtonPress)
        {
            ui->pushButton_2_STOP->setStyleSheet("QPushButton#pushButton_2_STOP{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: #ff0000;color: black;border: 2px solid #e7e7e7;}");
        }
    }

    if(target == ui->pushButton_3_Bluetooth)
    {
        if(event->type() == QEvent::HoverEnter)
        {
             ui->pushButton_3_Bluetooth->setStyleSheet("QPushButton#pushButton_3_Bluetooth{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: #e7e7e7;color: black;border: 2px solid #e7e7e7;}");
        }

        if(event->type() == QEvent::HoverLeave)
        {
            ui->pushButton_3_Bluetooth->setStyleSheet("QPushButton#pushButton_3_Bluetooth{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: white;color: black;border: 2px solid #e7e7e7;}");
        }

        if(event->type() == QEvent::MouseButtonPress)
        {
            ui->pushButton_3_Bluetooth->setStyleSheet("QPushButton#pushButton_3_Bluetooth{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: #00FFFF;color: black;border: 2px solid #e7e7e7;}");
        }
    }

    if(target == ui->pushButton_4_Rocord)
    {
        if(event->type() == QEvent::HoverEnter)
        {
             ui->pushButton_4_Rocord->setStyleSheet("QPushButton#pushButton_4_Rocord{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: #e7e7e7;color: black;border: 2px solid #e7e7e7;}");
        }

        if(event->type() == QEvent::HoverLeave)
        {
            ui->pushButton_4_Rocord->setStyleSheet("QPushButton#pushButton_4_Rocord{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: white;color: black;border: 2px solid #e7e7e7;}");
        }

        if(event->type() == QEvent::MouseButtonPress)
        {
            ui->pushButton_4_Rocord->setStyleSheet("QPushButton#pushButton_4_Rocord{border-radius: 8px;color: white;padding: 16px 32px;text-align: center;text-decoration: none;font-size: 16px;margin: 4px 2px;background-color: #5500ff;color: black;border: 2px solid #e7e7e7;}");
        }
    }

    return false;
}

void MainWindow::on_pushButton_VISUALIZATION_clicked()
{
    jsonObjects.clear();
    for (int i = 0;i < infolist.length() ; i++)
    {
        QString filepath = headfilepath;
        qDebug() << filepath;
        qDebug() << i;
        filepath += infolist.at(i);
        qDebug() << filepath;
        QFile file(filepath);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) //judge whether the file is successfully readed
        {
    //        qDebug() << "Fail to open jsonfile: " << file.errorString();
            QMessageBox::information(0,"info","fail to open!!!");
        }
        QByteArray jsonData = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        QJsonObject jsonObject = jsonDoc.object();
        jsonObjects.append(jsonObject);

        qint64 timeStamp = jsonObject["timeStamp"].toInt();
        bool leftFoot =  jsonObject["leftFoot"].toBool();

        QJsonArray sensordata = jsonObject.value("sensorData").toArray();
        for (qint32 i = 0; i < sensordata.count() ; i++)
        {
            QJsonValue value = sensordata.at(i);
            double result = value.toDouble();
            QString str = QString::number(result,'f', 2);
            int colorvalue = (int)((result / 16.0) * 255);

            if(leftFoot)
            {
                switch (i)
                {
                    case 0: ui->textBrowser_2->setText(str);RectItemL1->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL1);
                    case 1: ui->textBrowser_4->setText(str);RectItemL2->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL2);
                    case 2: ui->textBrowser_6->setText(str);RectItemL3->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL3);
                    case 3: ui->textBrowser_8->setText(str);RectItemL4->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL4);
                    case 4: ui->textBrowser_10->setText(str);RectItemL5->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL5);
                    case 5: ui->textBrowser_12->setText(str);RectItemL6->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL6);
                    case 6: ui->textBrowser_14->setText(str);RectItemL7->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL7);
                    case 7: ui->textBrowser_16->setText(str);RectItemL8->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL8);
                    case 8: ui->textBrowser_18->setText(str);RectItemL9->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL9);
                    case 9: ui->textBrowser_20->setText(str);RectItemL10->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL10);
                    case 10: ui->textBrowser_22->setText(str);RectItemL11->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL11);
                    case 11: ui->textBrowser_24->setText(str);RectItemL12->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL12);
                    case 12: ui->textBrowser_26->setText(str);RectItemL13->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL13);
                    case 13: ui->textBrowser_28->setText(str);RectItemL14->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL14);
                    case 14: ui->textBrowser_30->setText(str);RectItemL15->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL15);
                    case 15: ui->textBrowser_32->setText(str);RectItemL16->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemL16);
                }
            }
            else
            {
                switch (i)
                {
                    case 0: ui->textBrowser->setText(str);RectItemR1->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR1);
                    case 1: ui->textBrowser_3->setText(str);RectItemR2->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR2);
                    case 2: ui->textBrowser_5->setText(str);RectItemR3->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR3);
                    case 3: ui->textBrowser_7->setText(str);RectItemR4->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR4);
                    case 4: ui->textBrowser_9->setText(str);RectItemR5->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR5);
                    case 5: ui->textBrowser_11->setText(str);RectItemR6->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR6);
                    case 6: ui->textBrowser_13->setText(str);RectItemR7->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR7);
                    case 7: ui->textBrowser_15->setText(str);RectItemR8->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR8);
                    case 8: ui->textBrowser_17->setText(str);RectItemR9->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR9);
                    case 9: ui->textBrowser_19->setText(str);RectItemR10->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR10);
                    case 10: ui->textBrowser_21->setText(str);RectItemR11->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR11);
                    case 11: ui->textBrowser_23->setText(str);RectItemR12->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR12);
                    case 12: ui->textBrowser_25->setText(str);RectItemR13->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR13);
                    case 13: ui->textBrowser_27->setText(str);RectItemR14->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR14);
                    case 14: ui->textBrowser_29->setText(str);RectItemR15->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR15);
                    case 15: ui->textBrowser_31->setText(str);RectItemR16->setBrush(QColor(colorvalue,0,255 - colorvalue));scene->addItem(RectItemR16);
                }
            }
        }
        Delay_MSec(1000);
    }
}


void MainWindow::on_pushButton_2_STOP_clicked()
{
    qDebug() << 111;
}


void MainWindow::on_pushButton_3_Bluetooth_clicked()
{
//    MessageBox::information(this, "message", "start scan bluetooth...");//scan bluetooth after click button

}

void MainWindow::on_pushButton_4_Rocord_clicked()
{
    if (jsonObjects.isEmpty()) {
        QMessageBox::information(this, "message", "no json file can be saved");
        return;
    }

    QJsonArray jsonArray;
    for (const QJsonObject &obj : jsonObjects) {
        jsonArray.append(obj);
    }

    QJsonDocument jsonDoc(jsonArray);
    QString filePath = QFileDialog::getSaveFileName(this, "保存 JSON 文件", "", "JSON 文件 (*.json);;所有文件 (*)");

    if (filePath.isEmpty()) {
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "false", "can not save file");
        return;
    }

    file.write(jsonDoc.toJson());
    file.close();
    QMessageBox::information(this, "success", "JSON file saved successful");
}


int MainWindow::FindFile2(const QString& _filePath)
{
    QDir dir(_filePath);

    if (!dir.exists()) {
        return -1;
    }

  //取到所有的文件和文件名，但是去掉.和..的文件夹（这是QT默认有的）
    dir.setFilter(QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot);

    //文件夹优先
    dir.setSorting(QDir::DirsFirst);

    //转化成一个list
    QFileInfoList list = dir.entryInfoList();
    infolist = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
    if(list.size()< 1 ) {
        return -1;
    }
    int i=0;

    //递归算法的核心部分
    do{
        QFileInfo fileInfo = list.at(i);
        //如果是文件夹，递归
        bool bisDir = fileInfo.isDir();
        if(bisDir) {
            FindFile2(fileInfo.filePath());
        }
        else{
            for(int m = 0; m <infolist.size(); m++) { //这里是获取当前要处理的文件名
                qDebug() << infolist.at(m);
            }
            break;
        }//end else
        i++;
    } while(i < list.size());

    return 0;
}

void MainWindow::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}




