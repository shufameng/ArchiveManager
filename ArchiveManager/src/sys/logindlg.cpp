#include "LoginDlg.h"
#include "ui_loginfrm.h"
#include "common/DeleteButtonComboBox.h"
#include "common/IniLoader.h"
#include "NetConfigDlg.h"
#include "LoginThread.h"
#include <QMessageBox>
#include "common/globals.h"
#include <QTimer>

LoginDlg::LoginDlg(QWidget *parent) :
    SDialog(parent),
    ui(new Ui::LoginFrm)
{
    ui->setupUi(centralFrame());
    titleBarButtonLayout()->addWidget(ui->toolButton_configNetwork);
    setWindowTitle(QString::fromLocal8Bit("登录"));
    setWindowIconHidden(true);
    setDragResizeable(false);
    setWindowMaxRestoreButtonHidden(true);
    resize(400,300);

    // 生成UserComboBox组件
    mUserComboBox = new DeleteButtonComboBox(this);
    ui->gridLayout_loginMsg->addWidget(mUserComboBox, 0, 1);
    connect(mUserComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(onCurrentUserChanged(int)));
    connect(mUserComboBox, SIGNAL(itemRemoved(QString)),
            this, SLOT(onUserRemoved(QString)));

    // 加载配置文件
    mLoginHistory = IniLoader::loadLoginMsgs();
    mUserComboBox->clear();
    for (int i = 0; i < mLoginHistory.size(); i ++) {
        mUserComboBox->addItem(mLoginHistory.at(i).user);
    }
    ui->checkBox_rememberMyPasswd->setChecked(IniLoader::loadLoginRememberPwd());

    connect(ui->checkBox_rememberMyPasswd, SIGNAL(toggled(bool)),
            this, SLOT(onCheckBoxRememberPwdToggled(bool)));
    connect(ui->pushButton_login, SIGNAL(clicked()), this, SLOT(on_pushButton_login_clicked()));
    connect(ui->pushButton_goBack, SIGNAL(clicked()), this, SLOT(on_pushButton_goBack_clicked()));
    connect(ui->toolButton_configNetwork, SIGNAL(clicked()), this, SLOT(on_toolButton_configNetwork_clicked()));

    // test
    on_pushButton_login_clicked();
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::setStatus(const QString &status)
{
    ui->textEdit_status->setText(status);
}

void LoginDlg::setToLoginPage()
{
    ui->stackedWidget->setCurrentWidget(ui->page_login);
}

void LoginDlg::setToStatusPage()
{
    ui->stackedWidget->setCurrentWidget(ui->page_status);
}

void LoginDlg::on_pushButton_login_clicked()
{
    LoginThread *t = new LoginThread(mUserComboBox->currentText(), ui->lineEdit_password->text(), this);
    connect(t, SIGNAL(loginSucceed()), this, SLOT(onLoginSucceed()));
    connect(t, SIGNAL(loginFailed(QString)), this, SLOT(onLoginFailed(QString)));
    connect(t, SIGNAL(started()), this, SLOT(onLoginThreadStarted()));
    connect(t, SIGNAL(finished()), this, SLOT(onLoginThreadFinished()));
    t->start();
}

void LoginDlg::onCurrentUserChanged(int index)
{
    if (index < 0) {
        ui->lineEdit_password->clear();
        return;
    }

    QString text = mUserComboBox->itemText(index);
    for (int i = 0; i < mLoginHistory.size(); i ++) {
        if (mLoginHistory.at(i).user == text) {
            ui->lineEdit_password->setText(mLoginHistory.at(i).passwd);
            break;
        }
    }
}

void LoginDlg::onUserRemoved(const QString &name)
{
    IniLoader::removeLoginMsg(name);
}

void LoginDlg::on_toolButton_configNetwork_clicked()
{
    setDisabled(true);

    NetConfigDlg dlg(this);
    dlg.loadNetConfigs();
    dlg.exec();

    setDisabled(false);
}

void LoginDlg::onLoginSucceed()
{
    LoginMsg msg;
    msg.user = mUserComboBox->currentText();
    msg.passwd = ui->lineEdit_password->text();

    if (!ui->checkBox_rememberMyPasswd->isChecked())
        msg.passwd = "";

    IniLoader::addLoginMsg(msg);
    accept();
}

void LoginDlg::onLoginFailed(const QString &error)
{
    setToStatusPage();
    setStatus(QString::fromLocal8Bit("登录失败:\n") + error);
}

void LoginDlg::onLoginThreadStarted()
{
    setToStatusPage();
    setStatus(QString::fromLocal8Bit("正在登陆..."));
    ui->pushButton_goBack->hide();
}

void LoginDlg::onLoginThreadFinished()
{
   ui->pushButton_goBack->show();
}

void LoginDlg::onCheckBoxRememberPwdToggled(bool checked)
{
    IniLoader::saveLoginRememberPwd(checked);
}

void LoginDlg::on_pushButton_goBack_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_login);
}

