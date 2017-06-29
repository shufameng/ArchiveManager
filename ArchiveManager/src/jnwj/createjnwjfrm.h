#ifndef CREATEJNWJFRM_H
#define CREATEJNWJFRM_H

#include <QFrame>

namespace Ui {
class CreateJnwjFrm;
}

class JnwjDetailsFrm;

class CreateJnwjFrm : public QFrame
{
    Q_OBJECT

public:
    explicit CreateJnwjFrm(QWidget *parent = 0);
    ~CreateJnwjFrm();

private:
    Ui::CreateJnwjFrm *ui;
    JnwjDetailsFrm *mFrmDetails;
};

#endif // CREATEJNWJFRM_H
