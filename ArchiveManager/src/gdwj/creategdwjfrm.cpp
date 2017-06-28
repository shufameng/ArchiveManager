#include "creategdwjfrm.h"
#include "ui_creategdwjfrm.h"

CreateGdwjFrm::CreateGdwjFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreateGdwjFrm)
{
    ui->setupUi(this);
}

CreateGdwjFrm::~CreateGdwjFrm()
{
    delete ui;
}
