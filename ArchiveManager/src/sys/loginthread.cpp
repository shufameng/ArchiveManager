#include "LoginThread.h"
#include "common/DbHandler.h"
#include "common/IniLoader.h"
#include "common/globals.h"
#include "common/dbquery.h"

LoginThread::LoginThread(const QString &loginUser, const QString &loginPasswd, QObject *parent) :
    QThread(parent),
    mLoginUser(loginUser),
    mLoginPasswd(loginPasswd)
{
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}

void LoginThread::run()
{
    if (mLoginUser.isEmpty()) {
        emit loginFailed(QString::fromLocal8Bit("用户名不能为空"));
        return;
    }

    if (mLoginPasswd.isEmpty()) {
        emit loginFailed(QString::fromLocal8Bit("密码不能为空"));
        return;
    }

    QSqlDatabase db = DbHandler::openDb(DbHandler::dbConnectionName());
    if (!db.isOpen()) {
        emit loginFailed(db.lastError().text());
        return;
    }

    DbQuery q(db);
    bool ok = q.exec(QString("use %1;").arg(IniLoader::loadDefaultDbName()));
    if (!ok) {
        emit loginFailed(q.lastError().text());
        return;
    }

    ok = q.prepare("select * from user where name = ? and password = ?;");
    if (!ok) {
        emit loginFailed(q.lastError().text());
        return;
    }
    q.bindValue(0, mLoginUser);
    q.bindValue(1, mLoginPasswd);

    ok = q.exec();
    if (!ok) {
        emit loginFailed(q.lastError().text());
        return;
    }

    if (q.next()) {
        if (!Globals::sgCurUser)
            Globals::sgCurUser = new DbUser;
        q.getUser(*Globals::sgCurUser);
        emit loginSucceed();
        return;
    } else {
        emit loginFailed(QString::fromLocal8Bit("该用户不存在或者密码错误."));
        return;
    }
}

