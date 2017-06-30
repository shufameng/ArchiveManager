#include "MainDlg.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QSplitter>
#include <QApplication>
#include <QTableWidget>
#include <QProcess>

#include "common/dbtypes.h"
#include "log/LogSqlTableFrm.h"
#include "qz/QzSqlTableFrm.h"
#include "aj/AjSqlTableFrm.h"
#include "jnwj/JnwjSqlTableFrm.h"
#include "gdwj/GdwjSqlTableFrm.h"
#include "common/guidetreewidget.h"
#include "qz/createqzfrm.h"
#include "qz/searchqzfrm.h"
#include "aj/createajfrm.h"
#include "aj/searchajfrm.h"
#include "jnwj/createjnwjfrm.h"
#include "jnwj/searchjnwjfrm.h"
#include "gdwj/creategdwjfrm.h"
#include "gdwj/searchgdwjfrm.h"
#include "log/searchlogfrm.h"
#include "sys/importfrm.h"
#include "sys/exportfrm.h"
#include "sys/backupfrm.h"
#include "sys/resumefrm.h"
#include "user/createuserfrm.h"
#include "user/searchuserfrm.h"
#include "sys/changepassworddlg.h"
#include "common/globals.h"



MainDlg::MainDlg(QWidget *parent) :
    SDialog(parent)
{
    setWindowIconHidden(true);
    setWindowTitle(QString::fromLocal8Bit("龙城档案管理系统"));
    setupLayout();

    resize(800, 600);
}

MainDlg::~MainDlg()
{

}

void MainDlg::onQuitSystem()
{
    qApp->quit();
}

void MainDlg::onConfigSystem()
{
//    ConfigSystemDlg dlg(this);
//    dlg.exec();
}

void MainDlg::onCheckMyInfo()
{
    QString log = QString("Name:%1 \t Role:%2 \n Password:%3\n Remarks:%4\n CreateTime:%5\n UpdateTime:%6\n")
            .arg(Globals::sgCurUser->name.value.toString())
            .arg(Globals::sgCurUser->role.value.toInt())
            .arg(Globals::sgCurUser->password.value.toString())
            .arg(Globals::sgCurUser->remarks.value.toString())
            .arg(Globals::sgCurUser->createTime.value.toString())
            .arg(Globals::sgCurUser->updateTime.value.toString());
    qDebug() << log;
}

void MainDlg::onChangeMyPasswd()
{
    ChangePasswordDlg dlg(this);
    dlg.exec();
}

void MainDlg::onSignOut()
{
    qApp->quit();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}

void MainDlg::onFuncRequest(int funcID)
{
    switch (funcID) {
    case (GuideTreeWidget::ID_CREATE_QZ):
        mSWMain->setCurrentWidget(mFrmCreateQz);
        break;
    case (GuideTreeWidget::ID_SEARCH_QZ):
        mSWMain->setCurrentWidget(mFrmSearchQz);
        break;
    case (GuideTreeWidget::ID_CREATE_AJ):
        mSWMain->setCurrentWidget(mFrmCreateAj);
        break;
    case (GuideTreeWidget::ID_SEARCH_AJ):
        mSWMain->setCurrentWidget(mFrmSearchAj);
        break;
    case (GuideTreeWidget::ID_CREATE_JNWJ):
        mSWMain->setCurrentWidget(mFrmCreateJnwj);
        break;
    case (GuideTreeWidget::ID_SEARCH_JNWJ):
        mSWMain->setCurrentWidget(mFrmSearchJnwj);
        break;
    case (GuideTreeWidget::ID_CREATE_GDWJ):
        mSWMain->setCurrentWidget(mFrmCreateGdwj);
        break;
    case (GuideTreeWidget::ID_SEARCH_GDWJ):
        mSWMain->setCurrentWidget(mFrmSearchGdwj);
        break;
    case (GuideTreeWidget::ID_IMPORT):
        mSWMain->setCurrentWidget(mFrmImport);
        break;
    case (GuideTreeWidget::ID_EXPORT):
        mSWMain->setCurrentWidget(mFrmExport);
        break;
    case (GuideTreeWidget::ID_BACKUP):
        mSWMain->setCurrentWidget(mFrmBackUp);
        break;
    case (GuideTreeWidget::ID_RESUME):
        mSWMain->setCurrentWidget(mFrmResume);
        break;
    case (GuideTreeWidget::ID_CREATE_USER):
        mSWMain->setCurrentWidget(mFrmCreateUser);
        break;
    case (GuideTreeWidget::ID_SEARCH_USER):
        mSWMain->setCurrentWidget(mFrmSearchUser);
        break;
    case (GuideTreeWidget::ID_SEARCH_LOG):
        mSWMain->setCurrentWidget(mFrmSearchLog);
        break;
    default:
        break;
    }
}

void MainDlg::setupLayout()
{
    // 标题栏的 设置 菜单
    mBtnSettings = new QToolButton(this);
    mBtnSettings->setPopupMode(QToolButton::InstantPopup);
    mBtnSettings->setText(QString::fromLocal8Bit("设置"));
    mBtnSettings->setIcon(QIcon("://image/titlebar_settings.png"));
    mActConfigSystem = new QAction(QString::fromLocal8Bit("系统设置"), mBtnSettings);
    mActQuitSystem = new QAction(QString::fromLocal8Bit("退出系统"), mBtnSettings);
    mBtnSettings->addAction(mActConfigSystem);
    mBtnSettings->addAction(mActQuitSystem);
    connect(mActConfigSystem, SIGNAL(triggered()), this, SLOT(onConfigSystem()));
    connect(mActQuitSystem, SIGNAL(triggered()), this, SLOT(onQuitSystem()));

    // 标题栏的 用户 菜单
    mBtnUser = new QToolButton(this);
    mBtnUser->setPopupMode(QToolButton::InstantPopup);
    mBtnUser->setText(QString::fromLocal8Bit("用户"));
    mBtnUser->setIcon(QIcon("://image/titlebar_user.png"));
    titleBarButtonLayout()->addWidget(mBtnUser);
    titleBarButtonLayout()->addWidget(mBtnSettings);
    mActCheckUserMsg = new QAction(QString::fromLocal8Bit("查看我的信息"), mBtnUser);
    mActChangePasswd = new QAction(QString::fromLocal8Bit("修改我的密码"), mBtnUser);
    mActSignOut = new QAction(QString::fromLocal8Bit("注销登录"), mBtnUser);
    mBtnUser->addAction(mActCheckUserMsg);
    mBtnUser->addAction(mActChangePasswd);
    mBtnUser->addAction(mActSignOut);
    connect(mActCheckUserMsg, SIGNAL(triggered()), this, SLOT(onCheckMyInfo()));
    connect(mActChangePasswd, SIGNAL(triggered()), this, SLOT(onChangeMyPasswd()));
    connect(mActSignOut, SIGNAL(triggered()), this, SLOT(onSignOut()));

    //
    QHBoxLayout *hLay = new QHBoxLayout(centralFrame());
    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);
    hLay->addWidget(splitter);
    splitter->addWidget(mTWGuide = new GuideTreeWidget(this));
    splitter->addWidget(mSWMain = new QStackedWidget(this));
    mSWMain->addWidget(new QTableWidget);
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 4);

    mSWMain->addWidget(mFrmCreateQz = new CreateQzFrm);
    mSWMain->addWidget(mFrmSearchQz = new SearchQzFrm);
    mSWMain->addWidget(mFrmCreateAj = new CreateAjFrm);
    mSWMain->addWidget(mFrmSearchAj = new SearchAjFrm);
    mSWMain->addWidget(mFrmCreateJnwj = new CreateJnwjFrm);
    mSWMain->addWidget(mFrmSearchJnwj = new SearchJnwjFrm);
    mSWMain->addWidget(mFrmCreateGdwj = new CreateGdwjFrm);
    mSWMain->addWidget(mFrmSearchGdwj = new SearchGdwjFrm);
    mSWMain->addWidget(mFrmImport = new ImportFrm);
    mSWMain->addWidget(mFrmExport = new ExportFrm);
    mSWMain->addWidget(mFrmBackUp = new BackupFrm);
    mSWMain->addWidget(mFrmResume = new ResumeFrm);
    mSWMain->addWidget(mFrmCreateUser = new CreateUserFrm);
    mSWMain->addWidget(mFrmSearchUser = new SearchUserFrm);
    mSWMain->addWidget(mFrmSearchLog = new SearchLogFrm);

    connect(mTWGuide, SIGNAL(funcRequest(int)), this, SLOT(onFuncRequest(int)));
}
