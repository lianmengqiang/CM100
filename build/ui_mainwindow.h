/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actExit;
    QAction *actSetting;
    QAction *actFile;
    QAction *act_lower;
    QAction *act_led;
    QAction *act_camera;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *lab_dx;
    QLabel *lab_dxValue;
    QLabel *lab_dy;
    QLabel *lab_dyValue;
    QLabel *lab_dxa;
    QLabel *lab_dxaValue;
    QLabel *label_dya;
    QLabel *lab_dyaValue;
    QLabel *label_dis;
    QLabel *lab_disValue;
    QLabel *label;
    QLabel *label_2;
    QPushButton *ptb_lower;
    QLabel *label_3;
    QPushButton *ptb_std;
    QPushButton *pushButton;
    QLabel *lab_status;
    QDoubleSpinBox *spb_value;
    QPushButton *ptb_led;
    QFrame *frame;
    QPushButton *ptb_camStu;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1200);
        MainWindow->setMinimumSize(QSize(0, 0));
        actExit = new QAction(MainWindow);
        actExit->setObjectName(QStringLiteral("actExit"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        actExit->setFont(font);
        actSetting = new QAction(MainWindow);
        actSetting->setObjectName(QStringLiteral("actSetting"));
        actSetting->setFont(font);
        actFile = new QAction(MainWindow);
        actFile->setObjectName(QStringLiteral("actFile"));
        actFile->setFont(font);
        act_lower = new QAction(MainWindow);
        act_lower->setObjectName(QStringLiteral("act_lower"));
        act_lower->setCheckable(true);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        act_lower->setFont(font1);
        act_led = new QAction(MainWindow);
        act_led->setObjectName(QStringLiteral("act_led"));
        act_led->setCheckable(true);
        act_led->setFont(font1);
        act_camera = new QAction(MainWindow);
        act_camera->setObjectName(QStringLiteral("act_camera"));
        act_camera->setCheckable(true);
        act_camera->setFont(font1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lab_dx = new QLabel(centralwidget);
        lab_dx->setObjectName(QStringLiteral("lab_dx"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        lab_dx->setFont(font2);

        gridLayout->addWidget(lab_dx, 0, 0, 1, 1);

        lab_dxValue = new QLabel(centralwidget);
        lab_dxValue->setObjectName(QStringLiteral("lab_dxValue"));
        lab_dxValue->setFont(font2);

        gridLayout->addWidget(lab_dxValue, 0, 1, 1, 1);

        lab_dy = new QLabel(centralwidget);
        lab_dy->setObjectName(QStringLiteral("lab_dy"));
        lab_dy->setFont(font2);

        gridLayout->addWidget(lab_dy, 1, 0, 1, 1);

        lab_dyValue = new QLabel(centralwidget);
        lab_dyValue->setObjectName(QStringLiteral("lab_dyValue"));
        lab_dyValue->setFont(font2);

        gridLayout->addWidget(lab_dyValue, 1, 1, 1, 1);

        lab_dxa = new QLabel(centralwidget);
        lab_dxa->setObjectName(QStringLiteral("lab_dxa"));
        lab_dxa->setFont(font2);

        gridLayout->addWidget(lab_dxa, 2, 0, 1, 1);

        lab_dxaValue = new QLabel(centralwidget);
        lab_dxaValue->setObjectName(QStringLiteral("lab_dxaValue"));
        lab_dxaValue->setFont(font2);

        gridLayout->addWidget(lab_dxaValue, 2, 1, 1, 1);

        label_dya = new QLabel(centralwidget);
        label_dya->setObjectName(QStringLiteral("label_dya"));
        label_dya->setFont(font2);

        gridLayout->addWidget(label_dya, 3, 0, 1, 1);

        lab_dyaValue = new QLabel(centralwidget);
        lab_dyaValue->setObjectName(QStringLiteral("lab_dyaValue"));
        lab_dyaValue->setFont(font2);

        gridLayout->addWidget(lab_dyaValue, 3, 1, 1, 1);

        label_dis = new QLabel(centralwidget);
        label_dis->setObjectName(QStringLiteral("label_dis"));
        label_dis->setFont(font2);

        gridLayout->addWidget(label_dis, 4, 0, 1, 1);

        lab_disValue = new QLabel(centralwidget);
        lab_disValue->setObjectName(QStringLiteral("lab_disValue"));
        lab_disValue->setFont(font2);
        lab_disValue->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(lab_disValue, 4, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);

        gridLayout->addWidget(label, 5, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setSizeIncrement(QSize(1920, 1200));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(7);
        font3.setBold(false);
        font3.setWeight(50);
        label_2->setFont(font3);

        gridLayout->addWidget(label_2, 5, 1, 1, 1);

        ptb_lower = new QPushButton(centralwidget);
        ptb_lower->setObjectName(QStringLiteral("ptb_lower"));
        ptb_lower->setMinimumSize(QSize(0, 40));
        ptb_lower->setFont(font2);

        gridLayout->addWidget(ptb_lower, 6, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 40));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 7, 0, 1, 1);

        ptb_std = new QPushButton(centralwidget);
        ptb_std->setObjectName(QStringLiteral("ptb_std"));
        ptb_std->setMinimumSize(QSize(0, 40));
        ptb_std->setFont(font2);

        gridLayout->addWidget(ptb_std, 8, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setFont(font2);

        gridLayout->addWidget(pushButton, 8, 1, 1, 1);

        lab_status = new QLabel(centralwidget);
        lab_status->setObjectName(QStringLiteral("lab_status"));
        lab_status->setMinimumSize(QSize(0, 30));
        lab_status->setMaximumSize(QSize(16777215, 50));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        font4.setStyleStrategy(QFont::PreferDefault);
        lab_status->setFont(font4);
        lab_status->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lab_status, 9, 0, 1, 1);

        spb_value = new QDoubleSpinBox(centralwidget);
        spb_value->setObjectName(QStringLiteral("spb_value"));
        spb_value->setMinimumSize(QSize(0, 60));
        QFont font5;
        font5.setPointSize(11);
        spb_value->setFont(font5);
        spb_value->setMaximum(2.0099e+08);
        spb_value->setValue(10);

        gridLayout->addWidget(spb_value, 7, 1, 1, 1);

        ptb_led = new QPushButton(centralwidget);
        ptb_led->setObjectName(QStringLiteral("ptb_led"));
        ptb_led->setMinimumSize(QSize(0, 40));
        ptb_led->setFont(font2);

        gridLayout->addWidget(ptb_led, 9, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);

        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ptb_camStu = new QPushButton(frame);
        ptb_camStu->setObjectName(QStringLiteral("ptb_camStu"));
        ptb_camStu->setGeometry(QRect(1140, 270, 161, 51));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(9);
        font6.setBold(true);
        font6.setWeight(75);
        ptb_camStu->setFont(font6);

        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        gridLayout_2->setColumnStretch(0, 5);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setMinimumSize(QSize(0, 0));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 50));
        menubar->setMinimumSize(QSize(0, 50));
        QFont font7;
        font7.setPointSize(18);
        menubar->setFont(font7);
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setMinimumSize(QSize(50, 45));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_2->setMinimumSize(QSize(50, 45));
        QFont font8;
        font8.setPointSize(14);
        menu_2->setFont(font8);
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(act_lower);
        menu->addAction(act_camera);
        menu->addAction(actExit);
        menu_2->addAction(actSetting);
        menu_2->addAction(actFile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        actSetting->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        actFile->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\345\237\272\345\207\206\345\200\274", 0));
        act_lower->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\346\226\255\347\224\265", 0));
#ifndef QT_NO_TOOLTIP
        act_lower->setToolTip(QApplication::translate("MainWindow", "\347\263\273\347\273\237\346\226\255\347\224\265", 0));
#endif // QT_NO_TOOLTIP
        act_led->setText(QApplication::translate("MainWindow", "\345\274\200\347\201\257", 0));
        act_camera->setText(QApplication::translate("MainWindow", "\347\233\270\346\234\272\346\226\255\347\224\265", 0));
#ifndef QT_NO_TOOLTIP
        act_camera->setToolTip(QApplication::translate("MainWindow", "\347\233\270\346\234\272\346\226\255\347\224\265", 0));
#endif // QT_NO_TOOLTIP
        lab_dx->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\345\201\217\347\247\273\351\207\217\357\274\232", 0));
        lab_dxValue->setText(QApplication::translate("MainWindow", "--", 0));
        lab_dy->setText(QApplication::translate("MainWindow", "\345\236\202\347\233\264\345\201\217\347\247\273\351\207\217\357\274\232", 0));
        lab_dyValue->setText(QApplication::translate("MainWindow", "--", 0));
        lab_dxa->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\350\247\222\345\272\246\345\201\217\347\247\273\351\207\217\357\274\232", 0));
        lab_dxaValue->setText(QApplication::translate("MainWindow", "--", 0));
        label_dya->setText(QApplication::translate("MainWindow", "\345\236\202\347\233\264\350\247\222\345\272\246\345\201\217\347\247\273\351\207\217\357\274\232", 0));
        lab_dyaValue->setText(QApplication::translate("MainWindow", "--", 0));
        label_dis->setText(QApplication::translate("MainWindow", "\347\253\257\351\235\242\351\227\264\350\267\235\357\274\232", 0));
        lab_disValue->setText(QApplication::translate("MainWindow", "--", 0));
        label->setText(QApplication::translate("MainWindow", "\346\234\254\346\254\241\346\225\260\346\215\256\346\233\264\346\226\260\346\227\266\351\227\264\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "--", 0));
        ptb_lower->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\346\226\255\347\224\265", 0));
        label_3->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\351\230\210\345\200\274:", 0));
        ptb_std->setText(QApplication::translate("MainWindow", "\345\274\200\345\220\257\346\240\207\345\256\232", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\351\230\200\345\200\274", 0));
#ifndef QT_NO_STATUSTIP
        lab_status->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lab_status->setText(QApplication::translate("MainWindow", "\344\270\215\345\217\257\346\214\202\346\216\245", 0));
        ptb_led->setText(QApplication::translate("MainWindow", "\345\274\200\347\201\257", 0));
        ptb_camStu->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\347\250\213\345\272\217", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
