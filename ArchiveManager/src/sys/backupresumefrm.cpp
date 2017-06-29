#include "backupresumefrm.h"
#include "ui_backupresumefrm.h"

BackupResumeFrm::BackupResumeFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::BackupResumeFrm)
{
    ui->setupUi(this);
}

BackupResumeFrm::~BackupResumeFrm()
{
    delete ui;
}
