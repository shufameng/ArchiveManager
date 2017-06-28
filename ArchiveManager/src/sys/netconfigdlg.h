#ifndef NETCONFIGDLG_H
#define NETCONFIGDLG_H

#include "common/sdialog.h"

namespace Ui {
class NetConfigFrm;
}

class NetConfigDlg : public SDialog
{
    Q_OBJECT

public:
    explicit NetConfigDlg(QWidget *parent = 0);
    ~NetConfigDlg();

    void loadNetConfigs();
    void saveNetConfigs();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_yes_clicked();

    void on_pushButton_apply_clicked();

private:
    Ui::NetConfigFrm *ui;
};

#endif // NETCONFIGDLG_H
