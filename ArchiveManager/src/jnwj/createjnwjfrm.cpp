#include "createjnwjfrm.h"
#include "ui_createjnwjfrm.h"
#include "jnwjdetailsfrm.h"
#include <QVBoxLayout>

CreateJnwjFrm::CreateJnwjFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreateJnwjFrm)
{
    ui->setupUi(this);

    QVBoxLayout *vLay = new QVBoxLayout(ui->frame_details);
    vLay->addWidget(mFrmDetails = new JnwjDetailsFrm);
}

CreateJnwjFrm::~CreateJnwjFrm()
{
    delete ui;
}
