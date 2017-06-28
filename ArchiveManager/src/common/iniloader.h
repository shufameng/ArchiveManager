/**************************************************************************
**
** Description:
** 该文件主要声明了 IniLoader 类,该类的职责是读写应用程序的ini配置文件.
**
*****************************************************************************/

#ifndef INILOADER_H
#define INILOADER_H

#include <QString>
#include <QVariant>

///
/// \brief The DbNetConfig class
///
class DbNetConfig
{
public:
    DbNetConfig() :
        host("14.17.88.25"),
        port(3306),
        user("root"),
        passwd("123456"),
        dbName("dms_manager_db")
    {}

    QString host;
    int         port;
    QString user;
    QString passwd;
    QString dbName;
};

///
/// \brief The FsNetConfig class
///
class FsNetConfig
{
public:
    FsNetConfig() :
        host("14.17.88.25"),
        port(7383)
    {}

    QString host;
    int         port;
};

///
/// \brief The HsNetConfig class
///
class HsNetConfig
{
public:
    HsNetConfig() :
        host("14.17.88.25"),
        port(8182)
    {}

    QString host;
    int         port;
};

///
/// \brief The LoginMsg class
///
class LoginMsg
{
public:
    LoginMsg()
    {}

    QString user;
    QString passwd;
};

///
/// \brief The IniLoader class
///
class  IniLoader
{
public:
     IniLoader();

     // create default ini settings
    static void                createInis();

    // database connection settings
    static void                 saveDbNetConfig(const DbNetConfig &conf);
    static DbNetConfig    loadDbNetConfig();

    // file server connection settings
    static void                 saveFsNetConfig(const FsNetConfig &conf);
    static FsNetConfig   loadFsNetConfig();

    // http server connection settings
    static void                 saveHsNetConfig(const HsNetConfig &conf);
    static HsNetConfig  loadHsNetConfig();

    static void                 saveByKey(const QString &key, const QVariant &value);
    static QVariant         loadByKey(const QString &key);

    // default database name
    static void             saveDefaultDbName(const QString &name);
    static QString      loadDefaultDbName();

    // current database name
    static void             saveCurrentDbName(const QString &name);
    static QString      loadCurrentDbName();

    // login remember password
    static void             saveLoginRememberPwd(const bool remember);
    static bool             loadLoginRememberPwd();

    // max record perpage
    static void             saveMaxRecPerpage(const int count);
    static int                  loadMaxRecPerpage();

    // for cheating
    static void             saveCountFactor(const int factor);
    static int              loadCountFactor();

    /** User login history messages store format:
     * should like this:
     * username1,password1;username2,password;
     * */
    static void             addLoginMsg(const LoginMsg &msg);
    static void             removeLoginMsg(const QString &user);
    static QList<LoginMsg> loadLoginMsgs();
    static void             setLoginMsgs(const QList<LoginMsg> &msgs);
    static QString          loginMsgsToString(const QList<LoginMsg> &msgs);
    static QList<LoginMsg> stringToLoginMsgs(const QString &string);
    static QChar        loginMsgsSep1() { return ','; } // seperator between user and password
    static QChar        loginMsgsSep2() { return ';'; } // seperator between each login messages
};


#endif // INILOADER_H
