#ifndef CHANGEPASSWORDTHREAD_H
#define CHANGEPASSWORDTHREAD_H

#include <QThread>

class ChangePasswordThread : public QThread
{
    Q_OBJECT

public:
    ChangePasswordThread(const QString &oldPasswd, const QString &newPasswd, QObject *parent = 0);

protected:
    void run();

private:
    QString mOldPasswd;
    QString mNewPasswd;
};

#endif // CHANGEPASSWORDTHREAD_H
