#ifndef SSQLTABLEMODEL_H
#define SSQLTABLEMODEL_H

#include <QAbstractItemModel>
#include <QtSql>
#include <QTextDocument>

class DbRec;

class SSqlTableModel : public QAbstractItemModel
{
    Q_OBJECT
public:

    SSqlTableModel(QObject *parent = 0);
    ~SSqlTableModel();

    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    virtual QModelIndex parent(const QModelIndex &child) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                    int role = Qt::DisplayRole) const;
    virtual bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value,
                               int role = Qt::EditRole);

public slots:

    virtual void rowInfo(const int row, DbRec *info); //
    virtual qint64 rowInfoId(const int row);//
    virtual void print(QTextDocument *doc);//

public slots:
    void toNextPage();
    void toPrevPage();
    void toFirstPage();
    void toLastPage();
    void toPage(const int page);

    void setMaxRecPerpage(const int count);
    int maxRecPerpage();
    int totalRecCount();
    int currentPage();
    int totalPageCount();

    virtual bool setAdvancedKey(DbRec *key);//
    virtual QString tableName() const;//

    bool select();

protected slots:
    void setRowCount(const int count);
    void setColumnCount(const int count);
    void setTotalRecCount(const int count);
    void setCurrentPage(const int page);
    void updateTotalPageCount();
    void setTotalPageCount(const int count);

    virtual bool selectByAdvancedKey();//
    int offset();

signals:
    void rowCountChanged(int current = 0);
    void columnCountChanged(int current = 0);
    void totalRecCountChanged(int current = 0);
    void totalPageCountChanged(int current = 0);
    void maxRecPerpageChanged(int current = 0);
    void currentPageChanged(int current = 0);

protected:
    mutable QSqlQuery mQuery;
    int             mRowCount;
    int             mColumnCount;

    QVariantList mHorHeaderData;

    int             mTotalRecCount;
    int             mTotalPageCount;
    int             mMaxRecPerpage;
    int             mCurrentPage;

    DbRec        *mAdvancedKey;
    QSqlDatabase mDatabase;

};

#endif // SSQLTABLEMODEL_H
