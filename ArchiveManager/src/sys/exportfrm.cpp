#include "exportfrm.h"
#include "ui_exportfrm.h"

ExportFrm::ExportFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ExportFrm)
{
    ui->setupUi(this);
}

ExportFrm::~ExportFrm()
{
    delete ui;
}
