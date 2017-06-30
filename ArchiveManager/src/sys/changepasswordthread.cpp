#include "changepasswordthread.h"
#include "common/dbhandler.h"
#include "common/dbquery.h"


ChangePasswordThread::ChangePasswordThread(const QString userName,
                                           const QString &oldPasswd,
                                           const QString &newPasswd,
                                           const QString &repeatNewPasswd,
                                           QObject *parent) :
    QThread(parent)
{
    mUserName = userName;
    mOldPasswd = oldPasswd;
    mNewPasswd = newPasswd;
    mRepeatNewPasswd = repeatNewPasswd;

    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}

void ChangePasswordThread::run()
{
    // 检查参数有效性
    if (mOldPasswd.isEmpty()) {
        emit changePasswdResult(false, QString::fromLocal8Bit("当前密码不能为空"));
        return;
    }
    if (mNewPasswd != mRepeatNewPasswd) {
        emit changePasswdResult(false, QString::fromLocal8Bit("两次输入的新密码不一致"));
        return;
    }
    if (mNewPasswd.isEmpty()) {
        emit changePasswdResult(false, QString::fromLocal8Bit("新密码不能为空"));
        return;
    }

    // 连接数据库
    QSqlDatabase db = DbHandler::openDb(DbHandler::dbConnectionName());
    if (!db.isOpen()) {
        emit changePasswdResult(false, db.lastError().text());
        return;
    }

    // 检查当前密码是否正确
    DbQuery q(db);
    if (!q.exec2(QString("select * from user where name = '%1' and password = '%2';")
                .arg(mUserName)
                .arg(mOldPasswd))) {
        emit changePasswdResult(false, q.lastError().text());
        return;
    }
    if (!q.next()) {
        emit changePasswdResult(false, QString::fromLocal8Bit("当前密码不正确"));
        return;
    }

    // 修改密码
    if (!q.exec(QString("update user set password = '%1' where name = '%2' and password = '%3';")
                .arg(mNewPasswd)
                .arg(mUserName)
                .arg(mOldPasswd))) {
        emit changePasswdResult(false, q.lastError().text());
        return;
    }

    emit changePasswdResult(true, QString::fromLocal8Bit("密码修改成功"));
    return;
}

