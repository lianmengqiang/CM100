#ifndef CAMERAMEDIAMGR_H
#define CAMERAMEDIAMGR_H

#include <QObject>
#include <QHash>
#include <QMutex>

class CameraMedia;

struct CameraMediaInfo
{
    int                   cameraType;
    QList<CameraMedia *>  cameraMediaList;
};

class CameraMediaManager : public QObject
{
    Q_OBJECT
public:

    enum CameraType
    {
        HD_CAMERA = 0,
        INF_CAMERA
    };

    static CameraMediaManager& instance();

    CameraMedia* createCameraMedia(QString ipAddress, QString port, QString userName, QString userPwd, CameraType cameraType = CameraMediaManager::HD_CAMERA);
    void         freeCameraMedia(CameraMedia* pCameraMedia);
    CameraMedia* findCameraMedia(QString ipAddress);
    QString  getFirstCameraIp();
    void updateCameraMedia(CameraMedia* pCameraMedia, QString oldIpAddress, QString newIpAddress, CameraType cameraType);

private:
    int          connectCameraMedia(CameraMedia* pCameraMedia);

private:
    CameraMediaManager();
    ~CameraMediaManager();

    QHash<QString, CameraMediaInfo*> m_CameraMediaHash;
    QMutex m_mtx;
};
#endif // CAMERAMEDIAMGR_H
