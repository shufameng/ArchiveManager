#ifndef CREATEUSERFRM_H
#define CREATEUSERFRM_H

#include <QFrame>

namespace Ui {
class CreateUserFrm;
}

class UserDetailsFrm;

class CreateUserFrm : public QFrame
{
    Q_OBJECT

public:
    explicit CreateUserFrm(QWidget *parent = 0);
    ~CreateUserFrm();

private slots:
    void on_pushButton_create_clicked();

private:
    Ui::CreateUserFrm *ui;
    UserDetailsFrm *mFrmDetails;
};

#endif // CREATEUSERFRM_H
