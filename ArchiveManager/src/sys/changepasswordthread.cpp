#include "changepasswordthread.h"

ChangePasswordThread::ChangePasswordThread(const QString &oldPasswd, const QString &newPasswd, QObject *parent) :
    QThread(parent)
{
    mOldPasswd = oldPasswd;
    mNewPasswd = newPasswd;
}

void ChangePasswordThread::run()
{

}

