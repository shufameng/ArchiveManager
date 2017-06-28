#include "jnwjdetailsfrm.h"
#include "ui_jnwjdetailsfrm.h"

JnwjDetailsFrm::JnwjDetailsFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::JnwjDetailsFrm)
{
    ui->setupUi(this);
}

JnwjDetailsFrm::~JnwjDetailsFrm()
{
    delete ui;
}
