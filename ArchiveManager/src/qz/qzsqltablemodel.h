#ifndef QZSQLTABLEMODEL_H
#define QZSQLTABLEMODEL_H

#include "common/SSqlTableModel.h"

class QzSqlTableModel : public SSqlTableModel
{
    Q_OBJECT
public:
    QzSqlTableModel(QWidget *parent = 0);
    ~QzSqlTableModel();

public slots:
    bool setAdvancedKey(DbRec *key);
    QString tableName() const;
    void rowInfo(const int row, DbRec *info);
    void print(QTextDocument *doc);

protected slots:
    bool selectByAdvancedKey();
};

#endif // QZSQLTABLEMODEL_H
