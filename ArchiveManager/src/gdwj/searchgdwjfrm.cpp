#include "searchgdwjfrm.h"
#include "ui_searchgdwjfrm.h"

SearchGdwjFrm::SearchGdwjFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SearchGdwjFrm)
{
    ui->setupUi(this);
}

SearchGdwjFrm::~SearchGdwjFrm()
{
    delete ui;
}
