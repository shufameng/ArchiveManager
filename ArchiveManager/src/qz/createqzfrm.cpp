#include "createqzfrm.h"
#include "ui_createqzfrm.h"
#include "qzdetailsfrm.h"

#include <QVBoxLayout>

CreateQzFrm::CreateQzFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreateQzFrm)
{
    ui->setupUi(this);

    QVBoxLayout *vLay = new QVBoxLayout(ui->frame_details);
    vLay->addWidget(mFrmDetails = new QzDetailsFrm);
}

CreateQzFrm::~CreateQzFrm()
{
    delete ui;
}
