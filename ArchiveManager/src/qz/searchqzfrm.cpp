#include "searchqzfrm.h"
#include "ui_searchqzfrm.h"

SearchQzFrm::SearchQzFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SearchQzFrm)
{
    ui->setupUi(this);
}

SearchQzFrm::~SearchQzFrm()
{
    delete ui;
}
