#ifndef NORMALFORM_H
#define NORMALFORM_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class NorMalForm;
}

class NorMalForm : public QWidget
{
    Q_OBJECT

public:
    explicit NorMalForm(QWidget *parent = 0);
    ~NorMalForm();

private slots:
    void on_ptb_cancle_clicked();

    void on_ptb_firm_clicked();

private:
    Ui::NorMalForm *ui;
    enum CellType{};
    void normalInit();
    void anlysisData(QString str,int rowCount);
    QTableWidgetItem *item;
    int rowCount;
    int columt;
};

#endif // NORMALFORM_H
