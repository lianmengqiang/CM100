#ifndef CAMERAMEDIA_H
#define CAMERAMEDIA_H

#include <QObject>
#ifdef WIN32
#include "hcnetsdk/win32/include/HCNetSDK.h"
#include "hcnetsdk/win32/include/PlayM4.h"
#else
#include "hcnetsdk/linux64/include/HCNetSDK.h"
#include "hcnetsdk/linux64/include/PlayM4.h"
#endif

class CameraMediaManager;
class CameraMedia : public QObject
{
    Q_OBJECT
public:
    CameraMedia(CameraMediaManager *pManager, QString ipAddress, QString port, QString userName, QString userPwd);
    ~CameraMedia();

    void setIpAddress(QString ipAddress) {
        m_ip = ipAddress;
    }

    void setPort(QString port) {
        m_port = port;
    }

    void setUserName(QString userName) {
        m_userName = userName;
    }

    void setUserPwd(QString userPwd) {
        m_userPwd = userPwd;
    }

    int connect();
    int disConnect();
    int setWndHandle(HWND handle);
    int startPlay();
    int stopPlay();
    int pictureCapture(QString path);
    int changeWndSize();

    bool getOpticalZoomLevel(float &rOpticalZoomLevelP);
    bool setOpticalZoomLevel(float opticalZoomLevelP);

    bool getOpticalFocusValue(int &rOpticalFocusValueP);
    bool setOpticalFocusValue(int opticalFocusValueP);

    bool setFocusMode(int iMode);
    bool setRegionFocus(int x1,int y1,int x2,int y2);

    QString ipAddress();
    QString port();
    QString userName();
    QString userPwd();
    bool isConnected();
private:
private:
    QString  convertValueToXml(int focusValue);
    int convertXmlToValue(const char *xmlStr);

private:
    CameraMediaManager* m_pManager;
    QString             m_ip;
    QString             m_port;
    QString             m_userName;
    QString             m_userPwd;
    int                 m_userID;
    HWND                m_hPlayWnd;
    LONG                m_lRealPlayHandle;
    NET_DVR_DEVICEINFO  m_deviceInfo;
};
#endif // CAMERAMEDIA_H
