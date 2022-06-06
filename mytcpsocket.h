#ifndef MYTCPSOCKET
#define MYTCPSOCKET

#include <QTcpSocket>
#include <QDateTime>

class QTimer;
class MyTCPSocket : public QTcpSocket
{
    Q_OBJECT

public:
    MyTCPSocket(qintptr socketDescriptor, QObject *parent = nullptr);
    ~MyTCPSocket();

public slots:
    void        slotReadClientData();

private slots:
    void        slotHeartBeat();
    void        slotCheckHeartBeat();

    void        slotDisConnected();
    void        slotDisConnected(QString ip, int port);

    void        slotTransData(QByteArray mesg);
    void        slotTransDataString(QString mesg);
    void        slotTransData(QString ip, int port, QByteArray mesg);

signals:
    void        signRecvData(QString ip, int port, QByteArray mesg);

private:
    QTimer*     m_heartbeat;
    QDateTime   m_lastTime;
    QByteArray  m_data;
};

#endif // MYTCPSOCKET

