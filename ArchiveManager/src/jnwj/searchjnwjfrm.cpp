#include "searchjnwjfrm.h"
#include "ui_searchjnwjfrm.h"

SearchJnwjFrm::SearchJnwjFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SearchJnwjFrm)
{
    ui->setupUi(this);
}

SearchJnwjFrm::~SearchJnwjFrm()
{
    delete ui;
}
