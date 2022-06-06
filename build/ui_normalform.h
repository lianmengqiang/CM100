/********************************************************************************
** Form generated from reading UI file 'normalform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMALFORM_H
#define UI_NORMALFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NorMalForm
{
public:
    QGridLayout *gridLayout;
    QPushButton *ptb_firm;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tbw_file;
    QPushButton *ptb_cancle;
    QPushButton *ptb_add;
    QPushButton *pushButton;

    void setupUi(QWidget *NorMalForm)
    {
        if (NorMalForm->objectName().isEmpty())
            NorMalForm->setObjectName(QStringLiteral("NorMalForm"));
        NorMalForm->resize(962, 754);
        gridLayout = new QGridLayout(NorMalForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ptb_firm = new QPushButton(NorMalForm);
        ptb_firm->setObjectName(QStringLiteral("ptb_firm"));
        ptb_firm->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(ptb_firm, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(530, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        tbw_file = new QTableWidget(NorMalForm);
        if (tbw_file->columnCount() < 5)
            tbw_file->setColumnCount(5);
        if (tbw_file->rowCount() < 300)
            tbw_file->setRowCount(300);
        tbw_file->setObjectName(QStringLiteral("tbw_file"));
        tbw_file->setContextMenuPolicy(Qt::DefaultContextMenu);
        tbw_file->setLayoutDirection(Qt::LeftToRight);
        tbw_file->setLineWidth(17);
        tbw_file->setMidLineWidth(23);
        tbw_file->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tbw_file->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tbw_file->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tbw_file->setRowCount(300);
        tbw_file->setColumnCount(5);
        tbw_file->horizontalHeader()->setDefaultSectionSize(176);

        gridLayout->addWidget(tbw_file, 0, 0, 1, 6);

        ptb_cancle = new QPushButton(NorMalForm);
        ptb_cancle->setObjectName(QStringLiteral("ptb_cancle"));
        ptb_cancle->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(ptb_cancle, 2, 4, 1, 1);

        ptb_add = new QPushButton(NorMalForm);
        ptb_add->setObjectName(QStringLiteral("ptb_add"));

        gridLayout->addWidget(ptb_add, 2, 1, 1, 1);

        pushButton = new QPushButton(NorMalForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 3, 1, 1);


        retranslateUi(NorMalForm);

        QMetaObject::connectSlotsByName(NorMalForm);
    } // setupUi

    void retranslateUi(QWidget *NorMalForm)
    {
        NorMalForm->setWindowTitle(QApplication::translate("NorMalForm", "Form", 0));
        ptb_firm->setText(QApplication::translate("NorMalForm", "\345\210\267\346\226\260", 0));
        ptb_cancle->setText(QApplication::translate("NorMalForm", "\345\217\226\346\266\210", 0));
        ptb_add->setText(QApplication::translate("NorMalForm", "\346\226\260\345\242\236", 0));
        pushButton->setText(QApplication::translate("NorMalForm", "\345\210\240\351\231\244\346\214\207\345\256\232\350\241\214", 0));
    } // retranslateUi

};

namespace Ui {
    class NorMalForm: public Ui_NorMalForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALFORM_H
