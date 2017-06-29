#include "importfrm.h"
#include "ui_importfrm.h"

ImportFrm::ImportFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ImportFrm)
{
    ui->setupUi(this);
}

ImportFrm::~ImportFrm()
{
    delete ui;
}
