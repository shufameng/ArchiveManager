#include "searchuserfrm.h"
#include "ui_searchuserfrm.h"

SearchUserFrm::SearchUserFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SearchUserFrm)
{
    ui->setupUi(this);
}

SearchUserFrm::~SearchUserFrm()
{
    delete ui;
}
