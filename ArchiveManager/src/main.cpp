#include "MainDlg.h"
#include <QApplication>
#include "common/IniLoader.h"
#include "sys/LoginDlg.h"
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ���ؽ��������ʽqss�ļ�
    QFile f("://stylesheet/default.qss");
    if (f.open(QIODevice::ReadOnly)) {
        a.setStyleSheet(f.readAll());
    }

    // Ӧ�ó����ʼ��
    IniLoader::createInis();

    // ��¼����
    LoginDlg loginDialog;
    if (QDialog::Rejected == loginDialog.exec())
        return -1;

    // ������
   MainDlg window;
   window.show();

    return a.exec();
}
