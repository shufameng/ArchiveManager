#ifndef AJSQLTABLEMODEL_H
#define AJSQLTABLEMODEL_H

#include "common/SSqlTableModel.h"

class AjSqlTableModel : public SSqlTableModel
{
    Q_OBJECT
public:
    AjSqlTableModel(QObject *parent = 0);
    ~AjSqlTableModel();
public slots:
    bool setAdvancedKey(DbRec *key);
    QString tableName() const;
    void rowInfo(const int row, DbRec *info);
    void print(QTextDocument *doc);

protected slots:
    bool selectByAdvancedKey();
};

#endif // AJSQLTABLEMODEL_H
