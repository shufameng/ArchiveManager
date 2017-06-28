#include "IniLoader.h"
#include <QSettings>

#define INI_FILE_NAME   "archive_manager_config.ini"

#define GROUP_DB            "Database"
#define KEY_DB_HOST     "Host"
#define KEY_DB_PORT     "Port"
#define KEY_DB_USER     "User"
#define KEY_DB_PASSWD   "Password"
#define KEY_DB_DBNAME   "DatabaseName"

#define GROUP_FS            "FileServer"
#define KEY_FS_HOST     "Host"
#define KEY_FS_PORT      "Port"

#define GROUP_HS            "HttpServer"
#define KEY_HS_HOST     "Host"
#define KEY_HS_PORT         "Port"

#define GROUP_OPT                       "Options"
#define KEY_OPT_DEFAULT_DB      "DefaultDatabaseName"
#define KEY_OPT_CURRENT_DB      "CurrentDatabaseName"
#define KEY_OPT_LOGIN_REMEMBER_PWD  "LoginRememberPassword"
#define KEY_OPT_MAX_REC_PERPAGE     "MaxRecordCountPerpage"
#define KEY_OPT_COUNT_FACTOR            "CountFactor"
#define KEY_OPT_LOGIN_HISTORY       "LoginHistory"

IniLoader:: IniLoader()
{

}

void IniLoader::createInis()
{
    QSettings s(INI_FILE_NAME, QSettings::IniFormat);

    DbNetConfig dbConf;
    s.beginGroup(GROUP_DB);
    if (!s.contains(KEY_DB_HOST))
        s.setValue(KEY_DB_HOST, dbConf.host);
    if (!s.contains(KEY_DB_PORT))
        s.setValue(KEY_DB_PORT, dbConf.port);
    if (!s.contains(KEY_DB_USER))
        s.setValue(KEY_DB_USER, dbConf.user);
    if (!s.contains(KEY_DB_PASSWD))
        s.setValue(KEY_DB_PASSWD, dbConf.passwd);
    if (!s.contains(KEY_DB_DBNAME))
        s.setValue(KEY_DB_DBNAME, dbConf.dbName);
    s.endGroup();

    FsNetConfig fsConf;
    s.beginGroup(GROUP_FS);
    if (!s.contains(KEY_FS_HOST))
        s.setValue(KEY_FS_HOST, fsConf.host);
    if (!s.contains(KEY_FS_PORT))
        s.setValue(KEY_FS_PORT, fsConf.port);
    s.endGroup();

    HsNetConfig hsConf;
    s.beginGroup(GROUP_HS);
    if (!s.contains(KEY_HS_HOST))
        s.setValue(KEY_HS_HOST, hsConf.host);
    if (!s.contains(KEY_HS_PORT))
        s.setValue(KEY_HS_PORT, hsConf.port);
    s.endGroup();

    s.beginGroup(GROUP_OPT);
    if (!s.contains(KEY_OPT_DEFAULT_DB))
        s.setValue(KEY_OPT_DEFAULT_DB, "dms_manager_db");
    if (!s.contains(KEY_OPT_CURRENT_DB))
        s.setValue(KEY_OPT_CURRENT_DB, "dms_manager_db");
    if (!s.contains(KEY_OPT_LOGIN_REMEMBER_PWD))
        s.setValue(KEY_OPT_LOGIN_REMEMBER_PWD, false);
    if (!s.contains(KEY_OPT_MAX_REC_PERPAGE))
        s.setValue(KEY_OPT_MAX_REC_PERPAGE, 100);
    if (!s.contains(KEY_OPT_COUNT_FACTOR))
        s.setValue(KEY_OPT_COUNT_FACTOR, 100);
    s.endGroup();
}

void IniLoader::saveDbNetConfig(const DbNetConfig &conf)
{
    QSettings s(INI_FILE_NAME, QSettings::IniFormat);
    s.beginGroup(GROUP_DB);
    s.setValue(KEY_DB_HOST, conf.host);
    s.setValue(KEY_DB_PORT, conf.port);
    s.setValue(KEY_DB_USER, conf.user);
    s.setValue(KEY_DB_PASSWD, conf.passwd);
    s.setValue(KEY_DB_DBNAME, conf.dbName);
    s.endGroup();
}

DbNetConfig IniLoader::loadDbNetConfig()
{
    QSettings s(INI_FILE_NAME, QSettings::IniFormat);
    DbNetConfig conf;
    s.beginGroup(GROUP_DB);
    conf.host = s.value(KEY_DB_HOST).toString();
    conf.port = s.value(KEY_DB_PORT).toInt();
    conf.user = s.value(KEY_DB_USER).toString();
    conf.passwd = s.value(KEY_DB_PASSWD).toString();
    conf.dbName = s.value(KEY_DB_DBNAME).toString();
    s.endGroup();
    return conf;
}

void IniLoader::saveFsNetConfig(const FsNetConfig &conf)
{
    QSettings s(INI_FILE_NAME, QSettings::IniFormat);
    s.beginGroup(GROUP_FS);
    s.setValue(KEY_FS_HOST, conf.host);
    s.setValue(KEY_FS_PORT, conf.port);
    s.endGroup();
}

FsNetConfig IniLoader::loadFsNetConfig()
{
    QSettings s(INI_FILE_NAME, QSettings::IniFormat);
    FsNetConfig conf;
    s.beginGroup(GROUP_FS);
    conf.host = s.value(KEY_FS_HOST).toString();
    conf.port = s.value(KEY_FS_PORT).toInt();
    s.endGroup();
    return conf;
}

void IniLoader::saveHsNetConfig(const HsNetConfig &conf)
{
    QSettings s(INI_FILE_NAME, QSettings::IniFormat);
    s.beginGroup(GROUP_HS);
    s.setValue(KEY_HS_HOST, conf.host);
    s.setValue(KEY_HS_PORT, conf.port);
    s.endGroup();
}

HsNetConfig IniLoader::loadHsNetConfig()
{
    QSettings s(INI_FILE_NAME, QSettings::IniFormat);
    HsNetConfig conf;
    s.beginGroup(GROUP_HS);
    conf.host = s.value(KEY_HS_HOST).toString();
    conf.port = s.value(KEY_HS_PORT).toInt();
    s.endGroup();
    return conf;
}

void IniLoader::saveByKey(const QString &key, const QVariant &value)
{
    QSettings s(INI_FILE_NAME, QSettings::IniFormat);
    s.setValue(key, value);
}

QVariant IniLoader::loadByKey(const QString &key)
{
    QSettings s(INI_FILE_NAME, QSettings::IniFormat);
    return s.value(key);
}

void IniLoader::saveDefaultDbName(const QString &name)
{
    saveByKey(QString(GROUP_OPT) + "/" + KEY_OPT_DEFAULT_DB, name);
}

QString IniLoader::loadDefaultDbName()
{
    return loadByKey(QString(GROUP_OPT) + "/" + KEY_OPT_DEFAULT_DB).toString();
}

void IniLoader::saveCurrentDbName(const QString &name)
{
    saveByKey(QString(GROUP_OPT) + "/" + KEY_OPT_CURRENT_DB, name);
}

QString IniLoader::loadCurrentDbName()
{
    return loadByKey(QString(GROUP_OPT) + "/" + KEY_OPT_CURRENT_DB).toString();
}

void IniLoader::saveLoginRememberPwd(const bool remember)
{
    saveByKey(QString(GROUP_OPT) + "/" + KEY_OPT_LOGIN_REMEMBER_PWD, remember);
}

bool IniLoader::loadLoginRememberPwd()
{
    return loadByKey(QString(GROUP_OPT) + "/" + KEY_OPT_LOGIN_REMEMBER_PWD).toBool();
}

void IniLoader::saveMaxRecPerpage(const int count)
{
    saveByKey(QString(GROUP_OPT) + "/" + KEY_OPT_MAX_REC_PERPAGE, count);
}

int IniLoader::loadMaxRecPerpage()
{
    return loadByKey(QString(GROUP_OPT) + "/" + KEY_OPT_MAX_REC_PERPAGE).toInt();
}

void IniLoader::saveCountFactor(const int factor)
{
    saveByKey(QString(GROUP_OPT) + "/" + KEY_OPT_COUNT_FACTOR, factor);
}

int IniLoader::loadCountFactor()
{
    return loadByKey(QString(GROUP_OPT) + "/" + KEY_OPT_COUNT_FACTOR).toInt();
}

void IniLoader::addLoginMsg(const LoginMsg &msg)
{
    QList<LoginMsg> msgs = loadLoginMsgs();

    int i;
    for (i = 0; i < msgs.size(); i ++) {

        // 如果该用户名已经存在于登录历史信息中,更新配置文件中的密码
        if (msgs.at(i).user == msg.user) {
            msgs[i].passwd = msg.passwd;
            break;
        }
    }

    // 如果该用户名没有记录到登录历史信息中,则添加该条用户名到登录历史信息
    if (i >= msgs.size())
        msgs.append(msg);
    saveByKey(QString(GROUP_OPT) + "/" + KEY_OPT_LOGIN_HISTORY, loginMsgsToString(msgs));
}

void IniLoader::removeLoginMsg(const QString &user)
{
    QList<LoginMsg> msgs = loadLoginMsgs();
    for (int i = 0; i < msgs.size(); i ++) {
        if (msgs.at(i).user == user) {
            msgs.removeAt(i);
            break;
        }
    }

    saveByKey(QString(GROUP_OPT) + "/" + KEY_OPT_LOGIN_HISTORY, loginMsgsToString(msgs));
}

QList<LoginMsg> IniLoader::loadLoginMsgs()
{
    QString str = loadByKey(QString(GROUP_OPT) + "/" + KEY_OPT_LOGIN_HISTORY).toString();
    return stringToLoginMsgs(str);
}

void IniLoader::setLoginMsgs(const QList<LoginMsg> &msgs)
{
    saveByKey(QString(GROUP_OPT) + "/" + KEY_OPT_LOGIN_HISTORY, loginMsgsToString(msgs));
}

QString IniLoader::loginMsgsToString(const QList<LoginMsg> &msgs)
{
    QString str;
    for (int i = 0; i < msgs.size(); i ++) {
        str.append(msgs.at(i).user);
        str.append(loginMsgsSep1());
        str.append(msgs.at(i).passwd);
        str.append(loginMsgsSep2());
    }
    return str;
}

QList<LoginMsg> IniLoader::stringToLoginMsgs(const QString &string)
{
    QList<LoginMsg> msgs;
    QString str;
    LoginMsg msg;
    QStringList nameAndPasswd;

    QStringList strs = string.split(loginMsgsSep2());

    for (int i = 0; i < strs.size(); i ++) {
        str = strs.at(i);

        // every string in strs should like:
        // username,userpassword
        if (1 != str.count(loginMsgsSep1()))
            continue;

        nameAndPasswd = str.split(loginMsgsSep1());
        if (2 != nameAndPasswd.size())
            continue;

        msg.user = nameAndPasswd.at(0);
        msg.passwd = nameAndPasswd.at(1);
        msgs.append(msg);
    }

    return msgs;
}

