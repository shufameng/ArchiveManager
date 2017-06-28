#include "createqzfrm.h"
#include "ui_createqzfrm.h"
#include "qzdetailsfrm.h"

#include <QVBoxLayout>

CreateQzFrm::CreateQzFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreateQzFrm)
{
    ui->setupUi(this);

    QVBoxLayout *vLay = new QVBoxLayout(this);
    vLay->addWidget(mFrmQzDetails = new QzDetailsFrm);
    vLay->addStretch();
}

CreateQzFrm::~CreateQzFrm()
{
    delete ui;
}
