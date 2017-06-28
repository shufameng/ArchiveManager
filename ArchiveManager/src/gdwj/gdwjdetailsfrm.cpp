#include "gdwjdetailsfrm.h"
#include "ui_gdwjdetailsfrm.h"

GdwjDetailsFrm::GdwjDetailsFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::GdwjDetailsFrm)
{
    ui->setupUi(this);
}

GdwjDetailsFrm::~GdwjDetailsFrm()
{
    delete ui;
}
