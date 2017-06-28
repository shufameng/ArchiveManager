#include "GdwjSqlTableFrm.h"
#include "GdwjSqlTableModel.h"

GdwjSqlTableFrm::GdwjSqlTableFrm(QWidget *parent) :
    SSqlTableFrm(parent)
{
    mModel = new GdwjSqlTableModel(view());
    view()->setModel(mModel);
    connectSlots();
}

GdwjSqlTableFrm::~GdwjSqlTableFrm()
{

}
