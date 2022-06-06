/********************************************************************************
** Form generated from reading UI file 'widSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDSETTING_H
#define UI_WIDSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_widSetting
{
public:
    QGridLayout *gridLayout_3;
    QPushButton *pBtnCancel;
    QPushButton *pBtnSave;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lEditUserName;
    QLabel *label_2;
    QLineEdit *lEditPasswd;
    QLabel *label_3;
    QLineEdit *lEditCameraIP;
    QLabel *label_4;
    QLineEdit *lEditCameraPort;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *lEditTCPIP;
    QLabel *label_6;
    QLineEdit *lEditTCPPort;
    QGroupBox *groupBox_3;
    QLabel *label_9;
    QLabel *label_7;
    QLineEdit *led_lowerIP;
    QLineEdit *led_lowerPort;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QLabel *label_8;
    QLineEdit *led_ComIP;
    QLineEdit *led_ComPort;

    void setupUi(QDialog *widSetting)
    {
        if (widSetting->objectName().isEmpty())
            widSetting->setObjectName(QStringLiteral("widSetting"));
        widSetting->resize(1000, 600);
        widSetting->setMinimumSize(QSize(0, 0));
        widSetting->setMaximumSize(QSize(1000, 600));
        widSetting->setSizeIncrement(QSize(1920, 1200));
        gridLayout_3 = new QGridLayout(widSetting);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pBtnCancel = new QPushButton(widSetting);
        pBtnCancel->setObjectName(QStringLiteral("pBtnCancel"));
        pBtnCancel->setMinimumSize(QSize(100, 30));
        pBtnCancel->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pBtnCancel->setFont(font);

        gridLayout_3->addWidget(pBtnCancel, 3, 4, 1, 1);

        pBtnSave = new QPushButton(widSetting);
        pBtnSave->setObjectName(QStringLiteral("pBtnSave"));
        pBtnSave->setMinimumSize(QSize(100, 30));
        pBtnSave->setMaximumSize(QSize(16777215, 16777215));
        pBtnSave->setFont(font);

        gridLayout_3->addWidget(pBtnSave, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(183, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 3, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        groupBox = new QGroupBox(widSetting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        groupBox->setFont(font1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lEditUserName = new QLineEdit(groupBox);
        lEditUserName->setObjectName(QStringLiteral("lEditUserName"));

        gridLayout->addWidget(lEditUserName, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lEditPasswd = new QLineEdit(groupBox);
        lEditPasswd->setObjectName(QStringLiteral("lEditPasswd"));

        gridLayout->addWidget(lEditPasswd, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lEditCameraIP = new QLineEdit(groupBox);
        lEditCameraIP->setObjectName(QStringLiteral("lEditCameraIP"));

        gridLayout->addWidget(lEditCameraIP, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lEditCameraPort = new QLineEdit(groupBox);
        lEditCameraPort->setObjectName(QStringLiteral("lEditCameraPort"));

        gridLayout->addWidget(lEditCameraPort, 3, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 1, 1, 2);

        groupBox_2 = new QGroupBox(widSetting);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font1);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(70, 0));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        lEditTCPIP = new QLineEdit(groupBox_2);
        lEditTCPIP->setObjectName(QStringLiteral("lEditTCPIP"));

        gridLayout_2->addWidget(lEditTCPIP, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(70, 0));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        lEditTCPPort = new QLineEdit(groupBox_2);
        lEditTCPPort->setObjectName(QStringLiteral("lEditTCPPort"));

        gridLayout_2->addWidget(lEditTCPPort, 1, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 2, 1, 1, 2);

        groupBox_3 = new QGroupBox(widSetting);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font1);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 80, 91, 33));
        label_9->setMinimumSize(QSize(70, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        label_9->setFont(font2);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 170, 70, 33));
        label_7->setMinimumSize(QSize(70, 0));
        label_7->setFont(font2);
        led_lowerIP = new QLineEdit(groupBox_3);
        led_lowerIP->setObjectName(QStringLiteral("led_lowerIP"));
        led_lowerIP->setGeometry(QRect(140, 80, 321, 31));
        led_lowerIP->setFont(font1);
        led_lowerPort = new QLineEdit(groupBox_3);
        led_lowerPort->setObjectName(QStringLiteral("led_lowerPort"));
        led_lowerPort->setGeometry(QRect(140, 170, 321, 31));
        led_lowerPort->setFont(font1);

        gridLayout_3->addWidget(groupBox_3, 2, 3, 1, 2);

        groupBox_4 = new QGroupBox(widSetting);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font1);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_4->addWidget(label_10, 2, 0, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        led_ComIP = new QLineEdit(groupBox_4);
        led_ComIP->setObjectName(QStringLiteral("led_ComIP"));

        gridLayout_4->addWidget(led_ComIP, 0, 1, 1, 1);

        led_ComPort = new QLineEdit(groupBox_4);
        led_ComPort->setObjectName(QStringLiteral("led_ComPort"));

        gridLayout_4->addWidget(led_ComPort, 2, 1, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 3);

        gridLayout_3->addWidget(groupBox_4, 0, 3, 1, 2);


        retranslateUi(widSetting);

        QMetaObject::connectSlotsByName(widSetting);
    } // setupUi

    void retranslateUi(QDialog *widSetting)
    {
        widSetting->setWindowTitle(QApplication::translate("widSetting", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        pBtnCancel->setText(QApplication::translate("widSetting", "\345\217\226\346\266\210", 0));
        pBtnSave->setText(QApplication::translate("widSetting", "\347\241\256\345\256\232", 0));
        groupBox->setTitle(QApplication::translate("widSetting", "\347\233\270\346\234\272\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("widSetting", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("widSetting", "\345\257\206\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("widSetting", "IP\357\274\232", 0));
        label_4->setText(QApplication::translate("widSetting", "Port\357\274\232", 0));
        groupBox_2->setTitle(QApplication::translate("widSetting", "\345\267\245\346\216\247\346\234\272\350\256\276\347\275\256", 0));
        label_5->setText(QApplication::translate("widSetting", "IP\357\274\232", 0));
        label_6->setText(QApplication::translate("widSetting", "Port\357\274\232", 0));
        groupBox_3->setTitle(QApplication::translate("widSetting", "\344\275\216\345\212\237\350\200\227\350\256\276\347\275\256", 0));
        label_9->setText(QApplication::translate("widSetting", "IP\357\274\232", 0));
        label_7->setText(QApplication::translate("widSetting", "Port\357\274\232", 0));
        groupBox_4->setTitle(QApplication::translate("widSetting", "\344\270\262\345\217\243\346\234\215\345\212\241\345\231\250(\347\224\265\346\261\240\346\250\241\345\235\227)\350\256\276\347\275\256", 0));
        label_10->setText(QApplication::translate("widSetting", "Port\357\274\232", 0));
        label_8->setText(QApplication::translate("widSetting", "IP:", 0));
    } // retranslateUi

};

namespace Ui {
    class widSetting: public Ui_widSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDSETTING_H
