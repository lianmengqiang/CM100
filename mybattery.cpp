#include "mybattery.h"
#include <QSettings>

#define CFG_PATH    "./cfg.ini"

MyBattery::MyBattery(QObject *parent) : QObject(parent)
{
    tBattery = nullptr;
    myRecognize = nullptr;
    m_pWidSetting = nullptr;
    /********串口服务器 电池模块*************/
    m_ComIP = "";
     m_ComPort = 0;

    m_pWidSetting   = new widSetting();  //设置界面
    connect(m_pWidSetting, &widSetting::signReConnectBattery, this, &slotReConnectBattery);         //设置界面确定 -- 重新tcp连接串口服务器



    QSettings set(CFG_PATH, QSettings::IniFormat);
    //(串口服务器)电池模块信息
    m_ComIP    = set.value("/Seriver/IP").toString();
    m_ComPort  = set.value("/Seriver/Port").toInt();


    tBattery = new QTimer(this);
    tBattery->setInterval(10000);  //10s
    connect(tBattery, SIGNAL(timeout()), this, SLOT(slot_startConnectBattery()));

}

MyBattery::~MyBattery()
{
    disconnect(tBattery, SIGNAL(timeout()), this, SLOT(slot_startConnectBattery()));
    if(tBattery->isActive()){
        tBattery->stop();
    }

    delete myRecognize;
    myRecognize = nullptr;

    delete m_pWidSetting;
    m_pWidSetting = nullptr;
}

void MyBattery::slot_startConnectBattery()
{
    if(connectByModusBattery(m_ComIP, m_ComPort, 24)){
        qDebug()<<"alread send battery";
    } else {
        return;
    }
}
//发送I/O 串口服务器控制器控制协议
bool MyBattery::connectByModusBattery(QString linkIP, int linkPort, int func)
{
    qDebug()<<"*********串口服务, IP:"<<linkIP<<", Port:"<<linkPort;
    int ret = 0;
    QByteArray newResult;
    myRecognize = new MyRecognize(linkIP,linkPort);
    (void)myRecognize->setBatteryFuc(func);
    ret = myRecognize->getResult(newResult);
    if( ret != 0){
        qDebug()<<"MainWindow::connectByModus(), Send Fail "<< ret;
        delete myRecognize;
        myRecognize = nullptr;
        return false;
    }

    if(myRecognize->GetConnectedStatus()){
        myRecognize->disConnect();
    } else {
        qDebug()<<"MainWindow::connectByModus(), not link ";
    }

    delete myRecognize;
    myRecognize = nullptr;
    return true;
}

void MyBattery::slotStart()
{
    tBattery->start();
}

//设置界面确定 -- 重新tcp连接串口服务器
void MyBattery::slotReConnectBattery()
{
    QSettings set(CFG_PATH, QSettings::IniFormat);
    m_ComIP    = set.value("/Seriver/IP").toString();
    m_ComPort  = set.value("/Seriver/Port").toInt();
}


