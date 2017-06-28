/**************************************************************************
**
** Description:
** ���ļ���Ҫ������ LoginThread ��,������һ���߳���,ʵ���˵�¼������.
**
*****************************************************************************/


#ifndef LOGINTHREAD_H
#define LOGINTHREAD_H

#include <QThread>

class LoginThread : public QThread
{
    Q_OBJECT
public:
    LoginThread(const QString &loginUser, const QString &loginPasswd, QObject *parent = 0);

protected:
    virtual void run();

signals:
    void loginSucceed();
    void loginFailed(const QString &error);

public:
    QString loginUser() const
    { return mLoginUser; }

    void setLoginUser(const QString &user)
    { mLoginUser = user; }

    QString loginPassword() const
    { return mLoginPasswd; }

    void setLoginPassword(const QString &passwd)
    { mLoginPasswd = passwd; }

private:
    QString mLoginUser;
    QString mLoginPasswd;
};

#endif // LOGINTHREAD_H
