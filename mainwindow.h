#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "widSetting.h"
#include "normalform.h"
#include "cameramedia.h"
#include "cameramediamgr.h"
#include "mytcpserver.h"
#include <QMap>
#include <QTime>
#include <dbt.h>
#include <QFile>
#include <QDir>
#include <QDataStream>
#include <QLabel>
#include <QMessageBox>
#include <windows.h>
#include "tcp/MyRecognize.h"
#include <QTimer>
#include "mybattery.h"
#pragma comment(lib,"user32.lib")
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void                cameraLogin();
    void                cameraLogout();

    void                batteryLogin();
    void                batteryLogout();

signals:
    void                signalReStart(QString ipAddress, QString port, QString userName, QString userPwd);
    void                signalStartBase(double va);

protected:
    //鼠标双击事件
    void mouseDoubleClickEvent(QMouseEvent *e);
    //事件过滤器
    virtual bool eventFilter(QObject *obj, QEvent *e) override;
private slots:
    void                slotExit();
    void                slotSetting();

    void                slotHikvisionLogin();
    void                slotHikvisionLogout();

    void                slotRecvData(QString ip, int port, QByteArray data);
    void                slotReListen(int port);
    void                slotReConnectBattery();

    void on_ptb_std_clicked();

    void on_actFile_triggered();

    void on_ptb_lower_clicked();
    void on_ptb_led_clicked();

    void on_pushButton_clicked();

    void on_act_lower_triggered();

    void on_act_camera_triggered();

    void on_ptb_camStu_clicked();

    void slot_TimeBattery();

private:
    void updateControl(QString str);
    void mainInit();
    void controlInit();
    void writeDate(QString str);

    void changePalette(QWidget *w, QColor acolor);
    void updatelable(bool flag);
    void updateBattery(QByteArray array);

    bool connectByModus(QString linkIP, int linkPort, int address, bool IsOPen);
    bool connectByModusBattery(QString linkIP, int linkPort, int func);

    void openKey();

    Ui::MainWindow*     ui;
    widSetting*         m_pWidSetting;
    NorMalForm         *m_normalForm;
    CameraMedia*        m_cameraMedia;
    QThread             connectThreadM;  //***显示连接线程***//

    QThread             *batteryThreadM;   //电池获取线程
    MyBattery           *m_myBattery;

    MyTCPServer*        m_server;

    QString             m_userName;
    QString             m_password;
    QString             m_cameraIP;
    QString             m_cameraPort;
    QString             m_tcpIP;
    QString             m_tcpPort;
    QTimer *m_timer;

    /********低功耗 I/O控制器*************/
    QString             m_PowerIP;
    int                 m_PowerPort;
    /********串口服务器 电池模块*************/
    QString             m_ComIP;
    int                 m_ComPort;

    bool                bLowerStatus;
    bool                bLedStatus;
    bool                bCameraSatus;


    QString             m_connectIP;
    int                 m_connectPort;
    bool                IsSave;

    QFile                 file;
    QString             DirPath;
    QString             filePath;
    QLabel              *batteryStu;
    MyRecognize *myRecognize;

    enum{
        LOWER_CONTROL = 0,
        LED_CONTROL = 1,
        CAMERA_CONTROL = 2,
    };
};

#endif // MAINWINDOW_H
