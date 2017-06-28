#include "LogSqlTableFrm.h"
#include "LogSqlTableModel.h"

LogSqlTableFrm::LogSqlTableFrm(QWidget *parent) :
    SSqlTableFrm(parent)
{
    mModel = new LogSqlTableModel(view());
    view()->setModel(mModel);
    connectSlots();
}

LogSqlTableFrm::~LogSqlTableFrm()
{

}

