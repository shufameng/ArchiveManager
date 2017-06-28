#include "JnwjSqlTableFrm.h"
#include "JnwjSqlTableModel.h"


JnwjSqlTableFrm::JnwjSqlTableFrm(QWidget *parent) :
    SSqlTableFrm(parent)
{
    mModel = new JnwjSqlTableModel(view());
    view()->setModel(mModel);
    connectSlots();
}

JnwjSqlTableFrm::~JnwjSqlTableFrm()
{

}
