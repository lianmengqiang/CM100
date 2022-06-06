#include "normalform.h"
#include "ui_normalform.h"
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QStringList>
#include <QFont>
#include <QFile>
#include <QTextStream>
#include <QDebug>

NorMalForm::NorMalForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NorMalForm),
    rowCount(0),
    columt(0)
{
    ui->setupUi(this);
    normalInit();
}

NorMalForm::~NorMalForm()
{
    rowCount = 0;
    delete ui;
}

void NorMalForm::on_ptb_cancle_clicked()
{
    this->close();
}

void NorMalForm::on_ptb_firm_clicked()
{
    qDebug()<<"on_ptb_firm_clicked";
    ui->tbw_file->clear();
    QString filePath = QCoreApplication::applicationDirPath() + "/Datafile.txt";
    QFile file(filePath);
    if(!file.exists()){
        qDebug()<<"file  not exist!";
        return;
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"file open fail!";
    }
    rowCount = 0;
    while(!file.atEnd()){
        QString str =file.readLine();
        //qDebug()<<rowCount<<"    str:"<<str<<endl;
        anlysisData(str, rowCount);
        rowCount++;
    }
    qDebug()<<"file close!";
    file.close();



}

void NorMalForm::normalInit()
{
    item = new QTableWidgetItem();
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->tbw_file->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑
    ui->tbw_file->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tbw_file->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->ptb_add->setVisible(false);
    ui->pushButton->setVisible(false);
    //ui->tbw_file->setSelectionMode(QAbstractItemView)



    QTableWidgetItem *item;
    QStringList m_list;
    m_list<<"水平标定量"<<"垂直标定量"<<"端面间距"<<"水平角度标定量"<<"垂直角度标定量";
    //设置表头

    ui->tbw_file->setColumnCount(m_list.count());
    //ui->tbw_file->setHorizontalHeaderLabels(m_list);
    for(int i = 0; i < ui->tbw_file->columnCount(); i++){
        item = new QTableWidgetItem(m_list.at(i));
        QFont f = item->font();
        f.setBold(true);
        f.setPointSize(8);
        item->setTextColor(Qt::black);
        item->setFont(f);
        ui->tbw_file->setHorizontalHeaderItem(i,item);

    }

}
void NorMalForm::anlysisData(QString str, int rowCount)
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
            item->setText(QString(value));
            columt = 0;
        } else if(key == "Dy"){
            item->setText(QString(value));
            columt = 1;
        } else if(key == "dis"){
            item->setText(QString(value));
            columt = 2;
        } else if(key == "Dpitch"){
            item->setText(QString(value));
            columt = 3;
        } else if(key == "Dyaw"){
            item->setText(QString(value));
            columt = 4;
        } else if(key == "Status"){
            continue;
        } else{
        }
        //qDebug()<<rowCount<<"    str:"<<str<<endl;
        //qDebug()<<"("<<rowCount<<", "<<columt<<") "<<value<<endl;
        ui->tbw_file->setItem(rowCount,columt,new QTableWidgetItem(value));
    }

}
