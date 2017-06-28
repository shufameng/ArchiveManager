#ifndef GDWJDETAILSFRM_H
#define GDWJDETAILSFRM_H

#include <QFrame>

namespace Ui {
class GdwjDetailsFrm;
}

class GdwjDetailsFrm : public QFrame
{
    Q_OBJECT

public:
    explicit GdwjDetailsFrm(QWidget *parent = 0);
    ~GdwjDetailsFrm();

private:
    Ui::GdwjDetailsFrm *ui;
};

#endif // GDWJDETAILSFRM_H
