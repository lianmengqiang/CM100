#ifndef MYBATTERY_H
#define MYBATTERY_H

#include <QObject>
#include <QTimer>
#include "tcp/MyRecognize.h"
#include "widSetting.h"
class MyBattery : public QObject
{
    Q_OBJECT
public:
    explicit MyBattery(QObject *parent = 0);
    ~MyBattery();

signals:
private:
    QTimer *tBattery;
    MyRecognize *myRecognize;
    widSetting *m_pWidSetting;
    /********串口服务器 电池模块*************/
    QString             m_ComIP;
    int                 m_ComPort;
    bool connectByModusBattery(QString linkIP, int linkPort, int func);

public slots:
    void slotStart();

private slots:
    void slot_startConnectBattery();
    void slotReConnectBattery();
};

#endif // MYBATTERY_H
