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
    // ��������Ч��
    if (mOldPasswd.isEmpty()) {
        emit changePasswdResult(false, QString::fromLocal8Bit("��ǰ���벻��Ϊ��"));
        return;
    }
    if (mNewPasswd != mRepeatNewPasswd) {
        emit changePasswdResult(false, QString::fromLocal8Bit("��������������벻һ��"));
        return;
    }
    if (mNewPasswd.isEmpty()) {
        emit changePasswdResult(false, QString::fromLocal8Bit("�����벻��Ϊ��"));
        return;
    }

    // �������ݿ�
    QSqlDatabase db = DbHandler::openDb(DbHandler::dbConnectionName());
    if (!db.isOpen()) {
        emit changePasswdResult(false, db.lastError().text());
        return;
    }

    // ��鵱ǰ�����Ƿ���ȷ
    DbQuery q(db);
    if (!q.exec2(QString("select * from user where name = '%1' and password = '%2';")
                .arg(mUserName)
                .arg(mOldPasswd))) {
        emit changePasswdResult(false, q.lastError().text());
        return;
    }
    if (!q.next()) {
        emit changePasswdResult(false, QString::fromLocal8Bit("��ǰ���벻��ȷ"));
        return;
    }

    // �޸�����
    if (!q.exec(QString("update user set password = '%1' where name = '%2' and password = '%3';")
                .arg(mNewPasswd)
                .arg(mUserName)
                .arg(mOldPasswd))) {
        emit changePasswdResult(false, q.lastError().text());
        return;
    }

    emit changePasswdResult(true, QString::fromLocal8Bit("�����޸ĳɹ�"));
    return;
}

