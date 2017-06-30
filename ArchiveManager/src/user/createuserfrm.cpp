#include "createuserfrm.h"
#include "ui_createuserfrm.h"
#include <QVBoxLayout>
#include "userdetailsfrm.h"

CreateUserFrm::CreateUserFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreateUserFrm)
{
    ui->setupUi(this);
    QVBoxLayout *vLay = new QVBoxLayout(ui->frame_details);
    vLay->addWidget(mFrmDetails = new UserDetailsFrm);
}

CreateUserFrm::~CreateUserFrm()
{
    delete ui;
}

void CreateUserFrm::on_pushButton_create_clicked()
{

}
