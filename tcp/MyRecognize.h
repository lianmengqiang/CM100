#ifndef MYRECOGNIZE_H
#define MYRECOGNIZE_H

#include <QObject>
#include "tcp/MyClient.h"
#include <QThread>
#include <QByteArray>

//using namespace Core;
class MyRecognize : public QObject
{
    Q_OBJECT

public:
    MyRecognize(QString IP, int Port,int connectnum = 5, int sendTimeOutMs = 1000, int recTimeOutMs = 3000);
    ~MyRecognize();

public:
    int getResult(QByteArray &rNewResultP);
    bool setControlFuc(int address, int func);
    bool setBatteryFuc(int func);
    void disConnect();
    bool GetConnectedStatus();

private:

    bool connect(QString IP, qint16 Port,int time,int count);
    void ModBusCRC16(QByteArray &array, int len);
    bool SendMessageByteArray(QByteArray array,QByteArray &rNewResultP);

private:
    QString IPM;//连接IP
    qint16 portM;//连接端口号
    int connectNumM;//连接次数
    int sendTimeOutM;//发送超时时间
    int recvTimeOutM;//接收超时时间
    MyClient *myClientM;
    QByteArray sendArray;
    bool ISConnect;

    QThread *thread;
    QTextCodec *pCode;


public:

    enum
    {
        SUCCESS=0,
        LINK_FAILED=1,
        NOLINK_SERVER=2,
        SENDARRAYISEMPTY=3,
    };
    enum
    {
        RED=0,
        GREEN=1,
    };
    enum
    {
        CLOSE=0,
        OPEN=1,
    };
};

#endif // MYRECOGNIZE_H
