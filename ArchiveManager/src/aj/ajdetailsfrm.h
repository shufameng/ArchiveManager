#ifndef AJDETAILSFRM_H
#define AJDETAILSFRM_H

#include <QFrame>

namespace Ui {
class AjDetailsFrm;
}

class AjDetailsFrm : public QFrame
{
    Q_OBJECT

public:
    explicit AjDetailsFrm(QWidget *parent = 0);
    ~AjDetailsFrm();

private:
    Ui::AjDetailsFrm *ui;
};

#endif // AJDETAILSFRM_H
