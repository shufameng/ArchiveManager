#include "GdwjSqlTableModel.h"
#include "common/DbTypes.h"
#include "common/IniLoader.h"
#include <QDebug>


GdwjSqlTableModel::GdwjSqlTableModel(QObject *parent) :
    SSqlTableModel(parent)
{
    mAdvancedKey = new DbGdwj;
}

GdwjSqlTableModel::~GdwjSqlTableModel()
{

}

bool GdwjSqlTableModel::setAdvancedKey(DbRec *key)
{
    DbGdwj *oldKey = dynamic_cast<DbGdwj*>(mAdvancedKey);
    if (!oldKey)
        return false;

    DbGdwj *newKey = dynamic_cast<DbGdwj*>(key);
    if (!newKey)
        return false;

    *(oldKey) = *(newKey);
    return true;
}

QString GdwjSqlTableModel::tableName() const
{
    return "archive_book";
}

void GdwjSqlTableModel::rowInfo(const int row, DbRec *info)
{

}

void GdwjSqlTableModel::print(QTextDocument *doc)
{

}

bool GdwjSqlTableModel::useOcr()
{
    DbGdwj *key = dynamic_cast<DbGdwj*>(mAdvancedKey);
    if (!key)
        return false;

    return (!key->ocrKey.isEmpty());
}

bool GdwjSqlTableModel::selectByAdvancedKey()
{
    //check key
    DbGdwj *key = dynamic_cast<DbGdwj*>(mAdvancedKey);
    if (!key)
        return false;

    //run query
    QString fields = QString("ID,type,qzh,mlh,ajh,jh,tm,zrz,bgqx,jglb,mj,wh,nd,gdh,ztlx,flh,ztc,sj,dh,wsh,yh,zs,kfh,pjh,bz,jgwt,mldm,create_time,update_time");
    QString filter = QString("type = %1 and IFNULL(qzh,'') like '%2' and IFNULL(mlh,'') like '%3' "
                   "and IFNULL(ajh,'') like '%4' and IFNULL(jh,'') like '%5' and IFNULL(tm,'') like '%6' "
                   "and IFNULL(zrz,'') like '%7' and IFNULL(bgqx,'') like '%8' and IFNULL(jglb,'') like '%9' "
                   "and IFNULL(mj,'') like '%10' and IFNULL(wh,'') like '%11' and IFNULL(nd,'') like '%12' "
                   "and IFNULL(gdh,'') like '%13' and IFNULL(ztlx,'') like '%14' and IFNULL(flh,'') like '%15' "
                   "and IFNULL(ztc,'') like '%16' and IFNULL(sj,'') like '%17' and IFNULL(dh,'') like '%18' "
                   "and IFNULL(wsh,'') like '%19' and IFNULL(yh,'') like '%20' and IFNULL(zs,'') like '%21' "
                   "and IFNULL(kfh,'') like '%22' and IFNULL(pjh,'') like '%23' and IFNULL(bz,'') like '%24' ")
            .arg(ArchiveBook_GuiDangWenJian)
            .arg("%" + key->qzh.value.toString() + "%")
            .arg("%" + key->mlh.value.toString() + "%")
            .arg("%" + key->ajh.value.toString() + "%")
            .arg("%" + key->jh.value.toString() + "%")
            .arg("%" + key->tm.value.toString() + "%")
            .arg("%" + key->zrz.value.toString() + "%")
            .arg("%" + key->bgqx.value.toString() + "%")
            .arg("%" + key->jglb.value.toString() + "%")
            .arg("%" + key->mj.value.toString() + "%")
            .arg("%" + key->wh.value.toString() + "%")
            .arg("%" + key->nd.value.toString() + "%")
            .arg("%" + key->gdh.value.toString() + "%")
            .arg("%" + key->ztlx.value.toString() + "%")
            .arg("%" + key->flh.value.toString() + "%")
            .arg("%" + key->ztc.value.toString() + "%")
            .arg("%" + key->sj.value.toString() + "%")
            .arg("%" + key->dh.value.toString() + "%")
            .arg("%" + key->wsh.value.toString() + "%")
            .arg("%" + key->yh.value.toString() + "%")
            .arg("%" + key->zs.value.toString() + "%")
            .arg("%" + key->kfh.value.toString() + "%")
            .arg("%" + key->pjh.value.toString() + "%")
            .arg("%" + key->bz.value.toString() + "%");

    if (!key->ocrKey.trimmed().isEmpty()) {
        QString extraFilter = QString("and (select count(1) from archive_media where ocr_text like %1 and archive_book.qzh = archive_media.qzh "
                                   "and archive_book.mlh = archive_media.mlh and archive_book.ajh = archive_media.ajh "
                                   "and archive_book.jh = archive_media.jh) > 0 ").arg("%" + key->ocrKey + "%");
        filter.append(extraFilter);
    }

    QString cmd = QString("select %1 from %2 where %3 order by qzh,mlh,ajh,jh limit %4 offset %5;")
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
    qDebug() << q.lastQuery();

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
