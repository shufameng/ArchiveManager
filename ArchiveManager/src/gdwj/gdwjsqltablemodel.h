#ifndef GDWJSQLTABLEMODEL_H
#define GDWJSQLTABLEMODEL_H

#include "common/SSqlTableModel.h"

class GdwjSqlTableModel : public SSqlTableModel
{
    Q_OBJECT
public:
    GdwjSqlTableModel(QObject *parent = 0);
    ~GdwjSqlTableModel();

public slots:
    bool setAdvancedKey(DbRec *key);
    QString tableName() const;
    void rowInfo(const int row, DbRec *info);
    void print(QTextDocument *doc);

    bool useOcr();

protected slots:
    bool selectByAdvancedKey();
};

#endif // GDWJSQLTABLEMODEL_H
