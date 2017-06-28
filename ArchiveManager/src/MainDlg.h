#ifndef MAINDLG_H
#define MAINDLG_H

#include <QDialog>
#include <QToolButton>
#include <QAction>
#include <QMenu>
#include "common/sdialog.h"
#include <QStackedWidget>

namespace Ui {
class SqlModelDialog;
}

class GuideTreeWidget;

class CreateQzFrm;
class SearchQzFrm;
class CreateAjFrm;
class SearchAjFrm;
class CreateJnwjFrm;
class SearchJnwjFrm;
class CreateGdwjFrm;
class SearchGdwjFrm;

class MainDlg : public SDialog
{
    Q_OBJECT

public:
    explicit MainDlg(QWidget *parent = 0);
    ~MainDlg();

protected slots:
    void onQuitSystem();
    void onConfigSystem();
    void onCheckMyInfo();
    void onChangeMyPasswd();
    void onSignOut();

    void onFuncRequest(int funcID);

private:
    void setupLayout();

    Ui::SqlModelDialog *ui;

    QToolButton         *mBtnUser;
    QAction                 *mActCheckUserMsg;
    QAction                 *mActChangePasswd;
    QAction                 *mActSignOut;

    QToolButton         *mBtnSettings;
    QAction                 *mActConfigSystem;
    QAction                 *mActQuitSystem;

    GuideTreeWidget     *mTWGuide;
    QStackedWidget      *mSWMain;

    CreateQzFrm             *mFrmCreateQz;
    SearchQzFrm             *mFrmSearchQz;
    CreateAjFrm             *mFrmCreateAj;
    SearchAjFrm             *mFrmSearchAj;
    CreateJnwjFrm           *mFrmCreateJnwj;
    SearchJnwjFrm           *mFrmSearchJnwj;
    CreateGdwjFrm           *mFrmCreateGdwj;
    SearchGdwjFrm           *mFrmSearchGdwj;
    QFrame                      *mFrmImport;
    QFrame                      *mFrmExport;
    QFrame                      *mFrmBackUp;
    QFrame                      *mFrmResume;
    QFrame                      *mFrmCreateUser;
    QFrame                      *mFrmSearchUser;
    QFrame                      *mFrmSearchLog;
};

#endif // MAINDLG_H
