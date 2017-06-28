#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <QtSql>

class DbHandler
{
public:
    DbHandler();

    static QString dbConnectionName()           { return "am_qt_mysql_connection"; }
    static QSqlDatabase addDbAndConnect();
    static QSqlDatabase openDb(const QString &cnctName);
    static void removeDb(const QString &cnctName);

private:
    static QMutex sg_dbMutex;
};

#endif // DBHANDLER_H
