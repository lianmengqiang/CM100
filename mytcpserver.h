#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>

class MyTCPSocket;
class MyTCPServer : public QTcpServer
{
    Q_OBJECT

public:
    MyTCPServer(QObject *parent = nullptr);
    ~MyTCPServer();

    void                        sendMesg(QByteArray mesg);
    void                        sendMesgString(QString mesg);
    void                        sendMesg(QString ip, int port, QByteArray mesg);

    void                        closeConnect();
    void                        closeConnect(QString ip, int port);

signals:
    void                        signRecvData(QString ip, int port, QByteArray mesg);

    void                        signTransData(QByteArray mesg);
    void                        signTransData(QString ip, int port, QByteArray mesg);
    void                        signTransDataString(QString mesg);
    void                        signDisconnect();
    void                        signDisconnect(QString ip, int port);

public slots:
   // void                        slot_StartBase(double va);

protected:
    void                        incomingConnection(qintptr socketDescriptor) override;
};

#endif // MYTCPSERVER_H
