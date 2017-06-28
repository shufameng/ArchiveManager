#include "searchlogfrm.h"
#include "ui_searchlogfrm.h"

SearchLogFrm::SearchLogFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SearchLogFrm)
{
    ui->setupUi(this);
}

SearchLogFrm::~SearchLogFrm()
{
    delete ui;
}
