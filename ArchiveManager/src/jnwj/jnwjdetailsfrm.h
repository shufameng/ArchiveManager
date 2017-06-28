#ifndef JNWJDETAILSFRM_H
#define JNWJDETAILSFRM_H

#include <QFrame>

namespace Ui {
class JnwjDetailsFrm;
}

class JnwjDetailsFrm : public QFrame
{
    Q_OBJECT

public:
    explicit JnwjDetailsFrm(QWidget *parent = 0);
    ~JnwjDetailsFrm();

private:
    Ui::JnwjDetailsFrm *ui;
};

#endif // JNWJDETAILSFRM_H
