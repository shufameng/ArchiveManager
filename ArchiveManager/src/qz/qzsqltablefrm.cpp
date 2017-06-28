#include "QzSqlTableFrm.h"
#include "QzSqlTableModel.h"

QzSqlTableFrm::QzSqlTableFrm(QWidget *parent) :
    SSqlTableFrm(parent)
{
    mModel = new QzSqlTableModel(view());
    view()->setModel(mModel);
    connectSlots();
}

QzSqlTableFrm::~QzSqlTableFrm()
{

}

