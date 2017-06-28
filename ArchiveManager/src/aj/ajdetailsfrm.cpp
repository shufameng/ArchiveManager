#include "ajdetailsfrm.h"
#include "ui_ajdetailsfrm.h"

AjDetailsFrm::AjDetailsFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AjDetailsFrm)
{
    ui->setupUi(this);
}

AjDetailsFrm::~AjDetailsFrm()
{
    delete ui;
}
