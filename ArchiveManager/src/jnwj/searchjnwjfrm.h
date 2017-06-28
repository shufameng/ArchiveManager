#ifndef SEARCHJNWJFRM_H
#define SEARCHJNWJFRM_H

#include <QFrame>

namespace Ui {
class SearchJnwjFrm;
}

class SearchJnwjFrm : public QFrame
{
    Q_OBJECT

public:
    explicit SearchJnwjFrm(QWidget *parent = 0);
    ~SearchJnwjFrm();

private:
    Ui::SearchJnwjFrm *ui;
};

#endif // SEARCHJNWJFRM_H
