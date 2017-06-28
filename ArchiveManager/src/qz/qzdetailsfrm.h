#ifndef QZDETAILSFRM_H
#define QZDETAILSFRM_H

#include <QFrame>

class DbQz;

namespace Ui {
class QzDetailsFrm;
}

class QzDetailsFrm : public QFrame
{
    Q_OBJECT

public:
    explicit QzDetailsFrm(QWidget *parent = 0);
    ~QzDetailsFrm();

public slots:
    void getInfo(DbQz *info);
    void setInfo(const DbQz *info);
    void cleanNotCheckedFields();
    void cleanAllFields();

    void setToAddMode();
    void setToCheckMode();
    void setToKeyMode();
    void setToEditMode();

    void updateDbLists();

private:
    Ui::QzDetailsFrm *ui;
    qint64 mID;
};

#endif // QZDETAILSFRM_H
