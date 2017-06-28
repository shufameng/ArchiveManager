#include "AjSqlTableFrm.h"
#include "AjSqlTableModel.h"

AjSqlTableFrm::AjSqlTableFrm(QWidget *parent) :
    SSqlTableFrm(parent)
{
    mModel = new AjSqlTableModel(view());
    view()->setModel(mModel);
    connectSlots();
}

AjSqlTableFrm::~AjSqlTableFrm()
{

}
