#ifndef LOGSQLTABLEMODEL_H
#define LOGSQLTABLEMODEL_H

#include "common/SSqlTableModel.h"

class LogSqlTableModel : public SSqlTableModel
{
    Q_OBJECT
public:
    LogSqlTableModel(QObject *parent = 0);
    ~LogSqlTableModel();

public slots:
    bool setAdvancedKey(DbRec *key);
    QString tableName() const;
    void rowInfo(const int row, DbRec *info);
    void print(QTextDocument *doc);


protected slots:
    bool selectByAdvancedKey();
};

#endif // LOGSQLTABLEMODEL_H
