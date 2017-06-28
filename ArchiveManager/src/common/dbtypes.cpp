#include "DbTypes.h"


DbRec::DbRec()
{
    id.dbFieldName = "id";
    createTime.dbFieldName = "create_time";
    updateTime.dbFieldName = "update_time";
    id.userDefName = "ID";
    createTime.userDefName = QString::fromLocal8Bit("著录时间");
    updateTime.userDefName = QString::fromLocal8Bit("最后校对时间");
}

DbDag::DbDag() :
    DbRec()
{
    tableName = "archive_library";

    dbName.dbFieldName = "db_name";
    libraryName.dbFieldName = "name";
    remarks.dbFieldName = "remarks";

    dbName.userDefName = QString::fromLocal8Bit("数据库名称");
    libraryName.userDefName = QString::fromLocal8Bit("档案馆名称");
    remarks.userDefName = QString::fromLocal8Bit("备注");
}

DbQz::DbQz() :
    DbRec()
{
    tableName = "archive_fonds";

    qzh.dbFieldName = "qzh";
    qztm.dbFieldName = "qztm";
    kfh.dbFieldName = "kfh";
    pjh.dbFieldName = "pjh";
    qssj.dbFieldName = "qssj";
    zzsj.dbFieldName = "zzsj";
    bz.dbFieldName = "bz";

    qzh.userDefName = QString::fromLocal8Bit("全宗号");
    qztm.userDefName = QString::fromLocal8Bit("全宗题名");
    kfh.userDefName = QString::fromLocal8Bit("库房号");
    pjh.userDefName = QString::fromLocal8Bit("排架号");
    qssj.userDefName = QString::fromLocal8Bit("起始时间");
    zzsj.userDefName = QString::fromLocal8Bit("终止时间");
    bz.userDefName = QString::fromLocal8Bit("备注");
}

DbMl::DbMl() :
    DbRec()
{
    tableName = "";

    type.dbFieldName = "type";
    qzh.dbFieldName = "qzh";
    mlh.dbFieldName = "mlh";

    type.userDefName = QString::fromLocal8Bit("类型");
    qzh.userDefName = QString::fromLocal8Bit("全宗号");
    mlh.userDefName = QString::fromLocal8Bit("目录号");

    type.value = ArchiveCatalog;
}

DbAj::DbAj() :
    DbRec()
{
    tableName = "archive_box";

    type.dbFieldName = "type";
    qzh.dbFieldName = "qzh";
    mlh.dbFieldName = "mlh";
    ajh.dbFieldName = "ajh";
    tm.dbFieldName = "tm";
    bgqx.dbFieldName = "bgqx";
    jglb.dbFieldName = "jglb";
    zrz.dbFieldName = "zrz";
    nd.dbFieldName = "nd";
    ys.dbFieldName = "ys";
    gdh.dbFieldName = "gdh";
    flh.dbFieldName = "flh";
    qssj.dbFieldName = "qssj";
    zzsj.dbFieldName = "zzsj";
    dagdm.dbFieldName = "dagdm";
    kfh.dbFieldName = "kfh";
    pjh.dbFieldName = "pjh";
    bz.dbFieldName = "bz";
    jgwt.dbFieldName = "jgwt";
    mldm.dbFieldName = "mldm";

    type.userDefName = QString::fromLocal8Bit("类型");
    qzh.userDefName = QString::fromLocal8Bit("全宗号");
    mlh.userDefName = QString::fromLocal8Bit("目录号");
    ajh.userDefName = QString::fromLocal8Bit("案卷号");
    tm.userDefName = QString::fromLocal8Bit("题名");
    bgqx.userDefName = QString::fromLocal8Bit("保管期限");
    jglb.userDefName = QString::fromLocal8Bit("机构类别");
    zrz.userDefName = QString::fromLocal8Bit("责任者");
    nd.userDefName = QString::fromLocal8Bit("年度");
    ys.userDefName = QString::fromLocal8Bit("页数");
    gdh.userDefName = QString::fromLocal8Bit("归档号");
    flh.userDefName = QString::fromLocal8Bit("分类号");
    qssj.userDefName = QString::fromLocal8Bit("起始时间");
    zzsj.userDefName = QString::fromLocal8Bit("终止时间");
    dagdm.userDefName = QString::fromLocal8Bit("档案馆代码");
    kfh.userDefName = QString::fromLocal8Bit("库房号");
    pjh.userDefName = QString::fromLocal8Bit("排架号");
    bz.userDefName = QString::fromLocal8Bit("备注");
    jgwt.userDefName = QString::fromLocal8Bit("机构问题");
    mldm.userDefName = QString::fromLocal8Bit("档案馆门类代码");

    type.value = ArchiveBox;
}

DbJnwj::DbJnwj() :
    DbRec()
{
    tableName = "archive_book";

    type.dbFieldName = "type";
    qzh.dbFieldName = "qzh";
    mlh.dbFieldName = "mlh";
    ajh.dbFieldName = "ajh";
    jh.dbFieldName = "jh";
    tm.dbFieldName = "tm";
    zrz.dbFieldName = "zrz";
    bgqx.dbFieldName = "bgqx";
    jglb.dbFieldName = "jglb";
    mj.dbFieldName = "mj";
    wh.dbFieldName = "wh";
    nd.dbFieldName = "nd";
    gdh.dbFieldName = "gdh";
    ztlx.dbFieldName = "ztlx";
    flh.dbFieldName = "flh";
    ztc.dbFieldName = "ztc";
    sj.dbFieldName = "sj";
    dh.dbFieldName = "dh";
    wsh.dbFieldName = "wsh";
    yh.dbFieldName = "yh";
    zs.dbFieldName = "zs";
    kfh.dbFieldName = "kfh";
    pjh.dbFieldName = "pjh";
    bz.dbFieldName = "bz";
    jgwt.dbFieldName = "jgwt";
    mldm.dbFieldName = "mldm";

    type.userDefName = QString::fromLocal8Bit("类型");
    qzh.userDefName = QString::fromLocal8Bit("全宗号");
    mlh.userDefName = QString::fromLocal8Bit("目录号");
    ajh.userDefName = QString::fromLocal8Bit("案卷号");
    jh.userDefName = QString::fromLocal8Bit("件号");
    tm.userDefName = QString::fromLocal8Bit("题名");
    zrz.userDefName = QString::fromLocal8Bit("责任者");
    bgqx.userDefName = QString::fromLocal8Bit("保管期限");
    jglb.userDefName = QString::fromLocal8Bit("机构类别");
    mj.userDefName = QString::fromLocal8Bit("密级");
    wh.userDefName = QString::fromLocal8Bit("文号");
    nd.userDefName = QString::fromLocal8Bit("年度");
    gdh.userDefName = QString::fromLocal8Bit("归档号");
    ztlx.userDefName = QString::fromLocal8Bit("载体类型");
    flh.userDefName = QString::fromLocal8Bit("分类号");
    ztc.userDefName = QString::fromLocal8Bit("主题词");
    sj.userDefName = QString::fromLocal8Bit("时间");
    dh.userDefName = QString::fromLocal8Bit("档号");
    wsh.userDefName = QString::fromLocal8Bit("微缩号");
    yh.userDefName = QString::fromLocal8Bit("页号");
    zs.userDefName = QString::fromLocal8Bit("张数");
    kfh.userDefName = QString::fromLocal8Bit("库房号");
    pjh.userDefName = QString::fromLocal8Bit("排架号");
    bz.userDefName = QString::fromLocal8Bit("备注");
    jgwt.userDefName = QString::fromLocal8Bit("机构问题");
    mldm.userDefName = QString::fromLocal8Bit("档案馆门类代码");

    type.value = ArchiveBook;
}

DbGdwj::DbGdwj() :
    DbJnwj()
{
    tableName = "archive_book";

    mlh.userDefName  =QString::fromLocal8Bit("年度");
    type.value = ArchiveBook_GuiDangWenJian;
}

DbMedia::DbMedia() :
    DbGdwj()
{
    tableName = "archive_media";

    fileName.dbFieldName = "wjm";
    ocrText.dbFieldName = "ocr_text";
    type.dbFieldName = "dalx";

    fileName.userDefName = QString::fromLocal8Bit("文件名");
    ocrText.userDefName = QString::fromLocal8Bit("OCR文字");
    type.userDefName = QString::fromLocal8Bit("档案类型");

    type.value = JNWJ;
}

DbUser::DbUser() :
    DbRec()
{
    tableName = "user";

    name.dbFieldName = "name";
    role.dbFieldName = "role";
    password.dbFieldName = "password";
    remarks.dbFieldName = "remarks";

    name.userDefName = QString::fromLocal8Bit("用户名");
    role.userDefName = QString::fromLocal8Bit("用户角色");
    password.userDefName = QString::fromLocal8Bit("密码");
    remarks.userDefName = QString::fromLocal8Bit("备注");

    role.value = enAdminUser;
}

DbLog::DbLog() :
    DbRec()
{
    tableName = "log";

    operation.dbFieldName = "operation";
    operation.userDefName = QString::fromLocal8Bit("用户操作");

    updateTime.userDefName = QString::fromLocal8Bit("操作时间");
}

DbLog::DbLog(const qint64 userId, const qint64 libraryId, const QString &op) :
    DbRec()
{
    tableName = "log";

    operation.dbFieldName = "operation";
    operation.userDefName = QString::fromLocal8Bit("用户操作");

    user.id.value = userId;
    dag.id.value = libraryId;
    operation.value = op;
}

DbLogKey::DbLogKey() :
    DbLog()
{
    tableName = "";
}

DbCdjl::DbCdjl() :
    DbRec()
{
    tableName = "search_record";

    qzh.dbFieldName = "qzh";//全宗号
    mlh.dbFieldName = "mlh";//目录号
    ajh.dbFieldName = "ajh";//案卷号
    jh.dbFieldName = "jh";//件号
    customer.dbFieldName = "customer";//查档人
    idCardNum.dbFieldName = "id_card_num";//身份证号码
    operateReason.dbFieldName = "op_reason";//查档原因
    operatePerson.dbFieldName = "op_person";//操作人员
    operateTime.dbFieldName = "op_time";//查档时间
    remarks.dbFieldName = "remarks";//备注

    qzh.userDefName = QString::fromLocal8Bit("全宗号");
    mlh.userDefName = QString::fromLocal8Bit("目录号");
    ajh.userDefName = QString::fromLocal8Bit("案卷号");
    jh.userDefName = QString::fromLocal8Bit("件号");
    customer.userDefName = QString::fromLocal8Bit("查档人");
    idCardNum.userDefName = QString::fromLocal8Bit("查档人证件号");
    operateReason.userDefName = QString::fromLocal8Bit("查档原因");
    operatePerson.userDefName = QString::fromLocal8Bit("操作人员");
    operateTime.userDefName = QString::fromLocal8Bit("查档时间");
    remarks.userDefName = QString::fromLocal8Bit("备注");
}

DbCdjlKey::DbCdjlKey()
    : DbCdjl()
{

}
