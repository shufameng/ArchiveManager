#include "AjSqlTableModel.h"
#include "common/DbTypes.h"
#include "common/iniLoader.h"

AjSqlTableModel::AjSqlTableModel(QObject *parent) :
    SSqlTableModel(parent)
{
    mAdvancedKey = new DbAj;
}

AjSqlTableModel::~AjSqlTableModel()
{

}

bool AjSqlTableModel::setAdvancedKey(DbRec *key)
{
    DbAj *oldKey = dynamic_cast<DbAj*>(mAdvancedKey);
    if (!oldKey)
        return false;

    DbAj *newKey = dynamic_cast<DbAj*>(key);
    if (!newKey)
        return false;

    *(oldKey) = *(newKey);
    return true;
}

QString AjSqlTableModel::tableName() const
{
    return "archive_box";
}

void AjSqlTableModel::rowInfo(const int row, DbRec *info)
{

}

void AjSqlTableModel::print(QTextDocument *doc)
{

}

bool AjSqlTableModel::selectByAdvancedKey()
{
    //check key
    DbAj *key = dynamic_cast<DbAj*>(mAdvancedKey);
    if (!key)
        return false;

    //run query
    QString fields = QString("ID,type,qzh,mlh,ajh,tm,bgqx,jglb,zrz,nd,ys,gdh,flh,qssj,zzsj,dagdm,kfh,pjh,bz,jgwt,mldm,create_time,update_time");
    QString filter = QString("IFNULL(qzh,'') like '%1' and IFNULL(mlh,'') like '%2' and IFNULL(ajh,'') like '%3' "
                             "and IFNULL(tm,'') like '%4' and IFNULL(bgqx,'') like '%5' and IFNULL(jglb,'') like '%6' "
                             "and IFNULL(zrz,'') like '%7' and IFNULL(nd,'') like '%8' and IFNULL(ys,'') like '%9' "
                             "and IFNULL(gdh,'') like '%10' and IFNULL(flh,'') like '%11' and IFNULL(qssj,'') like '%12' "
                             "and IFNULL(zzsj,'') like '%13' and IFNULL(dagdm,'') like '%14' and IFNULL(kfh,'') like '%15' "
                             "and IFNULL(pjh,'') like '%16' and IFNULL(bz,'') like '%17' and IFNULL(jgwt, '') like '%18' "
                             "and IFNULL(mldm,'') like '%19'")
            .arg("%" + key->qzh.value.toString() + "%")
            .arg("%" + key->mlh.value.toString() + "%")
            .arg("%" + key->ajh.value.toString() + "%")
            .arg("%" + key->tm.value.toString() + "%")
            .arg("%" + key->bgqx.value.toString() + "%")
            .arg("%" + key->jglb.value.toString() + "%")
            .arg("%" + key->zrz.value.toString() + "%")
            .arg("%" + key->nd.value.toString() + "%")
            .arg("%" + key->ys.value.toString() + "%")
            .arg("%" + key->gdh.value.toString() + "%")
            .arg("%" + key->flh.value.toString() + "%")
            .arg("%" + key->qssj.value.toString() + "%")
            .arg("%" + key->zzsj.value.toString() + "%")
            .arg("%" + key->dagdm.value.toString() + "%")
            .arg("%" + key->kfh.value.toString() + "%")
            .arg("%" + key->pjh.value.toString() + "%")
            .arg("%" + key->bz.value.toString() + "%")
            .arg("%" + key->jgwt.value.toString() + "%")
            .arg("%" + key->mldm.value.toString() + "%");

    QString cmd = QString("select %1 from %2 where %3 order by qzh, mlh, ajh limit %4 offset %5;")
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
