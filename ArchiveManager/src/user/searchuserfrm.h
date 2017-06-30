#ifndef SEARCHUSERFRM_H
#define SEARCHUSERFRM_H

#include <QFrame>

namespace Ui {
class SearchUserFrm;
}

class SearchUserFrm : public QFrame
{
    Q_OBJECT

public:
    explicit SearchUserFrm(QWidget *parent = 0);
    ~SearchUserFrm();

private:
    Ui::SearchUserFrm *ui;
};

#endif // SEARCHUSERFRM_H
