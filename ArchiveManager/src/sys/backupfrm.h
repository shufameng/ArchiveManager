#ifndef BACKUPFRM_H
#define BACKUPFRM_H

#include <QFrame>

namespace Ui {
class BackupFrm;
}

class BackupFrm : public QFrame
{
    Q_OBJECT

public:
    explicit BackupFrm(QWidget *parent = 0);
    ~BackupFrm();

private:
    Ui::BackupFrm *ui;
};

#endif // BACKUPFRM_H
