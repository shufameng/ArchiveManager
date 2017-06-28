#include "QzSqlTableModel.h"
#include "common/DbTypes.h"
#include "common/IniLoader.h"
#include <QDebug>
#include <QTextCursor>

QzSqlTableModel::QzSqlTableModel(QWidget *parent) :
    SSqlTableModel(parent)
{
    mAdvancedKey = new DbQz;
}

QzSqlTableModel::~QzSqlTableModel()
{

}

bool QzSqlTableModel::setAdvancedKey(DbRec *key)
{
    DbQz *oldKey = dynamic_cast<DbQz*>(mAdvancedKey);
    if (!oldKey)
        return false;

    DbQz *newKey = dynamic_cast<DbQz*>(key);
    if (!newKey)
        return false;

    *(oldKey) = *(newKey);
    return true;
}

QString QzSqlTableModel::tableName() const
{
    return "archive_fonds";
}

void QzSqlTableModel::rowInfo(const int row, DbRec *info)
{
    DbQz *p = dynamic_cast<DbQz*>(info);
    if (!info)
        return;

    p->id.value = index(row, 0).data().toLongLong();
    p->qzh.value = index(row, 1).data().toString();
    p->qztm.value = index(row, 2).data().toString();
    p->kfh.value = index(row, 3).data().toString();
    p->pjh.value = index(row, 4).data().toString();
    p->qssj.value = index(row, 5).data().toString();
    p->zzsj.value = index(row, 6).data().toString();
    p->bz.value = index(row, 7).data().toString();
    p->createTime.value = index(row, 8).data().toString();
    p->updateTime.value = index(row, 9).data().toString();
}

void QzSqlTableModel::print(QTextDocument *doc)
{
    //ID,qzh,qztm,kfh,pjh,qssj,zzsj,bz,create_time,update_time
    QTextCursor cs(doc);
    cs.insertHtml(QString("<center><h1>%1<br/></h1></center>").arg(tr("Fonds Table")));
    cs.movePosition(QTextCursor::NextRow, QTextCursor::MoveAnchor, 1);

    int count = rowCount();
    int columnCount = 5;
    QTextTableFormat tableFmt;
    tableFmt.setAlignment(Qt::AlignLeft);
    tableFmt.setCellPadding(12);
    tableFmt.setCellSpacing(0);
    cs.insertTable(count + 1,columnCount, tableFmt);

    cs.movePosition(QTextCursor::StartOfBlock, QTextCursor::MoveAnchor, 1);
    cs.insertText(headerData(1, Qt::Horizontal).toString());
    cs.movePosition(QTextCursor::NextCell, QTextCursor::MoveAnchor, 1);
    cs.insertText(headerData(2, Qt::Horizontal).toString());
    cs.movePosition(QTextCursor::NextCell, QTextCursor::MoveAnchor, 1);
    cs.insertText(headerData(5, Qt::Horizontal).toString());
    cs.movePosition(QTextCursor::NextCell, QTextCursor::MoveAnchor, 1);
    cs.insertText(headerData(6, Qt::Horizontal).toString());
    cs.movePosition(QTextCursor::NextCell, QTextCursor::MoveAnchor, 1);
    cs.insertText(headerData(7, Qt::Horizontal).toString());
    cs.movePosition(QTextCursor::NextRow, QTextCursor::MoveAnchor, 1);

    for (int r = 0; r < count; r++) {
        cs.insertText(data(index(r, 1)).toString());
        cs.movePosition(QTextCursor::NextCell, QTextCursor::MoveAnchor, 1);
        cs.insertText(data(index(r, 2)).toString());
        cs.movePosition(QTextCursor::NextCell, QTextCursor::MoveAnchor, 1);
        cs.insertText(data(index(r, 5)).toString());
        cs.movePosition(QTextCursor::NextCell, QTextCursor::MoveAnchor, 1);
        cs.insertText(data(index(r, 6)).toString());
        cs.movePosition(QTextCursor::NextCell, QTextCursor::MoveAnchor, 1);
        cs.insertText(data(index(r, 7)).toString());
        cs.movePosition(QTextCursor::NextRow, QTextCursor::MoveAnchor, 1);
    }
}

bool QzSqlTableModel::selectByAdvancedKey()
{
    //check key
    DbQz *key = dynamic_cast<DbQz*>(mAdvancedKey);
    if (!key)
        return false;

    //run query
    QString fields = QString("ID,qzh,qztm,kfh,pjh,qssj,zzsj,bz,create_time,update_time");
    QString filter = QString("IFNULL(qzh, '') like '%1' and IFNULL(qztm, '') like '%2' and IFNULL(kfh, '') like '%3' "
                             "and IFNULL(pjh, '') like '%4' and IFNULL(qssj, '') like '%5' and IFNULL(zzsj, '') like '%6' "
                             "and IFNULL(bz, '') like '%7' ")
            .arg("%" + key->qzh.value.toString() + "%")
            .arg("%" + key->qztm.value.toString() + "%")
            .arg("%" + key->kfh.value.toString() + "%")
            .arg("%" + key->pjh.value.toString() + "%")
            .arg("%" + key->qssj.value.toString() + "%")
            .arg("%" + key->zzsj.value.toString() + "%")
            .arg("%" + key->bz.value.toString() + "%");
    QString cmd = QString("select %1 from %2 where %3 order by qzh limit %4 offset %5;")
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

