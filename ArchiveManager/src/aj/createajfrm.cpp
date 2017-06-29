#include "createajfrm.h"
#include "ui_createajfrm.h"
#include "ajdetailsfrm.h"
#include <QVBoxLayout>

CreateAjFrm::CreateAjFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreateAjFrm)
{
    ui->setupUi(this);

    QVBoxLayout *vLay = new QVBoxLayout(ui->frame_details);
    vLay->addWidget(mFrmDetails = new AjDetailsFrm);
}

CreateAjFrm::~CreateAjFrm()
{
    delete ui;
}
