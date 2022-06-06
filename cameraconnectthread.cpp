#include "cameraconnectthread.h"
#include <QDebug>
#include <QTcpSocket>

CameraConnectThread::CameraConnectThread() :
    m_cameraMedia(NULL),
    pTimerM(new QTimer(this)),
    pTcpTimerM(new QTimer(this)),
    pTcpSocketM(new QTcpSocket(this))
{
    pTimerM->setInterval(2000);
    connect(pTimerM, &QTimer::timeout, this, &CameraConnectThread::onConnectTimeout);

    pTcpTimerM->setInterval(5000);
    connect(pTcpTimerM, &QTimer::timeout, this, &CameraConnectThread::onTcpTimeout);
}

CameraConnectThread::~CameraConnectThread()
{
    qDebug() << "CameraConnectThread::~CameraConnectThread";

    pTimerM->stop();
    pTcpTimerM->stop();

    if(m_cameraMedia->isConnected())
    {
        m_cameraMedia->stopPlay();
        m_cameraMedia->disConnect();
    }
}

void CameraConnectThread::slotStart()
{
    pTimerM->start();
    onConnectTimeout();
}

void CameraConnectThread::slotReStart(QString ipAddress, QString port, QString userName, QString userPwd)
{
    qDebug() << "CameraConnectThread::slotReStart Begin";

    //停止定时器
    pTimerM->stop();
    pTcpTimerM->stop();

    //停止预览 断开连接
    m_cameraMedia->stopPlay();
    m_cameraMedia->disConnect();

    //更换相机ip port usr pwd
    QString oldIpAddress = m_cameraMedia->ipAddress();
    m_cameraMedia->setIpAddress(ipAddress);
    m_cameraMedia->setPort(port);
    m_cameraMedia->setUserName(userName);
    m_cameraMedia->setUserPwd(userPwd);
    if (oldIpAddress != ipAddress)
    {
        //hash表更新
        CameraMediaManager::instance().updateCameraMedia(m_cameraMedia,oldIpAddress,ipAddress,CameraMediaManager::HD_CAMERA);
    }

    //开启定时器
    pTimerM->start();
    onConnectTimeout();

    qDebug() << "CameraConnectThread::slotReStart End";
}

void CameraConnectThread::onConnectTimeout()
{
//    qDebug() << "CameraConnectThread::onConnectTimeout Begin";

    QSignalBlocker blocker(pTimerM);

    if(false == m_cameraMedia->isConnected())
    {
        emit signalLogout();

        int ret = m_cameraMedia->connect();
        if(0 == ret)
        {
            qDebug() << "CameraConnectThread : Connect Camera success !";
            ret = m_cameraMedia->startPlay();
            if(0 == ret)
            {
                qDebug() << "CameraConnectThread : Play Camera success !";

                emit signalLogin();
                pTcpTimerM->start();
            }
            else
            {
                qDebug() << "CameraConnectThread : Play Camera failed ret = !" << ret;
            }
        }
        else
        {
            qDebug() << "CameraConnectThread : Connect Camera failed ret = !" << ret;
            if ((1 == ret) || (153 == ret))
            {
                //do nothing
            }
        }
    }

//    qDebug() << "CameraConnectThread::onConnectTimeout End";
}

void CameraConnectThread::onTcpTimeout()
{
    QSignalBlocker blocker(pTcpTimerM);

    if (m_cameraMedia)
    {
        pTcpSocketM->abort();

        pTcpSocketM->connectToHost(m_cameraMedia->ipAddress(),m_cameraMedia->port().toInt());
        pTcpSocketM->waitForConnected(3000);

//        qDebug() << pTcpSocketM->errorString() << " " << pTcpSocketM->state();

        if (QTcpSocket::UnconnectedState == pTcpSocketM->state())
        {
            qDebug() << "===pTcpSocketM->errorString():" << pTcpSocketM->errorString();

            slotReStart(m_cameraMedia->ipAddress(),m_cameraMedia->port(),m_cameraMedia->userName(),m_cameraMedia->userPwd());
        }
    }
}
