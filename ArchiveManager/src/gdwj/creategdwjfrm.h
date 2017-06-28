#ifndef CREATEGDWJFRM_H
#define CREATEGDWJFRM_H

#include <QFrame>

namespace Ui {
class CreateGdwjFrm;
}

class CreateGdwjFrm : public QFrame
{
    Q_OBJECT

public:
    explicit CreateGdwjFrm(QWidget *parent = 0);
    ~CreateGdwjFrm();

private:
    Ui::CreateGdwjFrm *ui;
};

#endif // CREATEGDWJFRM_H
