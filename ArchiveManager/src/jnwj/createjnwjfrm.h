#ifndef CREATEJNWJFRM_H
#define CREATEJNWJFRM_H

#include <QFrame>

namespace Ui {
class CreateJnwjFrm;
}

class CreateJnwjFrm : public QFrame
{
    Q_OBJECT

public:
    explicit CreateJnwjFrm(QWidget *parent = 0);
    ~CreateJnwjFrm();

private:
    Ui::CreateJnwjFrm *ui;
};

#endif // CREATEJNWJFRM_H
