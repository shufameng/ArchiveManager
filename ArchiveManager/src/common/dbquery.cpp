#include "dbquery.h"
#include <QDebug>
#include "iniloader.h"

DbQuery::DbQuery(QSqlDatabase db) :
    QSqlQuery(db)
{

}

bool DbQuery::prepare2(const QString &query)
{
    if (!prepare(query)) {
        qDebug() << lastQuery();
        qDebug() << lastError().text();
        return false;
    } else {
        return true;
    }
}

bool DbQuery::exec2()
{
    if (!exec()) {
        qDebug() << lastQuery();
        qDebug() << lastError().text();
        return false;
    } else {
        return true;
    }
}

bool DbQuery::exec2(const QString &query)
{
    if (!exec(query)) {
        qDebug() << lastQuery();
        qDebug() << lastError().text();
        return false;
    } else {
        return true;
    }
}

bool DbQuery::useDefaultDb()
{
    return exec2(QString("use %1;").arg(IniLoader::loadDefaultDbName()));
}

bool DbQuery::useCurrentDb()
{
    return exec2(QString("use %1;").arg(IniLoader::loadCurrentDbName()));
}

bool DbQuery::selectDAG(const QString &dbName, DbDag &info)
{
    QString cmd = QString("select * from %1 where %2 = '%3';")
            .arg(info.tableName)
            .arg(info.dbName.dbFieldName)
            .arg(dbName);
    if (!useDefaultDb())
        return false;
    if (!exec2(cmd))
        return false;
    if (next())
        getDAG(info);
    return true;
}

bool DbQuery::selectMJ(QStringList &items)
{
    if (!useCurrentDb())
        return false;
    if (!exec2("select distinct name from secret_level;"))
        return false;
    while (next())
        items.append(value(0).toString());
    return true;
}

bool DbQuery::selectBGQX(QStringList &items)
{
    if (!useCurrentDb())
        return false;
    if (!exec2("select distinct name from time_limit;"))
        return false;
    while (next())
        items.append(value(0).toString());
    return true;
}

bool DbQuery::selectJGLB(QStringList &items)
{
    if (!useCurrentDb())
        return false;
    if (!exec2("select distinct name from org_type;"))
        return false;
    while (next())
        items.append(value(0).toString());
    return true;
}

bool DbQuery::selectQZH(QStringList &items)
{
    if (!useCurrentDb())
        return false;
    if (!exec2("select distinct qzh from archive_fonds;"))
        return false;
    while (next()) {
        items.append(value(0).toString());
    }
    return true;
}

void DbQuery::getDAG(DbDag &info)
{
    info.id.value                       = value(info.id.dbFieldName);
    info.libraryName.value      = value(info.libraryName.dbFieldName);
    info.dbName.value               = value(info.dbName.dbFieldName);
    info.remarks.value               = value(info.remarks.dbFieldName);
    if (!value(info.createTime.dbFieldName).isNull())
        info.createTime.value       = value(info.createTime.dbFieldName);
    if (!value(info.updateTime.dbFieldName).isNull())
        info.updateTime.value       = value(info.updateTime.dbFieldName);
}

void DbQuery::getQZ(DbQz &info)
{
    info.id.value                   = value(info.id.dbFieldName);
    info.qzh.value                  = value(info.qzh.dbFieldName);
    info.qztm.value             = value(info.qztm.dbFieldName);
    info.kfh.value              = value(info.kfh.dbFieldName);
    info.pjh.value              = value(info.pjh.dbFieldName);
    info.qssj.value             = value(info.qssj.dbFieldName);
    info.zzsj.value             = value(info.zzsj.dbFieldName);
    info.bz.value               = value(info.bz.dbFieldName);
    info.createTime.value         = value(info.createTime.dbFieldName);
    info.updateTime.value         = value(info.updateTime.dbFieldName);
}

void DbQuery::getAJ(DbAj &info)
{
    info.id.value               = value(info.id.dbFieldName);
    info.type.value         = value(info.type.dbFieldName);
    info.qzh.value          = value(info.qzh.dbFieldName);
    info.mlh.value          = value(info.mlh.dbFieldName);
    info.ajh.value          = value(info.ajh.dbFieldName);
    info.tm.value           = value(info.tm.dbFieldName);
    info.jglb.value         = value(info.jglb.dbFieldName);
    info.nd.value           = value(info.nd.dbFieldName);
    info.ys.value           = value(info.ys.dbFieldName);
    info.gdh.value          = value(info.gdh.dbFieldName);
    info.flh.value          = value(info.flh.dbFieldName);
    info.qssj.value         = value(info.qssj.dbFieldName);
    info.zzsj.value         = value(info.zzsj.dbFieldName);
    info.bgqx.value         = value(info.bgqx.dbFieldName);
    info.dagdm.value     = value(info.dagdm.dbFieldName);
    info.zrz.value          = value(info.zrz.dbFieldName);
    info.kfh.value          = value(info.kfh.dbFieldName);
    info.pjh.value          = value(info.pjh.dbFieldName);
    info.bz.value           = value(info.bz.dbFieldName);
    info.createTime.value    = value(info.createTime.dbFieldName);
    info.updateTime.value    = value(info.updateTime.dbFieldName);
}

void DbQuery::getJNWJ(DbJnwj &info)
{
    info.id.value               = value(info.id.dbFieldName);
    info.type.value             = value(info.type.dbFieldName);
    info.qzh.value              = value(info.qzh.dbFieldName);
    info.mlh.value              = value(info.mlh.dbFieldName);
    info.ajh.value              = value(info.ajh.dbFieldName);
    info.jh.value               = value(info.jh.dbFieldName);
    info.tm.value               = value(info.tm.dbFieldName);
    info.zrz.value              = value(info.zrz.dbFieldName);
    info.bgqx.value         = value(info.bgqx.dbFieldName);
    info.jglb.value             = value(info.jglb.dbFieldName);
    info.mj.value            = value(info.mj.dbFieldName);
    info.wh.value           = value(info.wh.dbFieldName);
    info.nd.value            = value(info.nd.dbFieldName);
    info.gdh.value          = value(info.gdh.dbFieldName);
    info.ztlx.value         = value(info.ztlx.dbFieldName);
    info.flh.value       = value(info.flh.dbFieldName);
    info.ztc.value       = value(info.ztc.dbFieldName);
    info.sj.value           = value(info.sj.dbFieldName);
    info.dh.value           = value(info.dh.dbFieldName);
    info.wsh.value          = value(info.wsh.dbFieldName);
    info.yh.value           = value(info.yh.dbFieldName);
    info.zs.value           = value(info.zs.dbFieldName);
    info.kfh.value          = value(info.kfh.dbFieldName);
    info.pjh.value          = value(info.pjh.dbFieldName);
    info.bz.value           = value(info.bz.dbFieldName);
    info.createTime.value = value(info.createTime.dbFieldName);
    info.updateTime.value = value(info.updateTime.dbFieldName);
}

void DbQuery::getMedia(DbMedia &info)
{
    info.id.value           = value(info.id.dbFieldName);
    info.type.value         = value(info.type.dbFieldName);
    info.qzh.value          = value(info.qzh.dbFieldName);
    info.mlh.value          = value(info.mlh.dbFieldName);
    info.ajh.value          = value(info.ajh.dbFieldName);
    info.jh.value           = value(info.jh.dbFieldName);
    info.fileName.value = value(info.fileName.dbFieldName);
    info.ocrText.value  = value(info.ocrText.dbFieldName);
}

void DbQuery::getLog(DbLog &info)
{
    info.id.value           = value(info.id.dbFieldName);
    info.user.id.value            = value("user_id");
    info.dag.id.value             = value("library_id");
    info.operation.value = value(info.operation.dbFieldName);
    info.updateTime.value = value(info.updateTime.dbFieldName);
}

void DbQuery::getCDJL(DbCdjl &info)
{
    info.id.value           = value(info.id.dbFieldName);
    info.qzh.value          = value(info.qzh.dbFieldName);
    info.mlh.value          = value(info.mlh.dbFieldName);
    info.ajh.value          = value(info.ajh.dbFieldName);
    info.jh.value           = value(info.jh.dbFieldName);
    info.customer.value = value(info.customer.dbFieldName);
    info.idCardNum.value = value(info.idCardNum.dbFieldName);
    info.operateReason.value = value(info.operateReason.dbFieldName);
    info.operatePerson.value = value(info.operatePerson.dbFieldName);
    info.operateTime.value = value(info.operateTime.dbFieldName);
    info.remarks.value      = value(info.remarks.dbFieldName);
}

void DbQuery::getUser(DbUser &info)
{
    info.id.value           = value(info.id.dbFieldName);
    info.name.value     = value(info.name.dbFieldName);
    info.role.value         = value(info.role.dbFieldName);
    info.password.value = value(info.password.dbFieldName);
    info.remarks.value  = value(info.remarks.dbFieldName);
    info.updateTime.value = value(info.updateTime.dbFieldName);
}

