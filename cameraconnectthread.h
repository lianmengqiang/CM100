#ifndef CAMERACONNECTTHREAD_H
#define CAMERACONNECTTHREAD_H

#include <QTimer>
#include <cameramediamgr.h>
#include <cameramedia.h>

class QTcpSocket;
class CameraConnectThread : public QObject
{
    Q_OBJECT
public:
    CameraConnectThread();
    ~CameraConnectThread();
    void            setCameraMedia(CameraMedia*  cameraMedia) { m_cameraMedia = cameraMedia; }

public slots:
    void            slotStart();
    void            slotReStart(QString ipAddress, QString port, QString userName, QString userPwd);
    void            onConnectTimeout();
    void            onTcpTimeout();

signals:
    void            signalLogin();
    void            signalLogout();

private:
    CameraMedia*    m_cameraMedia; //***相机对象指针***//
    QTimer*         pTimerM;
    QTimer*         pTcpTimerM;
    QTcpSocket*     pTcpSocketM;
};
#endif // CAMERACONNECTTHREAD_H
