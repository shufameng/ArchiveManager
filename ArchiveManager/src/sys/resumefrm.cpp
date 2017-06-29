#include "resumefrm.h"
#include "ui_resumefrm.h"

ResumeFrm::ResumeFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ResumeFrm)
{
    ui->setupUi(this);
}

ResumeFrm::~ResumeFrm()
{
    delete ui;
}
