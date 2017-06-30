#include "changepassworddlg.h"
#include "ui_changepasswordfrm.h"
#include "changepasswordthread.h"
#include "common/globals.h"
#include "common/dbtypes.h"

ChangePasswordDlg::ChangePasswordDlg(QWidget *parent) :
    SDialog(parent),
    ui(new Ui::ChangePasswordFrm)
{
    ui->setupUi(centralFrame());
    setWindowMaxRestoreButtonHidden(true);
    setWindowMinButtonHidden(true);
    setWindowIconHidden(true);
    setWindowTitle(QString::fromLocal8Bit("ĞŞ¸ÄÎÒµÄÃÜÂë"));

    connect(ui->pushButton_cancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->pushButton_yes, SIGNAL(clicked()), this, SLOT(onBtnYes()));
    connect(ui->pushButton_goBack, SIGNAL(clicked()), this, SLOT(onBtnGoBack()));
}

ChangePasswordDlg::~ChangePasswordDlg()
{

}

void ChangePasswordDlg::onBtnYes()
{
    ChangePasswordThread *thread = new ChangePasswordThread(
                Globals::sgCurUser->name.value.toString(),
                ui->lineEdit_oldPasswd->text().trimmed(),
                ui->lineEdit_newPasswd->text().trimmed(),
                ui->lineEdit_repeatPasswd->text().trimmed(),
                this
                );
    connect(thread, SIGNAL(started()), this, SLOT(onChangePasswdThreadStarted()));
    connect(thread, SIGNAL(finished()), this, SLOT(onChangePasswdThreadFinished()));
    connect(thread, SIGNAL(changePasswdResult(bool,QString)), this, SLOT(onChangePasswdResult(bool,QString)));
    thread->start();
}

void ChangePasswordDlg::onBtnGoBack()
{
    ui->stackedWidget->setCurrentWidget(ui->page_changePasswd);
}

void ChangePasswordDlg::onChangePasswdResult(bool succeed, const QString &description)
{
    ui->stackedWidget->setCurrentWidget(ui->page_description);
    QString title;
    if (succeed)
        title = QString::fromLocal8Bit("ĞŞ¸ÄÃÜÂë³É¹¦:");
    else
        title = QString::fromLocal8Bit("ĞŞ¸ÄÃÜÂëÊ§°Ü:");

    ui->textEdit_description->setText(title + "\n" + description);
    ui->pushButton_goBack->setHidden(false);
}

void ChangePasswordDlg::onChangePasswdThreadStarted()
{
    ui->stackedWidget->setCurrentWidget(ui->page_description);
    ui->pushButton_goBack->setHidden(true);
    ui->textEdit_description->setText(QString::fromLocal8Bit("ÕıÔÚĞŞ¸ÄÃÜÂë..."));
}

void ChangePasswordDlg::onChangePasswdThreadFinished()
{
    ui->pushButton_goBack->setHidden(false);
}

