#ifndef EXPORTFRM_H
#define EXPORTFRM_H

#include <QFrame>

namespace Ui {
class ExportFrm;
}

class ExportFrm : public QFrame
{
    Q_OBJECT

public:
    explicit ExportFrm(QWidget *parent = 0);
    ~ExportFrm();

private:
    Ui::ExportFrm *ui;
};

#endif // EXPORTFRM_H
