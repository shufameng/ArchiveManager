#include "creategdwjfrm.h"
#include "ui_creategdwjfrm.h"
#include "gdwjdetailsfrm.h"
#include <QVBoxLayout>

CreateGdwjFrm::CreateGdwjFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreateGdwjFrm)
{
    ui->setupUi(this);

    QVBoxLayout *vLay = new QVBoxLayout(ui->frame_details);
    vLay->addWidget(mFrmDetails = new GdwjDetailsFrm);
}

CreateGdwjFrm::~CreateGdwjFrm()
{
    delete ui;
}
