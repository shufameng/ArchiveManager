#ifndef JNWJSQLTABLEMODEL_H
#define JNWJSQLTABLEMODEL_H

#include "common/SSqlTableModel.h"

class JnwjSqlTableModel : public SSqlTableModel
{
    Q_OBJECT
public:
    JnwjSqlTableModel(QObject *parent = 0);
    ~JnwjSqlTableModel();

public slots:
    bool setAdvancedKey(DbRec *key);
    QString tableName() const;
    void rowInfo(const int row, DbRec *info);
    void print(QTextDocument *doc);

    bool useOcr();
protected slots:
    bool selectByAdvancedKey();
};

#endif // JNWJSQLTABLEMODEL_H
