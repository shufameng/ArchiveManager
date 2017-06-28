/**************************************************************************
**
** Description:
** 该文件主要声明了 LoginDlg 类,该类是登录对话框窗体类,
**
*****************************************************************************/

#ifndef LOGINDLG_H
#define LOGINDLG_H

#include "common/sdialog.h"
#include <QComboBox>
#include <QToolButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QDebug>


namespace Ui {
class LoginFrm;
}

class DeleteButtonComboBox;
class LoginMsg;

///
/// \brief The LoginDlg class
/// 登录对话框
///
class LoginDlg : public SDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = 0);
    ~LoginDlg();

    void setLoginStatus(const QString &status);
    void setToLoginPage();
    void setToStatusPage();

private slots:
    void on_pushButton_login_clicked();
    void onCurrentUserChanged(int index);
    void onUserRemoved(const QString &name);

    void on_toolButton_configNetwork_clicked();

    void onLoginSucceed();
    void onLoginFailed(const QString &error);
    void onLoginThreadStarted();
    void onLoginThreadFinished();

    void onCheckBoxRememberPwdToggled(bool checked);
    void on_pushButton_goBack_clicked();

private:
    Ui::LoginFrm *ui;
    DeleteButtonComboBox            *mUserComboBox;
    QList<LoginMsg>                         mLoginHistory;
};

#endif // LOGINDLG_H
