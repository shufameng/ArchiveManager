#ifndef CHANGEPASSWORDDLG_H
#define CHANGEPASSWORDDLG_H

#include "common/sdialog.h"

namespace Ui {
class ChangePasswordFrm;
}

class ChangePasswordDlg : public SDialog
{
    Q_OBJECT
public:
    ChangePasswordDlg(QWidget *parent = 0);
    ~ChangePasswordDlg();
private slots:
    void onBtnYes();

private:
    Ui::ChangePasswordFrm *ui;
};

#endif // CHANGEPASSWORDDLG_H
