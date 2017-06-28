#ifndef DBTYPES_H
#define DBTYPES_H

#include <QString>
#include <QVariant>


enum enUserRole {
    enNormalUser = 1,
    enOperatorUser,
    enAdminUser
};

enum enDaType {
    ArchiveFonds = 100,
    ArchiveCatalog,
    ArchiveBox,
    ArchiveBox_KuaiJiAnJuan,
    ArchiveBox_KeJiAnJuan,
    ArchiveBox_WenShuAnJuan,
    ArchiveBook,
    ArchiveBook_KuaiJiDangAn,
    ArchiveBook_YiGuRenYuanDangAn,
    ArchiveBook_JiJianDangAn,
    ArchiveBook_ZhaoPianDangAn,
    ArchiveBook_KeJiDangAn,
    ArchiveBook_WenShuDangAn,
    ArchiveArchv_WenShu,
    ArchiveBook_GuiDangWenJian,
    ArchiveBox_GuiDangAnJuan,
    ArchiveAllTypes
};


//
class Field
{
public:
    Field() : maxLength(64)
    {}

    QString dbFieldName;
    QString userDefName;
    QVariant value;
    int         maxLength;
};
//

//
class DbRec
{
public:
    DbRec();

    virtual bool isInvalid() {
        return false;
    }

    QString tableName;
    Field id;
    Field createTime;
    Field updateTime;
};
//

//
class DbDag : public DbRec
{
public:
    DbDag();

    Field dbName;
    Field libraryName;
    Field remarks;
};
//

//
class DbQz : public DbRec
{
public:
    DbQz();

    Field qzh;//全宗号
    Field qztm;//题名
    Field kfh;//库房号
    Field pjh;//排架号
    Field qssj;//起始时间
    Field zzsj;//终止时间
    Field bz;//备注
};

//
class DbMl : public DbRec
{
public:
    DbMl();

    Field type;
    Field qzh;
    Field mlh;
};
//

//
class DbAj : public DbRec
{
public:
    DbAj();

    Field type;//案卷类型
    Field qzh;//全宗号
    Field mlh;//目录号
    Field ajh;// 案卷号
    Field tm;//题名
    Field bgqx;//保管期限
    Field jglb;//机构类别
    Field zrz;//责任者
    Field nd;//年度
    Field ys;//页数
    Field gdh;//归档号
    Field flh;//分类号
    Field qssj;//起始时间
    Field zzsj;//终止时间
    Field dagdm;//档案馆代码
    Field kfh;//库房号
    Field pjh;//排架号
    Field bz;//备注
    Field jgwt;//机构问题
    Field mldm;//档案馆门类代码
};
//

//
class DbJnwj : public DbRec
{
public:
    DbJnwj();

    Field type;//档案类型
    Field qzh;//全宗号
    Field mlh;//目录号
    Field ajh;//案卷号
    Field jh;//件号
    Field tm;//题名
    Field zrz;//责任者
    Field bgqx;//保管期限
    Field jglb;//机构类别
    Field mj;//密级
    Field wh;//文号
    Field nd;//年度
    Field gdh;//归档号
    Field ztlx;//载体类型
    Field flh;//分类号
    Field ztc;//主题词
    Field sj;//时间
    Field dh;//档号
    Field wsh;//微缩号
    Field yh;//页号
    Field zs;//张数
    Field kfh;//库房号
    Field pjh;//排架号
    Field bz;//备注
    Field jgwt;//机构问题
    Field mldm;//档案馆门类代码

    QString ocrKey;//ocr搜索关键字
};
//

//
class DbGdwj : public DbJnwj
{
public:
    DbGdwj();
};
//

//
class DbMedia : public DbGdwj
{
public:
    enum Type {
        JNWJ = 1, GDWJ = 2
    };

    DbMedia();

    Field fileName;
    Field ocrText;
};
//

//
class DbUser : public DbRec
{
public:
    DbUser();

    Field name;
    Field role;
    Field password;
    Field remarks;
};
//

//
class DbLog : public DbRec
{
public:
    DbLog();
    DbLog(const qint64 userId, const qint64 libraryId, const QString &op);

    DbUser user;
    DbDag dag;
    Field operation;
};
//

//
class DbLogKey : public DbLog
{
public:
    DbLogKey();

    QString startTime;
    QString endTime;
};
//

//
class DbCdjl : public DbRec
{
public:
    DbCdjl();

    Field qzh;//全宗号
    Field mlh;//目录号
    Field ajh;//案卷号
    Field jh;//件号
    Field customer;//查档人
    Field idCardNum;//查档人身份证号码
    Field operateReason;//查档原因
    Field operatePerson;//操作人员
    Field operateTime;//查档时间
    Field remarks;//备注
};
//

//
class DbCdjlKey : public DbCdjl
{
public:
    DbCdjlKey();
};
//

//

//

//

//

//

//

//

//

//






#endif // DBTYPES_H
