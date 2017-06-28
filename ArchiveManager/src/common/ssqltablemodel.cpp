#include "SSqlTableModel.h"
#include <QDebug>
#include "IniLoader.h"
#include "DbHandler.h"
#include "DbTypes.h"

SSqlTableModel::SSqlTableModel(QObject *parent) :
    QAbstractItemModel(parent),
    mAdvancedKey(NULL),
    mRowCount(0),
    mColumnCount(0),
    mTotalRecCount(0),
    mTotalPageCount(0),
    mMaxRecPerpage(100),
    mCurrentPage(0)
{
    connect(this, SIGNAL(totalRecCountChanged(int)), this, SLOT(updateTotalPageCount()));
}

SSqlTableModel::~SSqlTableModel()
{
    if (mAdvancedKey)
        delete mAdvancedKey;
}

QModelIndex SSqlTableModel::index(int row, int column, const QModelIndex &parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();
}

QModelIndex SSqlTableModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int SSqlTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return mRowCount;
}

int SSqlTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return mColumnCount;
}

QVariant SSqlTableModel::data(const QModelIndex &index, int role) const
{
    if (!mQuery.isSelect() || !index.isValid())
        return QVariant();

    switch (role) {
    case Qt::DisplayRole:
    case Qt::EditRole:
        mQuery.seek(index.row());
        return mQuery.value(index.column());
        break;
    default:
        break;
    }
    return QVariant();
}

QVariant SSqlTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    switch (role) {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if (Qt::Vertical == orientation) {
            return section;
        } else if (Qt::Horizontal == orientation) {
            if (section < mHorHeaderData.size())
                return mHorHeaderData.at(section);
            else
                return QVariant();
        }
        break;
    default:
        break;
    }
    return QVariant();
}

bool SSqlTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    switch (role) {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if (Qt::Horizontal == orientation) {
            if (section < mHorHeaderData.size()) {
                mHorHeaderData.replace(section, value);
                return true;
            }
        }

        break;
    default:
        break;
    }
    return false;
}

void SSqlTableModel::rowInfo(const int row, DbRec *info)
{

}

qint64 SSqlTableModel::rowInfoId(const int row)
{
    return -1;
}

void SSqlTableModel::print(QTextDocument *doc)
{

}

void SSqlTableModel::toNextPage()
{
    if (mCurrentPage < mTotalPageCount - 1) {
        setCurrentPage(mCurrentPage + 1);
        select();
    }
}

void SSqlTableModel::toPrevPage()
{
    if (mCurrentPage > 0) {
        setCurrentPage(mCurrentPage - 1);
        select();
    }
}

void SSqlTableModel::toFirstPage()
{
    if (0 != mCurrentPage) {
        setCurrentPage(0);
        select();
    }
}

void SSqlTableModel::toLastPage()
{
    if (mTotalPageCount - 1 != mCurrentPage) {
        setCurrentPage(mTotalPageCount - 1);
        select();
    }
}

void SSqlTableModel::toPage(const int page)
{
    if (page >= 0 && page != mCurrentPage && page < mTotalPageCount) {
        setCurrentPage(page);
        select();
    }
}

void SSqlTableModel::setRowCount(const int count)
{
    mRowCount = count;
    emit rowCountChanged(count);
}

void SSqlTableModel::setColumnCount(const int count)
{
    mColumnCount = count;
    emit columnCountChanged(count);
}

void SSqlTableModel::setTotalRecCount(const int count)
{
    mTotalRecCount = count;
    emit totalRecCountChanged(count);
}

int SSqlTableModel::totalRecCount()
{
    return mTotalRecCount;
}

void SSqlTableModel::setMaxRecPerpage(const int count)
{
    IniLoader::saveMaxRecPerpage(count);
    emit maxRecPerpageChanged(count);
}

int SSqlTableModel::maxRecPerpage()
{
    return IniLoader::loadMaxRecPerpage();
}

void SSqlTableModel::setCurrentPage(const int page)
{
    mCurrentPage = page;
    emit currentPageChanged(page);
}

int SSqlTableModel::currentPage()
{
    return mCurrentPage;
}

void SSqlTableModel::updateTotalPageCount()
{
    int count = 0;
    if (0 >= totalRecCount())
        count = 0;
    else if (0 == totalRecCount() % maxRecPerpage())
        count = totalRecCount() / maxRecPerpage();
    else
        count = totalRecCount() / maxRecPerpage() + 1;
    setTotalPageCount(count);
}

void SSqlTableModel::setTotalPageCount(const int count)
{
    mTotalPageCount = count;
    emit totalPageCountChanged(count);
}

int SSqlTableModel::totalPageCount()
{
    return mTotalPageCount;
}

bool SSqlTableModel::setAdvancedKey(DbRec *key)
{
    return false;
}

QString SSqlTableModel::tableName() const
{
    return "";
}

bool SSqlTableModel::select()
{
    //open database
    mDatabase = DbHandler::openDb("am_mysql_table_db_connection");
    if (!mDatabase.open()) {
        qDebug() << mDatabase.lastError().text();
        return false;
    }

    //run query
    bool ret;
    ret = selectByAdvancedKey();
    if (!ret)
        return false;

    //check result
    updateTotalPageCount();
    mRowCount = mQuery.size();
    mColumnCount = mQuery.record().count();
    mHorHeaderData.clear();
    for (int i = 0; i < mColumnCount; i++) {
        mHorHeaderData.append(mQuery.record().field(i).name());
    }

    return true;
}

bool SSqlTableModel::selectByAdvancedKey()
{
    return false;
}

int SSqlTableModel::offset()
{
    return mCurrentPage * mMaxRecPerpage;
}






















