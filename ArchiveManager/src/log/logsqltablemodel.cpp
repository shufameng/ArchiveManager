#include "LogSqlTableModel.h"
#include "common/DbTypes.h"
#include "common/IniLoader.h"
#include <QDebug>

LogSqlTableModel::LogSqlTableModel(QObject *parent) :
    SSqlTableModel(parent)
{
    mAdvancedKey = new DbLogKey;
}

LogSqlTableModel::~LogSqlTableModel()
{

}

bool LogSqlTableModel::setAdvancedKey(DbRec *key)
{
    DbLogKey *oldKey = dynamic_cast<DbLogKey*>(mAdvancedKey);
    if (!oldKey)
        return false;

    DbLogKey *newKey = dynamic_cast<DbLogKey*>(key);
    if (!newKey)
        return false;

    *(oldKey) = *(newKey);
    return true;
}

QString LogSqlTableModel::tableName() const
{
    return "log";
}

void LogSqlTableModel::rowInfo(const int row, DbRec *info)
{

}

void LogSqlTableModel::print(QTextDocument *doc)
{

}

bool LogSqlTableModel::selectByAdvancedKey()
{
    //check key
    DbLogKey *key = dynamic_cast<DbLogKey*>(mAdvancedKey);
    if (!key)
        return false;

    //run query
    QString fields = QString("id, user_id, library_id, operation, update_time");
    QString filter = QString("operation like '%%1%'").arg(key->operation.value.toString());
    QString cmd = QString("select %1 from %2 where %3 order by update_time limit %4 offset %5;")
            .arg(fields)
            .arg(tableName())
            .arg(filter)
            .arg(maxRecPerpage())
            .arg(offset());
    QSqlQuery q(mDatabase);
    q.exec(QString("use %1;").arg(IniLoader::loadCurrentDbName()));
    if (!q.exec(cmd)) {
        qDebug() << q.lastError().text();
        return false;
    }
    beginResetModel();
    mQuery = q;
    endResetModel();

    //get total record count
    cmd = QString("select COUNT(1) from %1 where %2;")
            .arg(tableName())
            .arg(filter);
    if (!q.exec(cmd)) {
        qDebug() << q.lastError().text();
        return false;
    }
    if (q.next())
        setTotalRecCount(q.value(0).toInt());

    return true;
}
