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

bool DbQuery::insertQZ(const DbQz &info)
{
    if (!useCurrentDb())
        return false;
    if (!prepare2("insert into archive_fonds(qzh,qztm,kfh,pjh,qssj,zzsj,bz,create_time) values(?,?,?,?,?,?,?,?);"))
        return false;
    int i = 0;
    bindValue(i++, info.qzh.value);
    bindValue(i++, info.qztm.value);
    bindValue(i++, info.kfh.value);
    bindValue(i++, info.pjh.value);
    bindValue(i++, info.qssj.value);
    bindValue(i++, info.zzsj.value);
    bindValue(i++, info.bz.value);
    bindValue(i++, QDateTime::currentDateTime());
    if (!exec2())
        return false;
    return true;
}

bool DbQuery::insertAJ(const DbAj &info)
{
    if (!useCurrentDb())
        return false;
    if (!prepare2("insert into archive_box"
                          "(type,qzh,mlh,ajh,tm,bgqx,jglb,zrz,nd,ys,gdh,flh,qssj,zzsj,dagdm,kfh,pjh,bz,jgwt,mldm,create_time) "
                          "values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);"))
        return false;
    int i = 0;
    bindValue(i++, info.type.value);
    bindValue(i++, info.qzh.value);
    bindValue(i++, info.mlh.value);
    bindValue(i++, info.ajh.value);
    bindValue(i++, info.tm.value);
    bindValue(i++, info.bgqx.value);
    bindValue(i++, info.jglb.value);
    bindValue(i++, info.zrz.value);
    bindValue(i++, info.nd.value);
    bindValue(i++, info.ys.value);
    bindValue(i++, info.gdh.value);
    bindValue(i++, info.flh.value);
    bindValue(i++, info.qssj.value);
    bindValue(i++, info.zzsj.value);
    bindValue(i++, info.dagdm.value);
    bindValue(i++, info.kfh.value);
    bindValue(i++, info.pjh.value);
    bindValue(i++, info.bz.value);
    bindValue(i++, info.jgwt.value);
    bindValue(i++, info.mldm.value);
    bindValue(i++, QDateTime::currentDateTime());
    if (!exec2())
        return false;
    return true;
}

bool DbQuery::insertJnwj(const DbJnwj &info)
{
    if (!useCurrentDb())
        return false;
    if (!prepare2("insert into archive_book"
                          "(type,qzh,mlh,ajh,jh,tm,zrz,bgqx,jglb,mj,wh,nd,gdh,ztlx,flh,ztc,sj,dh,wsh,yh,zs,kfh,pjh,bz,jgwt,mldm,create_time) "
                          "values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);"))
        return false;
    int i = 0;
    bindValue(i++, info.type.value);
    bindValue(i++, info.qzh.value);
    bindValue(i++, info.mlh.value);
    bindValue(i++, info.ajh.value);
    bindValue(i++, info.jh.value);
    bindValue(i++, info.tm.value);
    bindValue(i++, info.zrz.value);
    bindValue(i++, info.bgqx.value);
    bindValue(i++, info.jglb.value);
    bindValue(i++, info.mj.value);
    bindValue(i++, info.wh.value);
    bindValue(i++, info.nd.value);
    bindValue(i++, info.gdh.value);
    bindValue(i++, info.ztlx.value);
    bindValue(i++, info.flh.value);
    bindValue(i++, info.ztc.value);
    bindValue(i++, info.sj.value);
    bindValue(i++, info.dh.value);
    bindValue(i++, info.wsh.value);
    bindValue(i++, info.yh.value);
    bindValue(i++, info.zs.value);
    bindValue(i++, info.kfh.value);
    bindValue(i++, info.pjh.value);
    bindValue(i++, info.bz.value);
    bindValue(i++, info.jgwt.value);
    bindValue(i++, info.mldm.value);
    bindValue(i++, QDateTime::currentDateTime());
    if (!exec2())
        return false;
    return true;
}

bool DbQuery::insertGdwj(const DbGdwj &info)
{
    if (!useCurrentDb())
        return false;
    if (!prepare2("insert into archive_book"
                          "(type,qzh,mlh,ajh,jh,tm,zrz,bgqx,jglb,mj,wh,nd,gdh,ztlx,flh,ztc,sj,dh,wsh,yh,zs,kfh,pjh,bz,jgwt,mldm,create_time) "
                          "values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);"))
        return false;
    int i = 0;
    bindValue(i++, info.type.value);
    bindValue(i++, info.qzh.value);
    bindValue(i++, info.mlh.value);
    bindValue(i++, info.ajh.value);
    bindValue(i++, info.jh.value);
    bindValue(i++, info.tm.value);
    bindValue(i++, info.zrz.value);
    bindValue(i++, info.bgqx.value);
    bindValue(i++, info.jglb.value);
    bindValue(i++, info.mj.value);
    bindValue(i++, info.wh.value);
    bindValue(i++, info.nd.value);
    bindValue(i++, info.gdh.value);
    bindValue(i++, info.ztlx.value);
    bindValue(i++, info.flh.value);
    bindValue(i++, info.ztc.value);
    bindValue(i++, info.sj.value);
    bindValue(i++, info.dh.value);
    bindValue(i++, info.wsh.value);
    bindValue(i++, info.yh.value);
    bindValue(i++, info.zs.value);
    bindValue(i++, info.kfh.value);
    bindValue(i++, info.pjh.value);
    bindValue(i++, info.bz.value);
    bindValue(i++, info.jgwt.value);
    bindValue(i++, info.mldm.value);
    bindValue(i++, QDateTime::currentDateTime());
    if (!exec2())
        return false;
    return true;
}

bool DbQuery::insertMedia(const DbMedia &info)
{
    if (!useCurrentDb())
        return false;
    if (!prepare2("insert into archive_media(qzh,mlh,ajh,jh,wjm,dalx) values(?,?,?,?,?,?);"))
        return false;
    int i = 0;
    bindValue(i++, info.qzh.value);
    bindValue(i++, info.mlh.value);
    bindValue(i++, info.ajh.value);
    bindValue(i++, info.jh.value);
    bindValue(i++, info.fileName.value);
    bindValue(i++, info.type.value);
    if (!exec2())
        return false;
    return true;
}

bool DbQuery::insertDAG(const DbDag &info)
{
    return true;
}

bool DbQuery::insertUser(const DbUser &info)
{
    return true;
}

bool DbQuery::insertLog(const DbLog &info)
{
    if (!useDefaultDb())
        return false;

    if (!prepare2("insert into log(user_id,library_id,operation) values(?,?,?);"))
        return false;
    bindValue(0, info.user.id.value);
    bindValue(1, info.dag.id.value);
    bindValue(2, info.operation.value);
    if (!exec2())
        return false;

    return true;
}

bool DbQuery::insertCDJL(const DbCdjl &info)
{
    if (!useCurrentDb())
        return false;

    if (!prepare2("insert into archive_borrow"
                          "(qzh,mlh,ajh,jh,borrower,id_card_num,approver,borrow_reason,return_sign,borrow_time,planned_return_time,actually_return_time,is_returned,remarks) "
                          "values(?,?,?,?,?,?,?,?,?,?,?,?,?,?);"))
        return false;
    int i = 0;
    bindValue(i++, info.qzh.value);
    bindValue(i++, info.mlh.value);
    bindValue(i++, info.ajh.value);
    bindValue(i++, info.jh.value);
    bindValue(i++, info.customer.value);
    bindValue(i++, info.idCardNum.value);
    bindValue(i++, info.operatePerson.value);
    bindValue(i++, info.operateReason.value);
    bindValue(i++, QVariant());
    bindValue(i++, QVariant());
    bindValue(i++, QVariant());
    bindValue(i++, QVariant());
    bindValue(i++, QVariant());
    bindValue(i++, info.remarks.value);
    if (!exec2())
        return false;

    return true;
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

