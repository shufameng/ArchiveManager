#ifndef IMPORTEXPORTFRM_H
#define IMPORTEXPORTFRM_H

#include <QFrame>

namespace Ui {
class ImportExportFrm;
}

class ImportExportFrm : public QFrame
{
    Q_OBJECT

public:
    explicit ImportExportFrm(QWidget *parent = 0);
    ~ImportExportFrm();

private:
    Ui::ImportExportFrm *ui;
};

#endif // IMPORTEXPORTFRM_H
