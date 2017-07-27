#ifndef TOOLSFRM_H
#define TOOLSFRM_H

#include <QFrame>

namespace Ui {
class ToolsFrm;
}

class ToolsFrm : public QFrame
{
    Q_OBJECT

public:
    explicit ToolsFrm(QWidget *parent = 0);
    ~ToolsFrm();

private:
    Ui::ToolsFrm *ui;
};

#endif // TOOLSFRM_H
