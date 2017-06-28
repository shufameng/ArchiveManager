#ifndef SEARCHLOGFRM_H
#define SEARCHLOGFRM_H

#include <QFrame>

namespace Ui {
class SearchLogFrm;
}

class SearchLogFrm : public QFrame
{
    Q_OBJECT

public:
    explicit SearchLogFrm(QWidget *parent = 0);
    ~SearchLogFrm();

private:
    Ui::SearchLogFrm *ui;
};

#endif // SEARCHLOGFRM_H
