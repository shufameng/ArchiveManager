#ifndef IMPORTFRM_H
#define IMPORTFRM_H

#include <QFrame>

namespace Ui {
class ImportFrm;
}

class ImportFrm : public QFrame
{
    Q_OBJECT

public:
    explicit ImportFrm(QWidget *parent = 0);
    ~ImportFrm();

private:
    Ui::ImportFrm *ui;
};

#endif // IMPORTFRM_H
