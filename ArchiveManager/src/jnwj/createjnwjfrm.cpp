#include "createjnwjfrm.h"
#include "ui_createjnwjfrm.h"

CreateJnwjFrm::CreateJnwjFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreateJnwjFrm)
{
    ui->setupUi(this);
}

CreateJnwjFrm::~CreateJnwjFrm()
{
    delete ui;
}
