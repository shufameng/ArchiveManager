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
    bool selectDAG(const QString &dbName, DbDag &info);     /* ���ݵ����ݵ����ݿ����Ƽ�����������Ϣ */
    bool selectMJ(QStringList &items);                                    /* ������������ܼ� */
    bool selectBGQX(QStringList &items);                                /* ����������б������� */
    bool selectJGLB(QStringList &items);                                /* ����������л������ */
    bool selectQZH(QStringList &items);                                  /* �����������ȫ�ں� */

    // get info
    void getDAG(DbDag &info);                                           /* �Ӳ�ѯ����л�ȡ��������Ϣ */
    void getQZ(DbQz &info);                                             /* �Ӳ�ѯ����л�ȡȫ����Ϣ */
    void getAJ(DbAj &info);                                                     /* �Ӳ�ѯ����л�ȡ������Ϣ */
    void getJNWJ(DbJnwj &info);                                     /* �Ӳ�ѯ����л�ȡ�����ļ���Ϣ */
    void getMedia(DbMedia &info);                                       /* �Ӳ�ѯ����л�ȡ�����ĵ���Ϣ */
    void getLog(DbLog &info);                                           /* �Ӳ�ѯ����л�ȡ��־��Ϣ */
    void getCDJL(DbCdjl &info);                                         /* �Ӳ�ѯ����л�ȡ�鵵��¼��Ϣ */
    void getUser(DbUser &info);                                         /* �Ӳ�ѯ����л�ȡ�û���Ϣ */
};

#endif // DBQUERY_H
