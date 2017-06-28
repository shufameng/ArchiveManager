#ifndef SEARCHQZFRM_H
#define SEARCHQZFRM_H

#include <QFrame>

namespace Ui {
class SearchQzFrm;
}

class SearchQzFrm : public QFrame
{
    Q_OBJECT

public:
    explicit SearchQzFrm(QWidget *parent = 0);
    ~SearchQzFrm();

private:
    Ui::SearchQzFrm *ui;
};

#endif // SEARCHQZFRM_H
