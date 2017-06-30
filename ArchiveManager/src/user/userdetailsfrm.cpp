#include "userdetailsfrm.h"
#include "ui_userdetailsfrm.h"
#include "common/dbtypes.h"
#include <QDateTime>

UserDetailsFrm::UserDetailsFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::UserDetailsFrm),
    mID(-1)
{
    ui->setupUi(this);
}

UserDetailsFrm::~UserDetailsFrm()
{
    delete ui;
}

void UserDetailsFrm::getInfo(DbUser *info)
{
    info->id.value              = mID;
    info->name.value        = ui->lineEdit_userName->text();
    info->password.value    = ui->lineEdit_password->text();
    info->role.value            = ui->comboBox_userRole->currentIndex();
    info->remarks.value     = ui->textEdit_remarks->toPlainText();
    info->createTime.value = QDateTime::currentDateTime();
}

void UserDetailsFrm::setInfo(const DbUser *info)
{
    mID = info->id.value.toLongLong();
    ui->lineEdit_userName->setText(info->name.value.toString());
    ui->lineEdit_password->setText(info->password.value.toString());
    ui->comboBox_userRole->setCurrentIndex(info->role.value.toInt());
    ui->textEdit_remarks->setText(info->remarks.value.toString());
}

void UserDetailsFrm::cleanNotCheckedFields()
{
    if (!ui->checkBox_userName->isChecked()) ui->lineEdit_userName->clear();
    if (!ui->checkBox_password->isChecked()) ui->lineEdit_password->clear();
    if (!ui->checkBox_userRole->isChecked()) ui->comboBox_userRole->setCurrentIndex(0);
    if (!ui->checkBox_remarks->isChecked()) ui->textEdit_remarks->clear();
}

void UserDetailsFrm::cleanAllFields()
{
    ui->lineEdit_userName->clear();
    ui->lineEdit_password->clear();
    ui->comboBox_userRole->setCurrentIndex(0);
    ui->textEdit_remarks->clear();
}

void UserDetailsFrm::setToAddMode()
{

}

void UserDetailsFrm::setToCheckMode()
{

}

void UserDetailsFrm::setToKeyMode()
{

}

void UserDetailsFrm::setToEditMode()
{

}
