//#include <QMessageBox>
#include <QDebug>
#include "cameramedia.h"
//#include <QTextCodec>
#include <QXmlStreamWriter>

CameraMedia::CameraMedia(CameraMediaManager *pManager, QString ipAddress, QString port, QString userName, QString userPwd):
    m_userID(-1),
    m_hPlayWnd(0),
    m_lRealPlayHandle(0)
{
    m_pManager = pManager;
    m_ip       = ipAddress;
    m_port     = port;
    m_userName = userName;
    m_userPwd  = userPwd;
}

CameraMedia::~CameraMedia()
{

}

bool CameraMedia::isConnected()
{
    return (NET_DVR_RemoteControl(m_userID,NET_DVR_CHECK_USER_STATUS,NULL,0) == TRUE) ? true : false;
}

int CameraMedia::connect()
{
    DWORD   error = 0;
    QByteArray  ucUserName = m_userName.toLatin1();
    QByteArray  ucUserPwd  = m_userPwd.toLatin1();
    QByteArray  ucIpaddr   = m_ip.toLatin1();
    int         port       = m_port.toInt();

    //qDebug() << ucUserName << ", " << ucUserPwd << ", " << ucIpaddr;

    m_userID = NET_DVR_Login((char*)ucIpaddr.data(), port, (char*)ucUserName.data(), (char*)ucUserPwd.data(), &m_deviceInfo);
    if(m_userID < 0)
    {
        error = NET_DVR_GetLastError();
        qDebug()<< "connect() : NET_DVR_Login fail : m_userID < 0 m_isConnect = false error =" <<error;
        return error;
    }

    return NET_DVR_NOERROR;
}

int CameraMedia::disConnect()
{
    if(isConnected() == true)
    {
       NET_DVR_Logout(m_userID);
    }

    m_userID = -1;
    return NET_DVR_NOERROR;
}

int CameraMedia::setWndHandle(HWND handle)
{
    m_hPlayWnd = handle;
    return NET_DVR_NOERROR;
}

int CameraMedia::startPlay()
{
    NET_DVR_SCALECFG  scaleCfg;

    if(isConnected() != true)
    {
        return NET_DVR_NETWORK_FAIL_CONNECT;
    }

    NET_DVR_GetScaleCFG_V30(m_userID, &scaleCfg);
    scaleCfg.dwMajorScale = 1;
    scaleCfg.dwMinorScale = 1;
    NET_DVR_SetScaleCFG_V30(m_userID, &scaleCfg);

    NET_DVR_PREVIEWINFO struPlayInfo;
    memset(&struPlayInfo, 0, sizeof(struPlayInfo));
    struPlayInfo.hPlayWnd     = m_hPlayWnd;         //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
    struPlayInfo.lChannel     = 1;       //预览通道号
    struPlayInfo.dwStreamType = 0;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
    struPlayInfo.dwLinkMode   = 0;       //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP
    struPlayInfo.byProtoType = 0;    //应用层取流协议，0-私有协议，1-RTSP协议
    struPlayInfo.byPreviewMode = 0;    //预览模式，0-正常预览，1-延迟预览
    struPlayInfo.byVideoCodingType = 0; //码流数据编解码类型 0-通用编码数据 1-热成像探测器产生的原始数据（温度数据的加密信息，通过去加密运算，将原始数据算出真实的温度值）
    struPlayInfo.dwDisplayBufNum = 50; //播放库播放缓冲区最大缓冲帧数，范围1-50，置0时默认为1
    m_lRealPlayHandle = NET_DVR_RealPlay_V40(m_userID, &struPlayInfo, NULL,NULL);

//    NET_DVR_CLIENTINFO clientinfo;
//    clientinfo.lChannel     = 1;
//    clientinfo.lLinkMode    = 0;
//    clientinfo.sMultiCastIP = 0;
//    clientinfo.hPlayWnd     = m_hPlayWnd;

//    PlayM4_GetLastError(0);

//    m_lRealPlayHandle = NET_DVR_RealPlay_V30(m_userID, &clientinfo, NULL,NULL,1);
    if (m_lRealPlayHandle < 0)
    {
        qDebug()<< "startPlay() : m_lRealPlayHandle < 0 "<<m_lRealPlayHandle;
        return NET_DVR_GetLastError();
    }
    return NET_DVR_NOERROR;
}

int CameraMedia::stopPlay()
{
    if(isConnected() != true)
    {
        return NET_DVR_NETWORK_FAIL_CONNECT;
    }

    if(m_lRealPlayHandle < 0)
    {
        qDebug()<< "stopPlay() : m_lRealPlayHandle < true "<<m_lRealPlayHandle;
        return NET_DVR_PARAMETER_ERROR;
    }

    NET_DVR_StopRealPlay(m_lRealPlayHandle);

    m_lRealPlayHandle = -1;
    return NET_DVR_NOERROR;
}

int CameraMedia::pictureCapture(QString path)
{
    int              iRet = 0;
    NET_DVR_JPEGPARA strPicPara;
#ifdef WIN32
    QByteArray     picPath = path.toLocal8Bit();
#else
    QByteArray     picPath = path.toUtf8();
#endif

    if(isConnected() != true)
    {
        return NET_DVR_NETWORK_FAIL_CONNECT;
    }

    strPicPara.wPicQuality = 0;
    strPicPara.wPicSize = 0;
//    qDebug() << "pictureCapture :NET_DVR_CaptureJPEGPicture m_userID = %d " <<m_userID;
//    qDebug() << "pictureCapture :NET_DVR_CaptureJPEGPicture m_deviceInfo.byStartChan = %d " <<m_deviceInfo.byStartChan;
//    qDebug() << "pictureCapture :NET_DVR_CaptureJPEGPicture wPicQuality = %d " <<strPicPara.wPicQuality;
//    qDebug() << "pictureCapture :NET_DVR_CaptureJPEGPicture wPicSize = %d " <<strPicPara.wPicSize;
//    qDebug() << "pictureCapture :NET_DVR_CaptureJPEGPicture picPath.data() = %s " <<path;
    iRet = NET_DVR_CaptureJPEGPicture(m_userID, m_deviceInfo.byStartChan, &strPicPara, (char*)picPath.data());
    if (!iRet)
    {
        qDebug() << "pictureCapture :NET_DVR_CaptureJPEGPicture iRet = " <<iRet;
        qDebug() << "pictureCapture :NET_DVR_CaptureJPEGPicture Errno = " <<NET_DVR_GetLastError();
        return NET_DVR_GetLastError();
    }
    return NET_DVR_NOERROR;
}


int CameraMedia::changeWndSize()
{
    if(isConnected() != true)
    {
        return NET_DVR_NETWORK_FAIL_CONNECT;
    }

    if(m_lRealPlayHandle < 0)
    {
        return NET_DVR_PARAMETER_ERROR;
    }
#ifdef WIN32
//    NET_DVR_ChangeWndResolution(m_lRealPlayHandle);  //linux系统下的接口
#else
      NET_DVR_ChangeWndResolution(m_lRealPlayHandle);
#endif
    return NET_DVR_NOERROR;
}

bool CameraMedia::getOpticalZoomLevel(float &rOpticalZoomLevelP)
{
    bool retVal = false;
    DWORD dwRetVal = -1;

    NET_DVR_FOCUSMODE_CFG focusModeCfg;
    retVal = NET_DVR_GetDVRConfig(m_userID, NET_DVR_GET_FOCUSMODECFG, m_deviceInfo.byStartChan, &focusModeCfg, sizeof(NET_DVR_FOCUSMODE_CFG), &dwRetVal);
    if (retVal == false)
    {
        qDebug() << "CameraMedia::getOpticalZoomLevel(), failed to call NET_DVR_GetDVRConfig.error code:"<<NET_DVR_GetLastError();;
        return false;
    }

    rOpticalZoomLevelP = focusModeCfg.fOpticalZoomLevel;
    return true;
}

int CameraMedia::convertXmlToValue(const char *xmlStr)
{
    QXmlStreamReader xmlReader(xmlStr);
    while (!xmlReader.atEnd() && !xmlReader.hasError())
    {
        if (xmlReader.name() == "FocusPos")
        {
            QString elementText = xmlReader.readElementText();
            return elementText.toInt();
        }
        xmlReader.readNext();
     }

    return 0;
}

bool CameraMedia::getOpticalFocusValue(int &rOpticalFocusValueP)
{
    std::string strCommand("GET /ISAPI/PTZCtrl/channels/1/FocusDirect");
    NET_DVR_XML_CONFIG_INPUT struInputParam;
    memset(&struInputParam, 0, sizeof(struInputParam));
    struInputParam.dwSize = sizeof(struInputParam);
    struInputParam.lpRequestUrl = (char *)(strCommand.c_str());
//    qDebug()<<"struInputParam.lpRequestUrl"<<(char *)struInputParam.lpRequestUrl;
    struInputParam.dwRequestUrlLen = strCommand.length();

    char szStatusBuff[1024]={0};
    char pOutputXmlBuffer[512] = {0};
    NET_DVR_XML_CONFIG_OUTPUT strOutputParm;
    memset(&strOutputParm, 0, sizeof(strOutputParm));
    strOutputParm.dwSize = sizeof(strOutputParm);
    strOutputParm.lpOutBuffer = pOutputXmlBuffer;
    strOutputParm.dwOutBufferSize = sizeof(pOutputXmlBuffer);
    strOutputParm.lpStatusBuffer = szStatusBuff;
    strOutputParm.dwStatusSize = sizeof(szStatusBuff);

    if (NET_DVR_STDXMLConfig(m_userID,&struInputParam,&strOutputParm) != TRUE)
    {
        qDebug()<<"getFocus error,error code:"<<NET_DVR_GetLastError();
        return false;
    }

    rOpticalFocusValueP = convertXmlToValue((char *)strOutputParm.lpOutBuffer);
    return true;
}

bool CameraMedia::setOpticalZoomLevel(float opticalZoomLevelP)
{
    bool retVal = false;

    DWORD dwRetVal = -1;
    NET_DVR_FOCUSMODE_CFG focusModeCfg;
    retVal = NET_DVR_GetDVRConfig(m_userID, NET_DVR_GET_FOCUSMODECFG, m_deviceInfo.byStartChan, &focusModeCfg, sizeof(NET_DVR_FOCUSMODE_CFG), &dwRetVal);
    if (retVal == false)
    {
        qDebug() << "CameraMedia::getOpticalZoomLevel(), failed to call NET_DVR_GetDVRConfig.";
        return false;
    }

    focusModeCfg.fOpticalZoomLevel = opticalZoomLevelP;
    retVal = NET_DVR_SetDVRConfig(m_userID, NET_DVR_SET_FOCUSMODECFG, m_deviceInfo.byStartChan, &focusModeCfg, sizeof(NET_DVR_FOCUSMODE_CFG));
    if (retVal == false)
    {
        qDebug() << "CameraMedia::setOpticalZoomLevel(), failed to call NET_DVR_SetDVRConfig.";
        return retVal;
    }

//    float opticalZoomLevel = 0;
//    getOpticalZoomLevel(opticalZoomLevel);
//    if (opticalZoomLevel != opticalZoomLevelP )
//    {
//        return false;
//    }

    return retVal;
}

QString CameraMedia::convertValueToXml(int focusValue)
{
    char valueStr[10] = {0};
    sprintf(valueStr, "%d", focusValue);

    QString xmlStr("");
    QXmlStreamWriter stream(&xmlStr);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();

    stream.writeStartElement("FocusDirectList");
    stream.writeAttribute("version", "2.0");
    stream.writeAttribute("xmlns", "http://www.hikvision.com/ver20/XMLSchema");
    stream.writeTextElement("FocusPos", valueStr);
    stream.writeEndElement();

    stream.writeEndDocument();

    return xmlStr;
}

bool CameraMedia::setOpticalFocusValue(int opticalFocusValueP)
{
    char inputBuffer[512] = {0};
    QString xmlString = convertValueToXml(opticalFocusValueP);
    strncpy(inputBuffer, xmlString.toStdString().c_str(), strlen(xmlString.toStdString().c_str()));

    std::string strCommand("PUT /ISAPI/PTZCtrl/channels/1/FocusDirect");
    NET_DVR_XML_CONFIG_INPUT struInputParam;
    memset(&struInputParam, 0, sizeof(struInputParam));
    struInputParam.dwSize = sizeof(struInputParam);
    struInputParam.lpRequestUrl = (void *)(strCommand.c_str());
    struInputParam.dwRequestUrlLen = strCommand.length();
    struInputParam.lpInBuffer = inputBuffer;
    struInputParam.dwInBufferSize = strlen(inputBuffer);

    char szStatusBuff[1024] = {0};
    NET_DVR_XML_CONFIG_OUTPUT struOutputParam;
    memset(&struOutputParam, 0, sizeof(struOutputParam));
    struOutputParam.dwSize = sizeof(struOutputParam);
    struOutputParam.lpStatusBuffer = szStatusBuff;
    struOutputParam.dwStatusSize = sizeof(szStatusBuff);

    if (NET_DVR_STDXMLConfig(m_userID, &struInputParam, &struOutputParam) != TRUE)
    {
        qDebug()<<"setFocus error,error code:"<<NET_DVR_GetLastError();
        return false;
    }
//    int   opticalFocusValue;
//    getOpticalFocusValue(opticalFocusValue);
//    if (opticalFocusValue != opticalFocusValueP)
//    {
//        return false;
//    }
    return true;
}

bool CameraMedia::setFocusMode(int iMode)
{
    NET_DVR_FOCUSMODE_CFG config;
    memset(&config,0x00,sizeof(config));
    DWORD dw = 0;
    NET_DVR_GetDVRConfig(m_userID, NET_DVR_GET_FOCUSMODECFG, 1, LPVOID(&config), sizeof(config), &dw);
    config.byFocusMode = iMode;
    bool bRtn = NET_DVR_SetDVRConfig(m_userID, NET_DVR_SET_FOCUSMODECFG, 1, LPVOID(&config), sizeof(config));
    return bRtn;
}

bool CameraMedia::setRegionFocus(int x1, int y1, int x2, int y2)
{
    char buffer_xml[512] = {0};
    NET_DVR_XML_CONFIG_INPUT struInput;
    NET_DVR_XML_CONFIG_OUTPUT struOuput;
    memset(&struInput,0x00,sizeof(struInput));
    memset(&struOuput,0x00,sizeof(struOuput));
    struInput.dwSize = sizeof(struInput);
    struInput.lpRequestUrl = (void*)"PUT /ISAPI/Image/channels/1/regionalFocus";
    struInput.dwRequestUrlLen = strlen("PUT /ISAPI/Image/channels/1/regionalFocus");
    sprintf(buffer_xml, "<RegionalFocus>"
        "<StartPoint>"
        "<positionX>%d</positionX>"
        "<positionY>%d</positionY>"
        "</StartPoint>"
        "<EndPoint>"
        "<positionX>%d</positionX>"
        "<positionY>%d</positionY>"
        "</EndPoint>"
        "</RegionalFocus>", x1, y1, x2, y2);
    struInput.lpInBuffer = buffer_xml;
    struInput.dwInBufferSize = 512;
    struInput.dwSize = sizeof(struInput);
    struOuput.dwSize = sizeof(struOuput);
    return NET_DVR_STDXMLConfig(m_userID, &struInput, &struOuput);
}

QString CameraMedia::ipAddress()
{
    return m_ip;
}

QString CameraMedia::port()
{
    return m_port;
}

QString CameraMedia::userName()
{
    return m_userName;
}

QString CameraMedia::userPwd()
{
    return m_userPwd;
}
