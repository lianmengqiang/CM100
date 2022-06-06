#ifndef WIDSETTING_H
#define WIDSETTING_H

#include <QDialog>

namespace Ui {
class widSetting;
}

class widSetting : public QDialog
{
    Q_OBJECT

public:
    explicit widSetting(QWidget *parent = 0);
    ~widSetting();

signals:
    void                signReLoginCamera(QString ipAddress, QString port, QString userName, QString userPwd);
    void                signReListen(int port);
    void                signReConnectBattery();

protected:
    void                showEvent(QShowEvent *event);

private slots:
    void                slotSaveParam();
    void                slotCancel();

private:
    Ui::widSetting*     ui;
};

#endif // WIDSETTING_H
