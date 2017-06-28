#include "NetConfigDlg.h"
#include "ui_netconfigfrm.h"
#include "common/IniLoader.h"
#include <QMessageBox>

NetConfigDlg::NetConfigDlg(QWidget *parent) :
    SDialog(parent),
    ui(new Ui::NetConfigFrm)
{
    ui->setupUi(centralFrame());
    setWindowTitle(QString::fromLocal8Bit("配置网络参数"));
    setWindowMinButtonHidden(true);
    setWindowMaxRestoreButtonHidden(true);
    setWindowIconHidden(true);

    connect(ui->pushButton_apply, SIGNAL(clicked()), this, SLOT(on_pushButton_apply_clicked()));
    connect(ui->pushButton_cancel, SIGNAL(clicked()), this, SLOT(on_pushButton_cancel_clicked()));
    connect(ui->pushButton_yes, SIGNAL(clicked()), this, SLOT(on_pushButton_yes_clicked()));
}

NetConfigDlg::~NetConfigDlg()
{
    delete ui;
}

void NetConfigDlg::loadNetConfigs()
{
    DbNetConfig dbConf = IniLoader::loadDbNetConfig();
    ui->lineEdit_dbIp->setText(dbConf.host);
    ui->lineEdit_dbPort->setText(QString::number(dbConf.port));
    ui->lineEdit_dbUser->setText(dbConf.user);
    ui->lineEdit_dbPasswd->setText(dbConf.passwd);

    FsNetConfig fsConf = IniLoader::loadFsNetConfig();
    ui->lineEdit_fsIp->setText(fsConf.host);
    ui->lineEdit_fsPort->setText(QString::number(fsConf.port));

    HsNetConfig hsConf = IniLoader::loadHsNetConfig();
    ui->lineEdit_hsIp->setText(hsConf.host);
    ui->lineEdit_hsPort->setText(QString::number(hsConf.port));
}

void NetConfigDlg::saveNetConfigs()
{
    DbNetConfig dbConf;
    dbConf.host = ui->lineEdit_dbIp->text();
    dbConf.port = ui->lineEdit_dbPort->text().toInt();
    dbConf.user = ui->lineEdit_dbUser->text();
    dbConf.passwd = ui->lineEdit_dbPasswd->text();
    IniLoader::saveDbNetConfig(dbConf);

    FsNetConfig fsConf;
    fsConf.host = ui->lineEdit_fsIp->text();
    fsConf.port = ui->lineEdit_fsPort->text().toInt();
    IniLoader::saveFsNetConfig(fsConf);

    HsNetConfig hsConf;
    hsConf.host = ui->lineEdit_hsIp->text();
    hsConf.port = ui->lineEdit_hsPort->text().toInt();
    IniLoader::saveHsNetConfig(hsConf);
}

void NetConfigDlg::on_pushButton_cancel_clicked()
{
    reject();
}

void NetConfigDlg::on_pushButton_yes_clicked()
{
    saveNetConfigs();
    accept();
}

void NetConfigDlg::on_pushButton_apply_clicked()
{
    saveNetConfigs();
    QMessageBox msg(QMessageBox::Information,
                    QString::fromLocal8Bit("提示"),
                    QString::fromLocal8Bit("网络配置信息已经保存."),
                    QMessageBox::Yes, this);
    msg.setButtonText(QMessageBox::Yes, QString::fromLocal8Bit("确定"));
    msg.exec();
}
