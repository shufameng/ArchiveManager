#include "changepassworddlg.h"
#include "ui_changepasswordfrm.h"

ChangePasswordDlg::ChangePasswordDlg(QWidget *parent) :
    SDialog(parent),
    ui(new Ui::ChangePasswordFrm)
{
    ui->setupUi(centralFrame());
    setWindowMaxRestoreButtonHidden(true);
    setWindowMinButtonHidden(true);
    setWindowIconHidden(true);
    setWindowTitle(QString::fromLocal8Bit("ÐÞ¸ÄÎÒµÄÃÜÂë"));

    connect(ui->pushButton_cancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->pushButton_yes, SIGNAL(clicked()), this, SLOT(onBtnYes()));
}

ChangePasswordDlg::~ChangePasswordDlg()
{

}

void ChangePasswordDlg::onBtnYes()
{

}

