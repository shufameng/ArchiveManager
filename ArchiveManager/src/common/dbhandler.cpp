#include "DbHandler.h"
#include "IniLoader.h"

QMutex DbHandler::sg_dbMutex;

DbHandler::DbHandler()
{

}

QSqlDatabase DbHandler::addDbAndConnect()
{
    sg_dbMutex.lock();
    for (int i = 0; ; i++) {
        QString cnctName = QString("am_mysql_db_connection_%1").arg(i);
        if (!QSqlDatabase::contains(cnctName)) {
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", cnctName);
            sg_dbMutex.unlock();

            DbNetConfig conf = IniLoader::loadDbNetConfig();
            db.setHostName(conf.host);
            db.setPort(conf.port);
            db.setUserName(conf.user);
            db.setPassword(conf.passwd);
            if (!db.open())
                qDebug() << db.lastError().text();
            return db;
        }
    }
}

QSqlDatabase DbHandler::openDb(const QString &cnctName)
{
    QSqlDatabase db;
    sg_dbMutex.lock();
    if (QSqlDatabase::contains(cnctName))
        db = QSqlDatabase::database(cnctName);
    else
        db = QSqlDatabase::addDatabase("QMYSQL", cnctName);
    sg_dbMutex.unlock();

    DbNetConfig conf = IniLoader::loadDbNetConfig();
    db.setHostName(conf.host);
    db.setPort(conf.port);
    db.setUserName(conf.user);
    db.setPassword(conf.passwd);
    if (!db.open())
        qDebug() << db.lastError().text();
    return db;
}

void DbHandler::removeDb(const QString &cnctName)
{
    sg_dbMutex.lock();
    QSqlDatabase::removeDatabase(cnctName);
    sg_dbMutex.unlock();
}

