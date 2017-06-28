#include "searchajfrm.h"
#include "ui_searchajfrm.h"

SearchAjFrm::SearchAjFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SearchAjFrm)
{
    ui->setupUi(this);
}

SearchAjFrm::~SearchAjFrm()
{
    delete ui;
}
