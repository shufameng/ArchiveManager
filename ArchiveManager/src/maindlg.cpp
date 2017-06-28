#include "MainDlg.h"
#include <QHBoxLayout>
#include "common/DbTypes.h"
#include <QDebug>
#include <QSplitter>
#include <QApplication>

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

#include "sys/changepassworddlg.h"

#include <QTableWidget>
#include <QProcess>


MainDlg::MainDlg(QWidget *parent) :
    SDialog(parent)
{
    setWindowIconHidden(true);
    setWindowTitle(QString::fromLocal8Bit("���ǵ�������ϵͳ"));
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
    // �������� ���� �˵�
    mBtnSettings = new QToolButton(this);
    mBtnSettings->setPopupMode(QToolButton::InstantPopup);
    mBtnSettings->setText(QString::fromLocal8Bit("����"));
    mBtnSettings->setIcon(QIcon("://image/titlebar_settings.png"));
    mActConfigSystem = new QAction(QString::fromLocal8Bit("ϵͳ����"), mBtnSettings);
    mActQuitSystem = new QAction(QString::fromLocal8Bit("�˳�ϵͳ"), mBtnSettings);
    mBtnSettings->addAction(mActConfigSystem);
    mBtnSettings->addAction(mActQuitSystem);
    connect(mActConfigSystem, SIGNAL(triggered()), this, SLOT(onConfigSystem()));
    connect(mActQuitSystem, SIGNAL(triggered()), this, SLOT(onQuitSystem()));

    // �������� �û� �˵�
    mBtnUser = new QToolButton(this);
    mBtnUser->setPopupMode(QToolButton::InstantPopup);
    mBtnUser->setText(QString::fromLocal8Bit("�û�"));
    mBtnUser->setIcon(QIcon("://image/titlebar_user.png"));
    titleBarButtonLayout()->addWidget(mBtnUser);
    titleBarButtonLayout()->addWidget(mBtnSettings);
    mActCheckUserMsg = new QAction(QString::fromLocal8Bit("�鿴�ҵ���Ϣ"), mBtnUser);
    mActChangePasswd = new QAction(QString::fromLocal8Bit("�޸��ҵ�����"), mBtnUser);
    mActSignOut = new QAction(QString::fromLocal8Bit("ע����¼"), mBtnUser);
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
    mSWMain->addWidget(mFrmImport = new QFrame);
    mSWMain->addWidget(mFrmExport = new QFrame);
    mSWMain->addWidget(mFrmBackUp = new QFrame);
    mSWMain->addWidget(mFrmResume = new QFrame);
    mSWMain->addWidget(mFrmCreateUser = new QFrame);
    mSWMain->addWidget(mFrmSearchUser = new QFrame);
    mSWMain->addWidget(mFrmSearchLog = new QFrame);

    connect(mTWGuide, SIGNAL(funcRequest(int)), this, SLOT(onFuncRequest(int)));
}