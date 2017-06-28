#include "SSqlTableFrm.h"
#include "ui_ssqltablefrm.h"
#include "log/LogSqlTableModel.h"
#include <QMenu>

SSqlTableFrm::SSqlTableFrm(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SSqlTableFrm),
    mModel(NULL)
{
    ui->setupUi(this);    
    ui->horizontalLayout_pageButtons->addWidget(mPageToolBar = new QToolBar(this));
    connect(view(), SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showViewMenu(QPoint)));
}

SSqlTableFrm::~SSqlTableFrm()
{
    delete ui;
}

QTreeView *SSqlTableFrm::view()
{
    return ui->treeView;
}

void SSqlTableFrm::setTotalRecLabel(int count)
{
    ui->label_totalRcdCount->setText(QString::number(count));
}

void SSqlTableFrm::setTotalPageLabel(int count)
{
    ui->label_totalPageCount->setText(QString::number(count));
}

void SSqlTableFrm::setCurrentPageLabel(int page)
{
    ui->label_currentPage->setText(QString::number(page + 1));
}

void SSqlTableFrm::toNextPage()
{
    if (!mModel)
        return;

    mModel->toNextPage();
}

void SSqlTableFrm::toPrevPage()
{
    if (!mModel)
        return;

    mModel->toPrevPage();
}

void SSqlTableFrm::toFirstPage()
{
    if (!mModel)
        return;

    mModel->toFirstPage();
}

void SSqlTableFrm::toLastPage()
{
    if (!mModel)
        return;

    mModel->toLastPage();
}

void SSqlTableFrm::toPage(const int page)
{
    if (!mModel)
        return;

    mModel->toPage(page);
}

void SSqlTableFrm::search(DbRec *key)
{
    if (!mModel || !key)
        return;

    mModel->setAdvancedKey(key);
    mModel->select();
}

void SSqlTableFrm::connectSlots()
{
    if (!mModel)
        return;
    connect(mModel, SIGNAL(totalRecCountChanged(int)), this, SLOT(setTotalRecLabel(int)));
    connect(mModel, SIGNAL(totalPageCountChanged(int)), this, SLOT(setTotalPageLabel(int)));
    connect(mModel, SIGNAL(currentPageChanged(int)), this, SLOT(setCurrentPageLabel(int)));
}

void SSqlTableFrm::showViewMenu(const QPoint &pos)
{
    if (!view()->indexAt(pos).isValid())
        return;

    QMenu m(this);
    m.addAction("Open");
    m.addAction("Save");
    m.addAction("Save As...");
    m.exec(QCursor::pos());
}

void SSqlTableFrm::on_pushButton_firstPage_clicked()
{
    mModel->toFirstPage();
}

void SSqlTableFrm::on_pushButton_prevPage_clicked()
{
    mModel->toPrevPage();
}

void SSqlTableFrm::on_pushButton_nextPage_clicked()
{
    mModel->toNextPage();
}

void SSqlTableFrm::on_pushButton_lastPage_clicked()
{
    mModel->toLastPage();
}
