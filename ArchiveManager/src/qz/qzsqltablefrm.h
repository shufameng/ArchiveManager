#ifndef QZSQLTABLEFRM_H
#define QZSQLTABLEFRM_H


#include "common/SSqlTableFrm.h"


class QzSqlTableFrm : public SSqlTableFrm
{
    Q_OBJECT
public:
    QzSqlTableFrm(QWidget *parent = 0);
    ~QzSqlTableFrm();
};

#endif // QZSQLTABLEFRM_H
