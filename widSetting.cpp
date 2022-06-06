#include "widSetting.h"
#include "ui_widSetting.h"
#include <QSettings>

#define CFG_PATH    "./cfg.ini"

widSetting::widSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::widSetting)
{
    ui->setupUi(this);
    //保存设置
    connect(ui->pBtnSave, SIGNAL(clicked()), this, SLOT(slotSaveParam()));
    //取消
    connect(ui->pBtnCancel, SIGNAL(clicked()), this, SLOT(slotCancel()));
}

widSetting::~widSetting()
{
    delete ui;
}

void widSetting::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    QSettings set(CFG_PATH, QSettings::IniFormat);
    QString userName    = set.value("/Camera/userName").toString();
    QString password    = set.value("/Camera/password").toString();
    QString cameraIP    = set.value("/Camera/IP").toString();
    QString cameraPort  = set.value("/Camera/Port").toString();
    //工控机
    QString tcpIP       = set.value("/TCP/IP").toString();
    QString tcpPort     = set.value("/TCP/Port").toString();
    //I/O控制器
    QString lowerTcpIP       = set.value("/WLANTCP/IP").toString();
    QString lowerTcpPort     = set.value("/WLANTCP/Port").toString();
    //串口服务器
    QString m_PowerIP    = set.value("/Seriver/IP").toString();
    QString m_PowerPort  = set.value("/Seriver/Port").toString();

    ui->lEditUserName->setText(userName);
    ui->lEditPasswd->setText(password);
    ui->lEditCameraIP->setText(cameraIP);
    ui->lEditCameraPort->setText(cameraPort);
    ui->lEditTCPIP->setText(tcpIP);
    ui->lEditTCPPort->setText(tcpPort);
    ui->led_lowerIP->setText(lowerTcpIP);
    ui->led_lowerPort->setText(lowerTcpPort);
    ui->led_ComIP->setText(m_PowerIP);
    ui->led_ComPort->setText(m_PowerPort);
}
//??
void widSetting::slotSaveParam()
{
    QString userName    = ui->lEditUserName->text();
    QString password    = ui->lEditPasswd->text();
    QString cameraIP    = ui->lEditCameraIP->text();
    QString cameraPort  = ui->lEditCameraPort->text();
    //工控机信息
    QString tcpIP       = ui->lEditTCPIP->text();
    QString tcpPort     = ui->lEditTCPPort->text();
    //i/o信息
    QString lowerTcpIP       = ui->led_lowerIP->text();
    QString lowerTcpPort     = ui->led_lowerPort->text();
    //串口服务器
    QString m_PowerIP    = ui->led_ComIP->text();
    QString m_PowerPort  = ui->led_ComPort->text();


    QSettings set(CFG_PATH, QSettings::IniFormat);
    set.setValue("/Camera/userName", QVariant(userName));
    set.setValue("/Camera/password", QVariant(password));
    set.setValue("/Camera/IP", QVariant(cameraIP));
    set.setValue("/Camera/Port", QVariant(cameraPort));
    set.setValue("/TCP/IP", QVariant(tcpIP));
    set.setValue("/TCP/Port", QVariant(tcpPort));
    set.setValue("/WLANTCP/IP", QVariant(lowerTcpIP));
    set.setValue("/WLANTCP/Port", QVariant(lowerTcpPort));
    set.setValue("/Seriver/IP", QVariant(m_PowerIP));
    set.setValue("/Seriver/Port", QVariant(m_PowerPort));

    emit signReLoginCamera(cameraIP, cameraPort, userName, password);
    emit signReListen(tcpPort.toInt());
    emit signReConnectBattery();

    close();
}
//??
void widSetting::slotCancel()
{
    emit signReConnectBattery();
    close();
}
