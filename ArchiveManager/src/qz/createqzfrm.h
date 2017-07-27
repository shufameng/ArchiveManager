#ifndef CREATEQZFRM_H
#define CREATEQZFRM_H

#include <QFrame>

class QzDetailsFrm;

namespace Ui {
class CreateQzFrm;
}

class CreateQzFrm : public QFrame
{
    Q_OBJECT

public:
    explicit CreateQzFrm(QWidget *parent = 0);
    ~CreateQzFrm();

protected slots:
    void onButtonCreate();

private:
    Ui::CreateQzFrm *ui;

    QzDetailsFrm *mFrmDetails;
};

#endif // CREATEQZFRM_H
