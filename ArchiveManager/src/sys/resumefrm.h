#ifndef RESUMEFRM_H
#define RESUMEFRM_H

#include <QFrame>

namespace Ui {
class ResumeFrm;
}

class ResumeFrm : public QFrame
{
    Q_OBJECT

public:
    explicit ResumeFrm(QWidget *parent = 0);
    ~ResumeFrm();

private:
    Ui::ResumeFrm *ui;
};

#endif // RESUMEFRM_H
