#include "backupfrm.h"
#include "ui_backupfrm.h"

BackupFrm::BackupFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::BackupFrm)
{
    ui->setupUi(this);
}

BackupFrm::~BackupFrm()
{
    delete ui;
}
