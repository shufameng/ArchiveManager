#ifndef CHANGEPASSWORDTHREAD_H
#define CHANGEPASSWORDTHREAD_H

#include <QThread>

class ChangePasswordThread : public QThread
{
    Q_OBJECT

public:
    ChangePasswordThread(const QString userName,
                         const QString &oldPasswd,
                         const QString &newPasswd,
                         const QString &repeatNewPasswd,
                         QObject *parent = 0);

protected:
    void run();

signals:
    void changePasswdResult(bool succeed, const QString &description);

private:
    QString mUserName;
    QString mOldPasswd;
    QString mNewPasswd;
    QString mRepeatNewPasswd;
};

#endif // CHANGEPASSWORDTHREAD_H
