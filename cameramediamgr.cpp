#include <QDebug>
#include "cameramediamgr.h"
#include "cameramedia.h"
#include <QMutexLocker>

#if defined(_WIN32)
void CALLBACK ExceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
#else
void CALLBACK ExceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
#endif
{
    qDebug()<<"ExceptionCallBack dwType = "<<dwType<<",lUserID:"<<lUserID\
                  <<", handle:"<<lHandle<<", user data"<<pUser;
    switch(dwType)
    {
    case EXCEPTION_AUDIOEXCHANGE:
        break;
    case EXCEPTION_ALARM:
        break;
    case EXCEPTION_ALARMRECONNECT:
        break;
    case ALARM_RECONNECTSUCCESS:
        break;
    case EXCEPTION_SERIAL:
        break;
    case EXCEPTION_PREVIEW:
        break;
    case EXCEPTION_RECONNECT:
        break;
    case PREVIEW_RECONNECTSUCCESS:
        break;
    default:
        break;
    }
}

CameraMediaManager::CameraMediaManager()
{
    if (!NET_DVR_Init())
    {
        qDebug() << "CameraMediaManager(). NET_DVR_Init() error.";
    }

    //NET_DVR_SetLogToFile(3, "./sdkLog", false); wdx change
    NET_DVR_SetLogPrint(false);
    //NET_DVR_SetReconnect(10000, 1);
    NET_DVR_SetConnectTime(2000, 1);
    NET_DVR_SetReconnect(10000, true);
    NET_DVR_SetExceptionCallBack_V30(0, NULL, ExceptionCallBack, NULL);
}

CameraMediaManager::~CameraMediaManager()
{

}

CameraMediaManager& CameraMediaManager::instance()
{
    static CameraMediaManager cameraMediaManagerS;
    return cameraMediaManagerS;
}

CameraMedia* CameraMediaManager::createCameraMedia(QString ipAddress, QString port, QString userName, QString userPwd,CameraType cameraType)
{
    CameraMediaInfo * curCameraMediaInfo = NULL;
    CameraMedia*      cameraMedia = NULL;
    if (false == m_CameraMediaHash.contains(ipAddress))
    {
        qDebug()<<"@@@@@@CameraMediaManager:: Firsr Create IP = "<<ipAddress;
        cameraMedia = new CameraMedia(this, ipAddress, port, userName, userPwd);
        curCameraMediaInfo = new CameraMediaInfo();
        curCameraMediaInfo->cameraType = cameraType;
        curCameraMediaInfo->cameraMediaList.append(cameraMedia);
        m_CameraMediaHash.insert(ipAddress, curCameraMediaInfo);
    }
    else
    {
        qDebug()<<"@@@@@@CameraMediaManager:: Multip Create IP = "<<ipAddress;
        curCameraMediaInfo = m_CameraMediaHash.value(ipAddress);
        cameraMedia = new CameraMedia(this, ipAddress, port, userName, userPwd);
        curCameraMediaInfo->cameraMediaList.append(cameraMedia);
    }
    Q_ASSERT(cameraMedia != NULL);

    return cameraMedia;
}

void CameraMediaManager::freeCameraMedia(CameraMedia* pCameraMedia)
{
    CameraMediaInfo * curCameraMediaInfo = NULL;
    if(pCameraMedia == NULL)
    {
        return;
    }
    curCameraMediaInfo = m_CameraMediaHash.value(pCameraMedia->ipAddress());
    if(curCameraMediaInfo)
    {
        curCameraMediaInfo->cameraMediaList.removeOne(pCameraMedia);
        if (curCameraMediaInfo->cameraMediaList.isEmpty())
        {
            qDebug()<<"@@@@@@ List Is Empty ,IP = "<<pCameraMedia->ipAddress();
            m_CameraMediaHash.remove(pCameraMedia->ipAddress());
            delete curCameraMediaInfo;
        }
    }
    delete pCameraMedia;
}

QString  CameraMediaManager::getFirstCameraIp()
{
    QString cameraIP = "";
    QHashIterator<QString, CameraMediaInfo*>hashIter(m_CameraMediaHash);
    while(hashIter.hasNext())
    {
        hashIter.next();
        CameraMediaInfo* info = hashIter.value();
        if (CameraMediaManager::HD_CAMERA == info->cameraType)
        {
            cameraIP = hashIter.key();
            break;
        }
    }

    qDebug() << "CameraMediaManager::getFirstCameraIp cameraIP===" << cameraIP;

    return cameraIP;
}

void CameraMediaManager::updateCameraMedia(CameraMedia *pCameraMedia, QString oldIpAddress, QString newIpAddress, CameraType cameraType)
{
    QMutexLocker locker(&m_mtx);
    //删除旧的
    if (m_CameraMediaHash.contains(oldIpAddress))
    {
        qDebug() << "===remove old===";
        CameraMediaInfo* oldInfo = m_CameraMediaHash.value(oldIpAddress);
        oldInfo->cameraMediaList.removeOne(pCameraMedia);

        if (oldInfo->cameraMediaList.isEmpty())
        {
            qDebug()<<"CameraMediaManager::updateCameraMedia @@@@@@ List Is Empty ,IP = "<<oldIpAddress;
            m_CameraMediaHash.remove(oldIpAddress);
            delete oldInfo;
            oldInfo = NULL;
        }
    }
    //添加新的
    if (m_CameraMediaHash.contains(newIpAddress))
    {
        qDebug() << "===add exist===";
        m_CameraMediaHash.value(newIpAddress)->cameraMediaList.append(pCameraMedia);
    }
    else
    {
        qDebug() << "===add new===";
        CameraMediaInfo *info = new CameraMediaInfo();
        info->cameraType = cameraType;
        info->cameraMediaList.append(pCameraMedia);
        m_CameraMediaHash.insert(newIpAddress, info);
    }
}

CameraMedia* CameraMediaManager::findCameraMedia(QString ipAddress)
{
    CameraMediaInfo * curCameraMediaInfo = m_CameraMediaHash.value(ipAddress);
    CameraMedia*      thisCameraMeida = NULL;

    if(curCameraMediaInfo == NULL)
    {
//        qDebug() << "curCameraMediaInfo == NULL. m_CameraMediaHash.value(ipAddress)";
        return NULL;
    }

    if(!curCameraMediaInfo->cameraMediaList.isEmpty())
    {
        thisCameraMeida = curCameraMediaInfo->cameraMediaList.first();
    }
    return thisCameraMeida;
}

int CameraMediaManager::connectCameraMedia(CameraMedia* pCameraMedia)
{
    Q_UNUSED(pCameraMedia);
    return 0;
}
