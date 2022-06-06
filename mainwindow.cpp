#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include "cameraconnectthread.h"
#include <QRect>
#include <QDesktopWidget>
#include <QDebug>
#include <QPalette>
#include <QColor>

#define CFG_PATH    "./cfg.ini"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pWidSetting(NULL),
    m_normalForm(NULL),
    m_cameraMedia(NULL),
    batteryThreadM(nullptr),
    m_myBattery(nullptr),
    m_PowerPort(0),
    m_ComIP(""),
    m_ComPort(0),
    bLowerStatus(nullptr),
    bLedStatus(nullptr),
    bCameraSatus(nullptr),
    IsSave(false),
    myRecognize(nullptr),
    m_timer(nullptr)
{
    ui->setupUi(this);

    mainInit();

    m_pWidSetting   = new widSetting(this);  //设置界面
    m_normalForm = new NorMalForm(this);
    m_server        = new MyTCPServer();  //建立tcp服务器

    //定时器检测电池模块的电量
    m_timer = new QTimer(this);
    m_timer->setInterval(10000);  //10s
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slot_TimeBattery()));
    //m_timer->start();

    //程序界面退出
    connect(ui->actExit, SIGNAL(triggered()), this, SLOT(slotExit()));
    //设计界面显示
    connect(ui->actSetting, SIGNAL(triggered()), this, SLOT(slotSetting()));
    //
    //connect(m_pWidSetting, &widSetting::signReLoginCamera, this, &signalReStart);   //设置界面确定 -- 重新登录相機
    connect(m_pWidSetting, &widSetting::signReListen, this, &slotReListen);         //设置界面确定 -- 重新tcp监听工控机
    //connect(m_pWidSetting, &widSetting::signReConnectBattery, this, &slotReConnectBattery);         //设置界面确定 -- 重新tcp连接串口服务器

    connect(m_server, &MyTCPServer::signRecvData, this, &slotRecvData);           //通信套接字接受数据



    QSettings set(CFG_PATH, QSettings::IniFormat);
    //高清相机信息
    m_userName    = set.value("/Camera/userName").toString();
    m_password    = set.value("/Camera/password").toString();
    m_cameraIP    = set.value("/Camera/IP").toString();
    m_cameraPort  = set.value("/Camera/Port").toString();
    //工控机信息
    m_tcpIP       = set.value("/TCP/IP").toString();
    m_tcpPort     = set.value("/TCP/Port").toString();
    //I/O控制器信息
    m_PowerIP    = set.value("/WLANTCP/IP").toString();
    m_PowerPort  = set.value("/WLANTCP/Port").toInt();
    //(串口服务器)电池模块信息
    m_ComIP    = set.value("/Seriver/IP").toString();
    m_ComPort  = set.value("/Seriver/Port").toInt();

    //相机登录连接
    //cameraLogin();
    //电池监听线程
    batteryLogin();
    //作为服务器监听tcp
    m_server->listen(QHostAddress::AnyIPv4, m_tcpPort.toInt());
    //this->showFullScreen();
}

MainWindow::~MainWindow()
{
    delete myRecognize;
    myRecognize = nullptr;
    delete ui;
}

void MainWindow::mainInit()
{
    ui->frame->installEventFilter(this);
    ui->spb_value->installEventFilter(this);

    this->setWindowTitle(QString("车钩对接工具"));

    //调整主界面网格布局比例系数
    //ui->centralwidget->setRowStretch(0,3);
    //ui->centralwidget->setRowStretch(1,1);
    //ui->centralwidget->setRowStretch(2,1);

    //ui->centralwidget->setColumnStretch(0,1);
    //ui->centralwidget->setColumnStretch(1,1);
    //ui->centralwidget->setColumnStretch(2,1);


    controlInit();


    batteryStu = new QLabel("剩余电量:100%",this);
    ui->statusbar->addWidget(batteryStu);
    ui->statusbar->addWidget(ui->ptb_camStu);

    QDesktopWidget *desktopWidget = QApplication::desktop(); //获取程序的桌面信息
    QRect screenRect = desktopWidget->screenGeometry();
    int screwnX = screenRect.width();//屏幕的宽度
    int screenY = screenRect.height();//屏幕的高度
    //double scaleX = screwnX/1920.0;//此时屏幕宽对比正常1920的倍数
    //double scaleY = screenY/1200.0;//此时屏幕高对比正常1080的倍数
    //然后按照倍数去移动位置以及调整大小
    //ui->widgetMain->move(452*scaleX, 180*scaleY);//(452，180)是1920*1080屏幕上的坐标
   // ui->MainWindow->resize(1920*scaleX, 1200*scaleY);//1013和681是1920*1080屏幕上的宽和高
   // this->resize(screwnX, screenY);
    this->showMaximized();
    //this->move(0,0);


    DirPath = QCoreApplication::applicationDirPath();
    qDebug()<<DirPath<<endl;

}

void MainWindow::controlInit()
{
    ui->ptb_lower->setEnabled(false);
    ui->ptb_lower->setVisible(false);

    ui->lab_status->setAutoFillBackground(true);
    ui->spb_value->setMouseTracking(true);
    changePalette(ui->lab_status, QColor(Qt::GlobalColor::green));

    QSettings set(CFG_PATH, QSettings::IniFormat);
    bLowerStatus    = set.value("/WLANTCP/LowerStatus").toBool();
    bLedStatus  = set.value("/WLANTCP/LedStatus").toBool();
    bCameraSatus  = set.value("/WLANTCP/CameraStatus").toBool();

    //后期需要采用配置文件记录状态值
    ui->ptb_lower->setCheckable(true);
    ui->ptb_led->setCheckable(true);
    ui->ptb_std->setCheckable(true);
    ui->ptb_std->setText(QString("开始标定"));

    if(bLowerStatus){
        //ui->ptb_lower->setText(QString("系统通电"));
        ui->act_lower->setText(QString("系统通电"));
        ui->act_lower->setChecked(true);
        //ui->ptb_lower->setChecked(true);
    } else{
        ui->act_lower->setText(QString("系统断电"));
        ui->act_lower->setChecked(false);
    }
    if(bLedStatus){
        ui->ptb_led->setText(QString("关灯"));
        ui->ptb_led->setChecked(true);
    } else{
        ui->ptb_led->setText(QString("开灯"));
        ui->ptb_led->setChecked(false);
    }
    if(bCameraSatus){
        ui->act_camera->setText(QString("相机断电"));
        ui->act_camera->setChecked(true);
    } else{
        ui->act_camera->setText(QString("相机通电"));
        ui->act_camera->setChecked(false);
    }



   // openKey();
}

void MainWindow::writeDate(QString str)
{

}

void MainWindow::changePalette(QWidget *w, QColor acolor)
{
    QPalette p = w->palette();
    p.setColor(QPalette::Background,acolor);
    w->setPalette(p);
}

void MainWindow::updatelable(bool flag)
{
    if(!flag){
        ui->lab_dx->setText(QString("水平偏移量:"));
        ui->lab_dy->setText(QString("垂直偏移量:"));
        ui->label_dis->setText(QString("端面距离:"));
        ui->lab_dxa->setText(QString("水平角度偏移量:"));
        ui->label_dya->setText(QString("垂直角度偏移量:"));
    }else{
        ui->lab_dx->setText(QString("水平标定量:"));
        ui->lab_dy->setText(QString("垂直标定量:"));
        ui->label_dis->setText(QString("端面标定距离:"));
        ui->lab_dxa->setText(QString("水平角度标定量:"));
        ui->label_dya->setText(QString("垂直角度标定量:"));
    }
}

void MainWindow::updateBattery(QByteArray array)
{
    if((QString::number(array.at(4),16) == QString::number(0x18,16) &&(array.size() < 11))){
       return;
    }
    qDebug()<<"2电池电量**"<<" "<<QString::number(array.at(0)&0xFF,16)<<" "
           <<QString::number(array.at(1)&0xFF,16)<<" "
          <<QString::number(array.at(2)&0xFF,16)<<" "
         <<QString::number(array.at(3)&0xFF,16)<<" "
        <<QString::number(array.at(4)&0xFF,16)<<" "
       <<QString::number(array.at(5)&0xFF,16)<<" "
      <<QString::number(array.at(6)&0xFF,16)<<" "
     <<QString::number(array.at(7)&0xFF,16)<<" "
    <<QString::number(array.at(8)&0xFF,16)<<" "
    <<QString::number(array.at(9)&0xFF,16)<<" "
    <<QString::number(array.at(10)&0xFF,16)<<" "
    <<QString::number(array.at(11)&0xFF,16)<<" "<<"\n";

    int soc = ((array.at(7))&0xFF);
    soc |= (array.at(8)<<8)&0xFF00;
    int Ssoc = (array.at(9))&0xFF;
    Ssoc |= (array.at(10)<<10)&0xFF00;
    int pre = (float)soc/(float)Ssoc*100;
    qDebug()<<"SOC**"<<" "<<soc/10<<" "<<Ssoc/10<<"  SUM:"<< pre;
    batteryStu->setText(QString::number(pre,10) + "%");
}

void MainWindow::openKey()
{
    //The code from david!!!
    PVOID OldValue;
    BOOL bRet = Wow64DisableWow64FsRedirection (&OldValue);
    QString csProcess="C:\\Windows\\System32\\osk.exe";
    QString params="";
    ShellExecute(NULL, L"open", (LPCWSTR)csProcess.utf16(), (LPCWSTR)params.utf16(), NULL, SW_SHOWNORMAL);
    if ( bRet )
    {
        Wow64RevertWow64FsRedirection(OldValue);
    }
}

//相机登录
void MainWindow::cameraLogin()
{
    if (NULL == m_cameraMedia)
    {
        //创建相机对象
        m_cameraMedia = CameraMediaManager::instance().createCameraMedia(m_cameraIP, m_cameraPort, m_userName, m_password);
        m_cameraMedia->setWndHandle((HWND)ui->frame->winId());

        //创建相机连接线程
        CameraConnectThread *pCameraThread = new CameraConnectThread();
        pCameraThread->setCameraMedia(m_cameraMedia);
        pCameraThread->moveToThread(&connectThreadM);

        //绑定信号
        connect(&connectThreadM, &QThread::started, pCameraThread, &CameraConnectThread::slotStart);//线程启动
        connect(this, &signalReStart, pCameraThread, &CameraConnectThread::slotReStart);//线程重新启动
        connect(&connectThreadM, &QThread::finished, pCameraThread, &CameraConnectThread::deleteLater);//线程退出
        connect(pCameraThread, &CameraConnectThread::signalLogin, this, &slotHikvisionLogin);//相机登入
        connect(pCameraThread, &CameraConnectThread::signalLogout, this, &slotHikvisionLogout);//相机登出
        connectThreadM.start();

//        //创建相机任务线程
//        CameraTaskThread *pCameraTaskThread = new CameraTaskThread();
//        pCameraTaskThread->setCameraMedia(m_cameraMedia);
//        pCameraTaskThread->moveToThread(&taskThreadM);

//        //绑定信号
//        connect(&taskThreadM, &QThread::started, pCameraTaskThread, &CameraTaskThread::slotStart);//线程启动
//        connect(&taskThreadM, &QThread::finished, pCameraTaskThread, &CameraTaskThread::deleteLater);//线程退出
//        connect(this, SIGNAL(signal_setPTZ2Center(quint32)), pCameraTaskThread, SLOT(slot_setPTZ2Center(quint32)));//控制相机云台在鼠标双击时移动至该鼠标点
//        connect(pCameraTaskThread, SIGNAL(signal_PTZInDstPositon()), this, SLOT(slot_PTZInRightPositon()));//相机云台移动结束
//        taskThreadM.start();
    }
}
//相机登出
void MainWindow::cameraLogout()
{
    if( m_cameraMedia != NULL )
    {
        connectThreadM.quit();
        connectThreadM.wait();
        CameraMediaManager::instance().freeCameraMedia(m_cameraMedia);
        m_cameraMedia = NULL;
    }
}

void MainWindow::batteryLogin()
{
    m_myBattery = new MyBattery();
    batteryThreadM  = new QThread(this);
    m_myBattery->moveToThread(batteryThreadM);

    //绑定信号
    connect(batteryThreadM, QThread::started, m_myBattery, MyBattery::slotStart);//线程启动
    //connect(this, &signalReStart, pCameraThread, &CameraConnectThread::slotReStart);//线程重新启动
    connect(batteryThreadM, QThread::finished, m_myBattery, MyBattery::deleteLater);//线程退出
    batteryThreadM->start();
}

void MainWindow::batteryLogout()
{
    batteryThreadM->quit();
    batteryThreadM->wait();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{

}

bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->frame) {  //过滤对象
        //QMouseEvent *ev = static_case<QMouseEvent *>(e);
        if(e->type() == QEvent::MouseButtonDblClick){  //过滤事件
            QDesktopWidget *desktopWidget = QApplication::desktop(); //获取程序的桌面信息
            QRect screenRect = desktopWidget->screenGeometry();
            int screwnX = screenRect.width();//屏幕的宽度
            int screenY = screenRect.height();//屏幕的高度

            //ui->frame->resize(screwnX, screenY);
           // ui->frame->showMaximized();
            ui->frame->showFullScreen();
            //布局隐藏
            for (int i = 0; i < ui->gridLayout->count(); ++i) {
                QWidget* w = ui->gridLayout->itemAt(i)->widget();
                if (w != NULL)
                    w->setVisible(false);
            }

            return true;
        } else if(e->type() == QEvent::MouseButtonPress){  //过滤事件

            ui->frame->showNormal();
            //布局隐藏
            for (int i = 0; i < ui->gridLayout->count(); ++i) {
                QWidget* w = ui->gridLayout->itemAt(i)->widget();
                if (w != NULL)
                    w->setVisible(true);
            }
             //openKey();
            return true;
        }
        return false;
    } else if(obj == ui->spb_value){

        if(e->type() == QEvent::MouseMove){  //过滤事件
            openKey();
            return true;
        }
        return false;
    }
}

void MainWindow::slotExit()
{
    cameraLogout();
    batteryLogin();
    qApp->quit();
}
//参数信息设置界面显示
void MainWindow::slotSetting()
{
    if(m_timer->isActive()){
         m_timer->stop();
    }
    m_pWidSetting->exec();
}

void MainWindow::slotHikvisionLogin()
{
    ui->frame->setUpdatesEnabled(false);
}

void MainWindow::slotHikvisionLogout()
{
    ui->frame->setUpdatesEnabled(true);
    repaint();
}
//服务器接受客户端传输数据，可以进行解析处理
void MainWindow::slotRecvData(QString ip, int port, QByteArray data)
{
    if(ip == m_PowerIP){
        return;
    }
    m_connectIP     = ip;
    m_connectPort   = port;
    qDebug()<<"/*********接受数据***************/"<<endl;
    QByteArray array = data;
    qDebug()<<"**"<<" "<<array.toHex()<<"\n";
    //qDebug()<<"---"<<QString::number(array.at(0)&0xff,16)<<endl;
    /*
    qDebug()<<"**"<<" "<<QString::number(array.at(0)&0xFF,16)<<" "
           <<QString::number(array.at(1)&0xFF,16)<<" "
          <<QString::number(array.at(2)&0xFF,16)<<" "
         <<QString::number(array.at(3)&0xFF,16)<<" "
        <<QString::number(array.at(4)&0xFF,16)<<" "
       <<QString::number(array.at(5)&0xFF,16)<<" "
      <<QString::number(array.at(6)&0xFF,16)<<" "
     <<QString::number(array.at(7)&0xFF,16)<<" "
    <<QString::number(array.at(8)&0xFF,16)<<" "
    <<QString::number(array.at(9)&0xFF,16)<<" "
    <<QString::number(array.at(10)&0xFF,16)<<" "
    <<QString::number(array.at(11)&0xFF,16)<<" "
    <<QString::number(array.at(12)&0xFF,16)<<" "<<"\n";*/

    if(QString::number(array.at(0),16) == QString::number(0x7f,16)){
        qDebug()<<"/*********A电池数据7F***************/"<<endl;
        updateBattery(array);
    } else if(QString::number(array.at(0),16) == QString::number(0x44,16)) {
        updateControl(data);
        //qDebug()<<"is save"<<IsSave;
        qDebug()<<"/*********B标定数据44***************/"<<endl;
        if(IsSave){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy_MM_dd_HH_mm_ss");
            QTextStream stream(&file);

            stream<<"**"<<currentTime <<", "<<data<<"\n";
            file.flush();
        }
    } else {
        qDebug()<<"/*********C无效数据***************/"<<endl;
    }

}

void MainWindow::slotReListen(int port)
{
    if (m_server->isListening())
    {
        m_server->close();
        m_server->closeConnect(m_connectIP, m_connectPort);
    }

    m_server->listen(QHostAddress::AnyIPv4, port);
}

//设置界面确定 -- 重新tcp连接串口服务器
void MainWindow::slotReConnectBattery()
{
    QSettings set(CFG_PATH, QSettings::IniFormat);
    m_ComIP    = set.value("/Seriver/IP").toString();
    m_ComPort  = set.value("/Seriver/Port").toInt();
    if(!m_timer->isActive()){
         m_timer->start();
    }
}

//解析tcp传输数据
void MainWindow::updateControl(QString str)
{
    if(str.isEmpty()){
        return;
    }
    QStringList list = str.split(",");
    foreach (QString var, list) {
        QString     key = var.trimmed().section(":",0,0);
        QString     value = var.trimmed().section(":",1,1);
        if(value == ""){
            value = "--";
        }
        if(key == "ID"){

        } else if (key == "Dx"){
            ui->lab_dxValue->setText(value);
        } else if(key == "Dy"){
            ui->lab_dyValue->setText(value);
        } else if(key == "dis"){
            ui->lab_disValue->setText(value);
            if((file.isOpen()) && ((value.toDouble() > 30)&& (value.toDouble() < 200))){
                //file.close();
                IsSave = true;
                //qDebug()<<"dis <=30, file close"<<value.toInt();
                //updatelable(IsSave);
                //ui->ptb_std->setText(QString("开启标定"));
                //ui->ptb_std->setCheckable(true);
            } else {
                IsSave = false;
            }
        } else if(key == "Dpitch"){
            ui->lab_dxaValue->setText(value);
        } else if(key == "Dyaw"){
            ui->lab_dyaValue->setText(value);
        } else if(key == "Status"){
            if(value == "true"){
                ui->lab_status->setText(QString("可挂载"));
                changePalette(ui->lab_status, QColor(Qt::GlobalColor::red));
            } else if(value == "false"){
                ui->lab_status->setText(QString("不可挂载"));
                changePalette(ui->lab_status, QColor(Qt::GlobalColor::green));
            }
        } else{

        }

    }
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->label_2->setText(currentTime);
}

//开始标定
void MainWindow::on_ptb_std_clicked()
{
    if(ui->ptb_std->isChecked()){
        qDebug()<<"open"<<endl;

        QMessageBox w(QMessageBox::Question,"标定控制","是否开启标定",QMessageBox::Ok|QMessageBox::Close);
        if(w.exec() == QMessageBox::Close){
            ui->ptb_std->setChecked(false);
            return;
        }

        IsSave = true;
        updatelable(IsSave);
        ui->ptb_std->setText(QString("关闭标定"));
        ui->ptb_std->setChecked(true);
        QDir DataFile;
        if(DataFile.exists(DirPath)){
            QString currentTime = QDateTime::currentDateTime().toString("yyyy_MM_dd_HH_mm_ss");
            filePath = DirPath + "/Datafile.txt";
            file.setFileName(filePath);
            if(file.exists()){
                file.remove();
            }
            if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
            {
                qDebug()<<"file open fail!";
            }
        }
        double baseValue = ui->spb_value->text().toDouble();
        qDebug()<<"on_ptb_std_clicked: Start Base:"<<baseValue;
        QString str = "Calib:true, Threshold:"+ QString("%1").arg(baseValue);
        m_server->sendMesgString(str);
    } else if(!ui->ptb_std->isChecked()){
        qDebug()<<"close"<<endl;
        IsSave = false;
        updatelable(IsSave);
        ui->ptb_std->setText(QString("开启标定"));
        ui->ptb_std->setChecked(false);
        if(file.isOpen()){
            file.close();
        }
    }
}

void MainWindow::on_actFile_triggered()
{
     m_normalForm->show();
}
//开启低功耗  按钮
void MainWindow::on_ptb_lower_clicked()
{
    QSettings set(CFG_PATH, QSettings::IniFormat);
    m_PowerIP    = set.value("/WLANTCP/IP").toString();
    m_PowerPort  = set.value("/WLANTCP/Port").toInt();
    qDebug()<<"*********低功耗开关(按钮), IP:"<<m_PowerIP<<", Port:"<<m_PowerPort;
    if(ui->ptb_lower->isChecked()){ 
        if(connectByModus(m_PowerIP, m_PowerPort, LOWER_CONTROL, true)){
            qDebug()<<"alread open Lower";
            set.setValue("/WLANTCP/LowerStatus", QVariant(true));
        } else {
            ui->ptb_lower->setChecked(false);
            return;
        }
        ui->ptb_lower->setText(QString("系统通电"));
        ui->ptb_lower->setChecked(true);

    } else if(!ui->ptb_lower->isChecked()){
        if(connectByModus(m_PowerIP, m_PowerPort, LOWER_CONTROL, false)){
            qDebug()<<"alread close Lower";
            set.setValue("/WLANTCP/LowerStatus", QVariant(false));
        } else {
            ui->ptb_lower->setChecked(true);
            return;
        }
        ui->ptb_lower->setText(QString("系统断电"));
        ui->ptb_lower->setChecked(false);
    }
}


//I/O控制器 按钮
void MainWindow::on_ptb_led_clicked()
{

    QSettings set(CFG_PATH, QSettings::IniFormat);
    m_PowerIP    = set.value("/WLANTCP/IP").toString();
    m_PowerPort  = set.value("/WLANTCP/Port").toInt();
    qDebug()<<"*********照明灯开关(按钮), IP:"<<m_PowerIP<<", Port:"<<m_PowerPort;
    if(ui->ptb_led->isChecked()){
        if(connectByModus(m_PowerIP, m_PowerPort, LED_CONTROL, true)){
            qDebug()<<"alread open led";
            set.setValue("/WLANTCP/LedStatus", QVariant(true));
        } else {
            ui->ptb_led->setChecked(false);
            return;
        }
        ui->ptb_led->setText(QString("关灯"));
        ui->ptb_led->setChecked(true);
    } else if(!ui->ptb_led->isChecked()){
        if(connectByModus(m_PowerIP, m_PowerPort, LED_CONTROL, false)){
            qDebug()<<"alread close led";
            set.setValue("/WLANTCP/LedStatus", QVariant(false));
        } else {
            ui->ptb_led->setChecked(true);
            return;
        }
        ui->ptb_led->setText(QString("开灯"));
        ui->ptb_led->setChecked(false);
    }
}
//发送阀值
void MainWindow::on_pushButton_clicked()
{
    double baseValue = ui->spb_value->text().toDouble();
    qDebug()<<"on_ptb_std_clicked: Start Base:"<<baseValue;
    QString str = "Calib:false, Threshold:"+ QString("%1").arg(baseValue);
    m_server->sendMesgString(str);
}


//低功耗 I/O控制器 动作
void MainWindow::on_act_lower_triggered()
{
    QSettings set(CFG_PATH, QSettings::IniFormat);
    m_PowerIP    = set.value("/WLANTCP/IP").toString();
    m_PowerPort  = set.value("/WLANTCP/Port").toInt();
   qDebug()<<"*********低功耗开关(动作), IP:"<<m_PowerIP<<", Port:"<<m_PowerPort;
    if(ui->act_lower->isChecked()){
        if(connectByModus(m_PowerIP, m_PowerPort, LOWER_CONTROL, true)){
            qDebug()<<"alread open Lower";
            set.setValue("/WLANTCP/LowerStatus", QVariant(true));
        } else {
            ui->act_lower->setChecked(false);
            return;
        }
        ui->act_lower->setChecked(true);
        ui->act_lower->setText("系统通电");

    } else if(!ui->act_lower->isChecked()){
        if(connectByModus(m_PowerIP, m_PowerPort, LOWER_CONTROL, false)){
            qDebug()<<"alread close Lower";
            set.setValue("/WLANTCP/LowerStatus", QVariant(false));
        } else {
            ui->act_lower->setChecked(true);
            return;
        }
        ui->act_lower->setChecked(false);
        ui->act_lower->setText("系统断电");
    }
}


//发送I/O 低功耗控制器控制协议
bool MainWindow::connectByModus(QString linkIP, int linkPort, int address, bool IsOPen)
{
    qDebug()<<"*********I/O控制器, IP:"<<linkIP<<", Port:"<<linkPort;
    int ret = 0;
    QByteArray newResult;
    myRecognize = new MyRecognize(linkIP,linkPort);
    //address  00 01 02 03
    if(IsOPen){
        (void)myRecognize->setControlFuc(address, MyRecognize::OPEN);
    } else{
        (void)myRecognize->setControlFuc(address, MyRecognize::CLOSE);
    }
    ret = myRecognize->getResult(newResult);
    if( ret != 0){
        qDebug()<<"MainWindow::connectByModus(), Send Fail "<< ret;
        delete myRecognize;
        myRecognize = nullptr;
        return false;
    }

    if(myRecognize->GetConnectedStatus()){
        myRecognize->disConnect();
    } else {
        qDebug()<<"MainWindow::connectByModus(), not link ";
    }

    delete myRecognize;
    myRecognize = nullptr;
    return true;
}

//发送I/O 串口服务器控制器控制协议
bool MainWindow::connectByModusBattery(QString linkIP, int linkPort, int func)
{
    qDebug()<<"*********串口服务, IP:"<<linkIP<<", Port:"<<linkPort;
    int ret = 0;
    QByteArray newResult;
    myRecognize = new MyRecognize(linkIP,linkPort);
    (void)myRecognize->setBatteryFuc(func);
    ret = myRecognize->getResult(newResult);
    if( ret != 0){
        qDebug()<<"MainWindow::connectByModus(), Send Fail "<< ret;
        delete myRecognize;
        myRecognize = nullptr;
        return false;
    }

    if(myRecognize->GetConnectedStatus()){
        myRecognize->disConnect();
    } else {
        qDebug()<<"MainWindow::connectByModus(), not link ";
    }

    delete myRecognize;
    myRecognize = nullptr;
    return true;
}

//相机通断动作
void MainWindow::on_act_camera_triggered()
{
    QSettings set(CFG_PATH, QSettings::IniFormat);
    m_PowerIP    = set.value("/WLANTCP/IP").toString();
    m_PowerPort  = set.value("/WLANTCP/Port").toInt();
    qDebug()<<"*********相机通断电(动作), IP:"<<m_PowerIP<<", Port:"<<m_PowerPort;
    if(ui->act_camera->isChecked()){
        if(connectByModus(m_PowerIP, m_PowerPort, CAMERA_CONTROL, false)){
            qDebug()<<"alread open camera";
            set.setValue("/WLANTCP/CameraStatus", QVariant(false));
        } else {
            ui->act_camera->setChecked(false);
            return;
        }
        ui->act_camera->setChecked(true);
        ui->act_camera->setText("相机通电");


    } else if(!ui->act_camera->isChecked()){
        if(connectByModus(m_PowerIP, m_PowerPort, CAMERA_CONTROL, true)){
            qDebug()<<"alread close camera";
            set.setValue("/WLANTCP/CameraStatus", QVariant(true));
        } else {
            ui->act_camera->setChecked(true);
            return;
        }
        ui->act_camera->setChecked(false);
        ui->act_camera->setText("相机断电");
    }
}

//刷新界面  --重连相机/工控机
void MainWindow::on_ptb_camStu_clicked()
{
    QSettings set(CFG_PATH, QSettings::IniFormat);
    m_userName    = set.value("/Camera/userName").toString();
    m_password    = set.value("/Camera/password").toString();
    m_cameraIP    = set.value("/Camera/IP").toString();
    m_cameraPort  = set.value("/Camera/Port").toString();
    m_tcpIP       = set.value("/TCP/IP").toString();
    m_tcpPort     = set.value("/TCP/Port").toString();

    //相机登录连接
    cameraLogin();
    //作为服务器监听tcp
    m_server->listen(QHostAddress::AnyIPv4, m_tcpPort.toInt());
}

void MainWindow::slot_TimeBattery()
{
    //QSettings set(CFG_PATH, QSettings::IniFormat);
    //m_PowerIP    = set.value("/Seriver/IP").toString();
    //m_PowerPort  = set.value("/Seriver/Port").toInt();
    if(connectByModusBattery(m_PowerIP, m_PowerPort, 24)){
        qDebug()<<"alread send battery";
    } else {
        return;
    }
}
