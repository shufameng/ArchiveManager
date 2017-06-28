#include "ArchiveContentTreeWidget.h"
#include "DbTypes.h"
#include <QHeaderView>

ArchiveContentTreeWidget::ArchiveContentTreeWidget(QWidget *parent) :
    QTreeWidget(parent)
{
    setColumnCount(1);
    setHeaderLabels(QStringList() << QString::fromLocal8Bit("窗格导航"));

    initItems();
}

QTreeWidgetItem *ArchiveContentTreeWidget::createTopLevelItem(const QString &text)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(this, QStringList() << text);
    addTopLevelItem(item);
    return item;
}

QTreeWidgetItem *ArchiveContentTreeWidget::createArchiveItem(QTreeWidgetItem *parent, const int archiveType, const QString &text)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent, QStringList() << text);
    item->setData(0, ArchiveTypeRole, archiveType);
    return item;
}

void ArchiveContentTreeWidget::initItems()
{
    QTreeWidgetItem *topItemQz = createTopLevelItem(QString::fromLocal8Bit("全宗"));
    createArchiveItem(topItemQz, ArchiveFonds, QString::fromLocal8Bit("全宗"));

    QTreeWidgetItem *topItemAj = createTopLevelItem(QString::fromLocal8Bit("案卷"));
    createArchiveItem(topItemAj, ArchiveBox, QString::fromLocal8Bit("案卷"));
    createArchiveItem(topItemAj, ArchiveBox_KuaiJiAnJuan, QString::fromLocal8Bit("会计案卷"));
    createArchiveItem(topItemAj, ArchiveBox_KeJiAnJuan, QString::fromLocal8Bit("科技案卷"));
    createArchiveItem(topItemAj, ArchiveBox_WenShuAnJuan, QString::fromLocal8Bit("文书案卷"));
    createArchiveItem(topItemAj, ArchiveBox_GuiDangAnJuan, QString::fromLocal8Bit("归档案卷"));

    QTreeWidgetItem *topItemJnwj = createTopLevelItem(QString::fromLocal8Bit("卷内文件"));
    createArchiveItem(topItemJnwj, ArchiveBook, QString::fromLocal8Bit("卷内文件"));
    createArchiveItem(topItemJnwj, ArchiveBook_KuaiJiDangAn, QString::fromLocal8Bit("会计档案"));
    createArchiveItem(topItemJnwj, ArchiveBook_YiGuRenYuanDangAn, QString::fromLocal8Bit("已故人员档案"));
    createArchiveItem(topItemJnwj, ArchiveBook_JiJianDangAn, QString::fromLocal8Bit("基建档案"));
    createArchiveItem(topItemJnwj, ArchiveBook_ZhaoPianDangAn, QString::fromLocal8Bit("照片档案"));
    createArchiveItem(topItemJnwj, ArchiveBook_KeJiDangAn, QString::fromLocal8Bit("科技档案"));
    createArchiveItem(topItemJnwj, ArchiveBook_WenShuDangAn, QString::fromLocal8Bit("文书档案"));

    QTreeWidgetItem *topItemGdwj = createTopLevelItem(QString::fromLocal8Bit("归档文件"));
    createArchiveItem(topItemGdwj, ArchiveArchv_WenShu, QString::fromLocal8Bit("归档文件"));
}
