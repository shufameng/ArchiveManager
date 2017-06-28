#include "qzdetailsfrm.h"
#include "ui_qzdetailsfrm.h"
#include "common/dbtypes.h"

QzDetailsFrm::QzDetailsFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::QzDetailsFrm),
    mID(-1)
{
    ui->setupUi(this);
}

QzDetailsFrm::~QzDetailsFrm()
{
    delete ui;
}

void QzDetailsFrm::getInfo(DbQz *info)
{
    info->qzh.value = ui->comboBox_qzh->currentText();
    info->qztm.value = ui->textEdit_qztm->toPlainText();
    info->kfh.value = ui->lineEdit_kfh->text();
    info->pjh.value = ui->lineEdit_pjh->text();
    info->qssj.value = ui->lineEdit_qssj->text();
    info->zzsj.value = ui->lineEdit_zzsj->text();
    info->bz.value = ui->textEdit_bz->toPlainText();
    info->id.value = mID;
}

void QzDetailsFrm::setInfo(const DbQz *info)
{
    ui->comboBox_qzh->setCurrentText(info->qzh.value.toString());
    ui->textEdit_qztm->setText(info->qztm.value.toString());
    ui->lineEdit_kfh->setText(info->kfh.value.toString());
    ui->lineEdit_pjh->setText(info->pjh.value.toString());
    ui->lineEdit_qssj->setText(info->qssj.value.toString());
    ui->lineEdit_zzsj->setText(info->zzsj.value.toString());
    ui->textEdit_bz->setText(info->bz.value.toString());
    mID = info->id.value.toLongLong();
}

void QzDetailsFrm::cleanNotCheckedFields()
{
    if (!ui->checkBox_qzh->isChecked())         ui->comboBox_qzh->setCurrentText("");
    if (!ui->checkBox_qztm->isChecked())        ui->textEdit_qztm->clear();
    if (!ui->checkBox_kfh->isChecked())         ui->lineEdit_kfh->clear();
    if (!ui->checkBox_pjh->isChecked())          ui->lineEdit_pjh->clear();
    if (!ui->checkBox_qssj->isChecked())        ui->lineEdit_zzsj->clear();
    if (!ui->checkBox_zzsj->isChecked())        ui->lineEdit_zzsj->clear();
    if (!ui->checkBox_bz->isChecked())          ui->textEdit_bz->clear();
}

void QzDetailsFrm::cleanAllFields()
{
    ui->comboBox_qzh->setCurrentText("");
    ui->textEdit_qztm->clear();
    ui->lineEdit_kfh->clear();
    ui->lineEdit_pjh->clear();
    ui->lineEdit_qssj->clear();
    ui->lineEdit_zzsj->clear();
    ui->textEdit_bz->clear();
}

void QzDetailsFrm::setToAddMode()
{

}

void QzDetailsFrm::setToCheckMode()
{

}

void QzDetailsFrm::setToKeyMode()
{

}

void QzDetailsFrm::setToEditMode()
{

}

void QzDetailsFrm::updateDbLists()
{

}
