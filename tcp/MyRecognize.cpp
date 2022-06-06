#include "MyRecognize.h"
#include <QDebug>
#include <QtCore>
#include "QTextCodec"

/*
 * case 0:"no-mdf"
 * case 1:"mdf"
 * case 2:"识别失败"
 * case 3:"超量程"
 * case -1:"接收失败"
 * case -2:"超时"
 * case -3:"超时"
 * case -4:"建立链接失败"
*/


MyRecognize::MyRecognize(QString IP, int Port,int connectnum, int sendTimeOutMs, int recTimeOutMs):
    myClientM(NULL)
{
    IPM = IP;
    portM = Port;   //28899
    connectNumM = connectnum;
    sendTimeOutM = sendTimeOutMs;   //1s
    recvTimeOutM = 1;  //30s
    myClientM = new MyClient();
    ISConnect = false;

    pCode = QTextCodec::codecForName("gb2312");

}

MyRecognize::~MyRecognize()
{
    delete myClientM;
    myClientM = NULL;
}

bool MyRecognize::connect(QString IP, qint16 Port,int time,int count)
{
    //qDebug()<<"@@@@@@@@@@@@@@@@@@@MyRecognize::connect IP:"<<IP<<"  Port:"<<Port<<"  time:"<<time<<"  count:"<<count;
    return myClientM->newConnect(IP,Port,time,count);
}

int MyRecognize::getResult(QByteArray &rNewResultP)
{
    ISConnect = false;
    if(connect(IPM,28899,sendTimeOutM,connectNumM)==false)
    {
        qDebug()<<"MyRecognize::getResult(), Connected Failed!";
        return LINK_FAILED;
    }
    if(sendArray.size() == 0 ){
        disConnect();
        return SENDARRAYISEMPTY;
    }
    if(!myClientM->getLinkStatus()){
        qDebug()<<"MyClient No Link!";
        return NOLINK_SERVER;
    }

    if(!SendMessageByteArray(sendArray, rNewResultP)){
        disConnect();
        return NOLINK_SERVER;
    }
    ISConnect = true;
    //disConnect();
    //qDebug()<<"MyRecognize::getResult(), Send Success!";
    return SUCCESS;
}

void MyRecognize::disConnect()
{
    ISConnect = false;
    //qDebug()<<"@@@@@@@@@@@@@@@MyRecognize::disconnect";
    myClientM->disConnect();
}

bool MyRecognize::GetConnectedStatus()
{
    return ISConnect;
}

bool MyRecognize::SendMessageByteArray(QByteArray array,QByteArray &rNewResultP)
{
    if(!myClientM->getLinkStatus()){
        qDebug()<<"MyClient No Link!";
        return false;
    }
    qDebug()<<"MyRecognize SendMessageByteArray: "<<array.toHex();
    myClientM->sendMessage(array);


    if( myClientM->getRecvData(recvTimeOutM))
    {
        rNewResultP = myClientM->m_recvData;
        //rNewResultP = pCode->toUnicode(strResult.remove(0,1).data());
        //qDebug()<<"MyRecognize GetResult: "<<rNewResultP.toHex();
        //disConnect();
    }
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<45);  //delay 1s
    return true;
}

bool MyRecognize::setControlFuc(int address, int func)
{
    sendArray.clear();
    sendArray[0] = (0x11);
    sendArray[1] = (0x05);
    sendArray[2] = (0x00);//fasle
    sendArray[3] = (address);  //0red 1green
    if(func == OPEN){
         sendArray[4] = (0xFF);
    } else {
         sendArray[4] = (0x00);
    }
    sendArray[5] = (0x00);
    ModBusCRC16(sendArray,sendArray.size());
    return true;
}

bool MyRecognize::setBatteryFuc(int func)
{
    sendArray.clear();
    sendArray[0] = (0x7F);
    sendArray[1] = (0x10);
    sendArray[2] = (0x02);//fasle
    sendArray[3] = (0x06);
    sendArray[4] = (func);  //0red 1green
    ModBusCRC16(sendArray,sendArray.size());
    return true;
}


void MyRecognize::ModBusCRC16(QByteArray &array, int len){

    ushort i,j,CRC16;
    CRC16 = 0xFFFF;

    for(i = 0; i < len; i++){
        CRC16 = (array[i]&0x00FF) ^ CRC16;
        for(j = 0; j < 8; j++){
            if(CRC16 & 0x0001){
                CRC16 = CRC16 >> 1;
                CRC16 = CRC16 ^ 0xA001;
            } else {
                CRC16 = CRC16 >>1;
            }
        }
    }
    array[6] = (CRC16&0x00FF);
    array[7] = (CRC16&0xFF00)>>8;
}
