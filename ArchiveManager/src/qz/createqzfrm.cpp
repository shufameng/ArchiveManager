#include "createqzfrm.h"
#include "ui_createqzfrm.h"
#include "qzdetailsfrm.h"
#include "common/dbtypes.h"
#include <QMessageBox>

#include <QVBoxLayout>

CreateQzFrm::CreateQzFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreateQzFrm)
{
    ui->setupUi(this);

    QVBoxLayout *vLay = new QVBoxLayout(ui->frame_details);
    vLay->addWidget(mFrmDetails = new QzDetailsFrm);

    connect(ui->pushButton_create, SIGNAL(clicked()),
            this, SLOT(onButtonCreate()));
}

CreateQzFrm::~CreateQzFrm()
{
    delete ui;
}

void CreateQzFrm::onButtonCreate()
{
    DbQz info;
    mFrmDetails->getInfo(&info);

    if (info.qzh.value.toString().isEmpty()) {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("输入的全宗信息不完整!"), QMessageBox::Yes);
        return;
    }


}
