#ifndef DBQUERY_H
#define DBQUERY_H

#include <QtSql>
#include "dbtypes.h"

class DbQuery : public QSqlQuery
{
public:
    explicit DbQuery(QSqlDatabase db);

    // common use
    bool prepare2(const QString &query);
    bool exec2();
    bool exec2(const QString &query);
    bool useDefaultDb();
    bool useCurrentDb();

    // insert
    bool insertQZ(const DbQz &info);
    bool insertAJ(const DbAj &info);
    bool insertJnwj(const DbJnwj &info);
    bool insertGdwj(const DbGdwj &info);
    bool insertMedia(const DbMedia &info);
    bool insertDAG(const DbDag &info);
    bool insertUser(const DbUser &info);
    bool insertLog(const DbLog &info);
    bool insertCDJL(const DbCdjl &info);

    // select
    bool selectDAG(const QString &dbName, DbDag &info);     /* 根据档案馆的数据库名称检索档案馆信息 */
    bool selectMJ(QStringList &items);                                    /* 检索获得所有密级 */
    bool selectBGQX(QStringList &items);                                /* 检索获得所有保管期限 */
    bool selectJGLB(QStringList &items);                                /* 检索获得所有机构类别 */
    bool selectQZH(QStringList &items);                                  /* 检索获得所有全宗号 */

    // get info
    void getDAG(DbDag &info);                                           /* 从查询结果中获取档案馆信息 */
    void getQZ(DbQz &info);                                             /* 从查询结果中获取全宗信息 */
    void getAJ(DbAj &info);                                                     /* 从查询结果中获取案卷信息 */
    void getJNWJ(DbJnwj &info);                                     /* 从查询结果中获取卷内文件信息 */
    void getMedia(DbMedia &info);                                       /* 从查询结果中获取电子文档信息 */
    void getLog(DbLog &info);                                           /* 从查询结果中获取日志信息 */
    void getCDJL(DbCdjl &info);                                         /* 从查询结果中获取查档记录信息 */
    void getUser(DbUser &info);                                         /* 从查询结果中获取用户信息 */
};

#endif // DBQUERY_H
