#ifndef SSQLTABLEFRM_H
#define SSQLTABLEFRM_H

#include <QFrame>
#include <QToolBar>
#include <QTreeView>

namespace Ui {
class SSqlTableFrm;
}

class DbRec;
class SSqlTableModel;

class SSqlTableFrm : public QFrame
{
    Q_OBJECT

public:
    explicit SSqlTableFrm(QWidget *parent = 0);
    ~SSqlTableFrm();

public slots:
    QTreeView *view();
    void setTotalRecLabel(int count);
    void setTotalPageLabel(int count);
    void setCurrentPageLabel(int page);

    void toNextPage();
    void toPrevPage();
    void toFirstPage();
    void toLastPage();
    void toPage(const int page);

    void search(DbRec *key);

protected slots:
    void connectSlots();
    virtual void showViewMenu(const QPoint &pos);

private:
    Ui::SSqlTableFrm *ui;
protected:
    QToolBar *mPageToolBar;
    SSqlTableModel *mModel;
private slots:
    void on_pushButton_firstPage_clicked();
    void on_pushButton_prevPage_clicked();
    void on_pushButton_nextPage_clicked();
    void on_pushButton_lastPage_clicked();
};

#endif // SSQLTABLEFRM_H
