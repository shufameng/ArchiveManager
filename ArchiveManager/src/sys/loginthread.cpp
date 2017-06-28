#include "LoginThread.h"
#include "common/DbHandler.h"
#include "common/IniLoader.h"

LoginThread::LoginThread(const QString &loginUser, const QString &loginPasswd, QObject *parent) :
    QThread(parent),
    mLoginUser(loginUser),
    mLoginPasswd(loginPasswd)
{
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}

void LoginThread::run()
{
    QSqlDatabase db = DbHandler::openDb(DbHandler::dbConnectionName());
    if (!db.isOpen()) {
        emit loginFailed(db.lastError().text());
        return;
    }

    QSqlQuery q(db);
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
        emit loginSucceed();
        return;
    } else {
        emit loginFailed(QString::fromLocal8Bit("该用户不存在或者密码错误."));
        return;
    }
}

