#include "MainDlg.h"
#include <QApplication>
#include "common/IniLoader.h"
#include "sys/LoginDlg.h"
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 加载界面组件样式qss文件
    QFile f("://stylesheet/default.qss");
    if (f.open(QIODevice::ReadOnly)) {
        a.setStyleSheet(f.readAll());
    }

    // 应用程序初始化
    IniLoader::createInis();

    // 登录窗口
    LoginDlg loginDialog;
    if (QDialog::Rejected == loginDialog.exec())
        return -1;

    // 主窗口
   MainDlg window;
   window.show();

    return a.exec();
}
