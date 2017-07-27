#include "toolsfrm.h"
#include "ui_toolsfrm.h"

ToolsFrm::ToolsFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ToolsFrm)
{
    ui->setupUi(this);
}

ToolsFrm::~ToolsFrm()
{
    delete ui;
}
