#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QAbstractSocket>
#include <QDataStream>
#include <QTcpSocket>

class MyClient : public QObject
{
    Q_OBJECT

public:
    MyClient(QObject *parent = 0);
    ~MyClient();

public:
    bool newConnect(QString IP, qint16 Port,int time,int count);
    void sendMessage(QByteArray data_write);
    void sendMessage(const char *data, qint64 len);
    bool getRecvData(int recvTimeOutP);
    void disConnect();
    bool getLinkStatus();

public slots:
    void displayError(QAbstractSocket::SocketError);
    void readMessage();

private:
    bool startConnect();

public:
    QByteArray m_recvData;

private:
    int m_tryCount;//重连次数
    QString m_IP;//连接IP
    qint16 m_port;//连接端口号
    bool m_linkFlag;//连接标志
    int m_waitTime;//接收超时时间
    QTcpSocket *m_tcpSocket;
};

#endif // MYCLIENT_H
