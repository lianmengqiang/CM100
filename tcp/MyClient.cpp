#include "MyClient.h"
#include <QThread>

MyClient::MyClient(QObject *parent) :
    QObject(parent),
    m_tcpSocket(NULL)
{
    //Client相关初始化
    m_tryCount = 0;
    m_IP = "";
    m_port = 0;
    m_linkFlag = false;
    m_tcpSocket = new QTcpSocket(this);
}

MyClient::~MyClient()
{
    delete m_tcpSocket;
    m_tcpSocket = NULL;
}

bool MyClient::newConnect(QString IP, qint16 Port,int time,int count)
{
    IP = IP.simplified();
    m_IP = IP;
    m_port = Port;
    m_waitTime = time;
    m_linkFlag = false;
    m_tryCount = count;
    m_recvData.clear();
    return startConnect();
}

bool MyClient::startConnect()
{
    int count =0;
    while((count < m_tryCount) && (m_linkFlag == false))
    {
        m_tcpSocket->abort();
        m_tcpSocket->connectToHost(m_IP, m_port);
        count ++;
        m_linkFlag = m_tcpSocket->waitForConnected(m_waitTime);
    }
    if((count >= m_tryCount) && (m_linkFlag == false))
    {
        m_tcpSocket->abort();
        return false;
    }
    return true;
}

void MyClient::disConnect()
{
    if(m_linkFlag)
    {
        m_tcpSocket->abort();
        m_linkFlag = false;
    }
}

bool MyClient::getLinkStatus()
{
    //m_tcpSocket->state();
    return m_linkFlag;
}

void MyClient::displayError(QAbstractSocket::SocketError)
{
    //qDebug()<< "["<<connNameM<<"]"<<"MyClient::displayError(),error:"<<m_tcpSocket->errorString();
    m_tcpSocket->abort();
    m_linkFlag = false;
}

void MyClient::sendMessage(QByteArray sendData)
{
    if (m_tcpSocket == NULL||m_linkFlag == false)
    {
       return;
    }

    m_tcpSocket->write(sendData);
}

void MyClient::sendMessage(const char *data, qint64 len)
{
    if (m_tcpSocket == NULL||m_linkFlag == false)
    {
       return;
    }

    m_tcpSocket->write(data,len);
}

void MyClient::readMessage()
{
    m_recvData = m_tcpSocket->readAll();
}

bool MyClient::getRecvData(int recvTimeOutP)
{
    if (m_tcpSocket->waitForReadyRead(recvTimeOutP))
    {
        m_recvData = m_tcpSocket->readAll();
        return true;
    }
    return false;
}
