#include "importexportfrm.h"
#include "ui_importexportfrm.h"

ImportExportFrm::ImportExportFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ImportExportFrm)
{
    ui->setupUi(this);
}

ImportExportFrm::~ImportExportFrm()
{
    delete ui;
}
