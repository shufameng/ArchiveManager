#ifndef USERDETAILSFRM_H
#define USERDETAILSFRM_H

#include <QFrame>

class DbUser;

namespace Ui {
class UserDetailsFrm;
}

class UserDetailsFrm : public QFrame
{
    Q_OBJECT

public:
    explicit UserDetailsFrm(QWidget *parent = 0);
    ~UserDetailsFrm();

public slots:
    void getInfo(DbUser *info);
    void setInfo(const DbUser *info);
    void cleanNotCheckedFields();
    void cleanAllFields();

    void setToAddMode();
    void setToCheckMode();
    void setToKeyMode();
    void setToEditMode();

private:
    Ui::UserDetailsFrm *ui;
    qint64 mID;
};

#endif // USERDETAILSFRM_H
