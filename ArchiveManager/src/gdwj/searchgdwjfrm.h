#ifndef SEARCHGDWJFRM_H
#define SEARCHGDWJFRM_H

#include <QFrame>

namespace Ui {
class SearchGdwjFrm;
}

class SearchGdwjFrm : public QFrame
{
    Q_OBJECT

public:
    explicit SearchGdwjFrm(QWidget *parent = 0);
    ~SearchGdwjFrm();

private:
    Ui::SearchGdwjFrm *ui;
};

#endif // SEARCHGDWJFRM_H
