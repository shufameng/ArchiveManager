#ifndef AJSQLTABLEFRM_H
#define AJSQLTABLEFRM_H

#include "common/SSqlTableFrm.h"

class AjSqlTableFrm : public SSqlTableFrm
{
    Q_OBJECT
public:
    AjSqlTableFrm(QWidget *parent = 0);
    ~AjSqlTableFrm();
};

#endif // AJSQLTABLEFRM_H
