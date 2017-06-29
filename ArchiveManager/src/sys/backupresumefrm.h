#ifndef BACKUPRESUMEFRM_H
#define BACKUPRESUMEFRM_H

#include <QFrame>

namespace Ui {
class BackupResumeFrm;
}

class BackupResumeFrm : public QFrame
{
    Q_OBJECT

public:
    explicit BackupResumeFrm(QWidget *parent = 0);
    ~BackupResumeFrm();

private:
    Ui::BackupResumeFrm *ui;
};

#endif // BACKUPRESUMEFRM_H
