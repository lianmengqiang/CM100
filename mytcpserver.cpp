#include <QThread>
#include "mytcpserver.h"
#include "mytcpsocket.h"
#include <QString>

MyTCPServer::MyTCPServer(QObject *parent) :
    QTcpServer(parent)
{

}

MyTCPServer::~MyTCPServer()
{

}

void MyTCPServer::incomingConnection(qintptr socketDescriptor)
{
    QThread*        thread  = new QThread;
    MyTCPSocket*    socket  = new MyTCPSocket(socketDescriptor);

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    //通信套接字接受数据
    connect(socket, SIGNAL(signRecvData(QString,int,QByteArray)), this, SIGNAL(signRecvData(QString,int,QByteArray)), Qt::QueuedConnection);
    connect(this, SIGNAL(signTransData(QByteArray)), socket, SLOT(slotTransData(QByteArray)), Qt::QueuedConnection);
    connect(this, SIGNAL(signTransDataString(QString)), socket, SLOT(slotTransDataString(QString)), Qt::QueuedConnection);
    connect(this, SIGNAL(signTransData(QString, int, QByteArray)), socket, SLOT(slotTransData(QString, int, QByteArray)), Qt::QueuedConnection);
    connect(this, SIGNAL(signDisconnect()), socket, SLOT(slotDisConnected()), Qt::QueuedConnection);
    connect(this, SIGNAL(signDisconnect(QString,int)), socket, SLOT(slotDisConnected(QString,int)), Qt::QueuedConnection);

    socket->moveToThread(thread);
    thread->start();
}

void MyTCPServer::sendMesg(QByteArray mesg)
{
    emit signTransData(mesg);
}
void MyTCPServer::sendMesgString(QString mesg)
{
    qDebug()<<"slot_StartBase: Start Base:"<<mesg;
    emit signTransDataString(mesg);
}

void MyTCPServer::sendMesg(QString ip, int port, QByteArray mesg)
{
    emit signTransData(ip, port, mesg);
}

void MyTCPServer::closeConnect()
{
    emit signDisconnect();
}

void MyTCPServer::closeConnect(QString ip, int port)
{
    emit signDisconnect(ip, port);
}
