#include "createajfrm.h"
#include "ui_createajfrm.h"

CreateAjFrm::CreateAjFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreateAjFrm)
{
    ui->setupUi(this);
}

CreateAjFrm::~CreateAjFrm()
{
    delete ui;
}
