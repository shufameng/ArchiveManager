#ifndef SEARCHAJFRM_H
#define SEARCHAJFRM_H

#include <QFrame>

namespace Ui {
class SearchAjFrm;
}

class SearchAjFrm : public QFrame
{
    Q_OBJECT

public:
    explicit SearchAjFrm(QWidget *parent = 0);
    ~SearchAjFrm();

private:
    Ui::SearchAjFrm *ui;
};

#endif // SEARCHAJFRM_H
