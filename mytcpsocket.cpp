#include <QTimer>
#include <QDataStream>
#include <QDebug>
#include <QHostAddress>
#include "mytcpsocket.h"
#include <QMessageBox>

#define HEARTBEAT   30000

MyTCPSocket::MyTCPSocket(qintptr socketDescriptor, QObject* parent):
    QTcpSocket(parent)
{
    if (!setSocketDescriptor(socketDescriptor))
    {
        qDebug() << "[" << peerAddress() << ":" << peerPort() << "] " << errorString();
        deleteLater();
    }

    m_heartbeat = new QTimer(this);
    m_heartbeat->setInterval(HEARTBEAT);

    m_lastTime  = QDateTime::currentDateTime();

    connect(this, SIGNAL(readyRead()), this, SLOT(slotHeartBeat()));
    connect(this, SIGNAL(readyRead()), this, SLOT(slotReadClientData()));  //有数据信号 -- 通信套接字接受数据
    connect(this, SIGNAL(disconnected()), this, SLOT(slotDisConnected()));
    connect(m_heartbeat, SIGNAL(timeout()), this, SLOT(slotCheckHeartBeat()));

    m_data.clear();

    m_heartbeat->start();
}

MyTCPSocket::~MyTCPSocket()
{

}

void MyTCPSocket::slotHeartBeat()
{
    if (!m_heartbeat->isActive())
    {
        m_heartbeat->start();
    }

    m_lastTime = QDateTime::currentDateTime();
}

void MyTCPSocket::slotCheckHeartBeat()
{
    //妫�娴嬫帀绾匡紝鏂紑杩炴帴
    if (m_lastTime.secsTo(QDateTime::currentDateTime()) >= (HEARTBEAT / 1000))
    {
        qDebug() << "hearbeat timeout, [" << peerAddress().toString() << ":" << peerPort() << "] will disconnect!";
        m_heartbeat->stop();
//        disconnectFromHost();
    }
}

void MyTCPSocket::slotDisConnected()
{
    disconnectFromHost();
    waitForDisconnected();
    qDebug() << "[" << peerAddress() << ":" << peerPort() << "] disconnect...";
    deleteLater();
}

void MyTCPSocket::slotDisConnected(QString ip, int port)
{
    if (ip == peerAddress().toString() && port == peerPort())
    {
        slotDisConnected();
    }
    else
    {
        return;
    }
}
//通信套接字接受数据
void MyTCPSocket::slotReadClientData()
{
    m_data = readAll();

    if (!m_data.isEmpty())
    {
        emit signRecvData(peerAddress().toString(), peerPort(), m_data);

        //qDebug() << "recv info from[" << peerAddress().toString() << "]:" << m_data;
        m_data.clear();
    }
}

void MyTCPSocket::slotTransData(QByteArray mesg)
{
    write(mesg);
    waitForBytesWritten();
}

void MyTCPSocket::slotTransDataString(QString mesg)
{
    qDebug()<<"Start Base:"<<mesg;
    const char *data = mesg.toStdString().c_str();
    write(data);
    waitForBytesWritten();
}

void MyTCPSocket::slotTransData(QString ip, int port, QByteArray mesg)
{
    if (ip == peerAddress().toString() && port == peerPort())
    {
        slotTransData(mesg);
    }
    else
    {
        return;
    }
}
