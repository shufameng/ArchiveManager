#ifndef CREATEAJFRM_H
#define CREATEAJFRM_H

#include <QFrame>

namespace Ui {
class CreateAjFrm;
}

class AjDetailsFrm;

class CreateAjFrm : public QFrame
{
    Q_OBJECT

public:
    explicit CreateAjFrm(QWidget *parent = 0);
    ~CreateAjFrm();

private:
    Ui::CreateAjFrm *ui;

    AjDetailsFrm *mFrmDetails;
};

#endif // CREATEAJFRM_H
