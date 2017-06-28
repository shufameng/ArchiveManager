#include "ArchiveContentTreeWidget.h"
#include "DbTypes.h"
#include <QHeaderView>

ArchiveContentTreeWidget::ArchiveContentTreeWidget(QWidget *parent) :
    QTreeWidget(parent)
{
    setColumnCount(1);
    setHeaderLabels(QStringList() << QString::fromLocal8Bit("���񵼺�"));

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
    QTreeWidgetItem *topItemQz = createTopLevelItem(QString::fromLocal8Bit("ȫ��"));
    createArchiveItem(topItemQz, ArchiveFonds, QString::fromLocal8Bit("ȫ��"));

    QTreeWidgetItem *topItemAj = createTopLevelItem(QString::fromLocal8Bit("����"));
    createArchiveItem(topItemAj, ArchiveBox, QString::fromLocal8Bit("����"));
    createArchiveItem(topItemAj, ArchiveBox_KuaiJiAnJuan, QString::fromLocal8Bit("��ư���"));
    createArchiveItem(topItemAj, ArchiveBox_KeJiAnJuan, QString::fromLocal8Bit("�Ƽ�����"));
    createArchiveItem(topItemAj, ArchiveBox_WenShuAnJuan, QString::fromLocal8Bit("���鰸��"));
    createArchiveItem(topItemAj, ArchiveBox_GuiDangAnJuan, QString::fromLocal8Bit("�鵵����"));

    QTreeWidgetItem *topItemJnwj = createTopLevelItem(QString::fromLocal8Bit("�����ļ�"));
    createArchiveItem(topItemJnwj, ArchiveBook, QString::fromLocal8Bit("�����ļ�"));
    createArchiveItem(topItemJnwj, ArchiveBook_KuaiJiDangAn, QString::fromLocal8Bit("��Ƶ���"));
    createArchiveItem(topItemJnwj, ArchiveBook_YiGuRenYuanDangAn, QString::fromLocal8Bit("�ѹ���Ա����"));
    createArchiveItem(topItemJnwj, ArchiveBook_JiJianDangAn, QString::fromLocal8Bit("��������"));
    createArchiveItem(topItemJnwj, ArchiveBook_ZhaoPianDangAn, QString::fromLocal8Bit("��Ƭ����"));
    createArchiveItem(topItemJnwj, ArchiveBook_KeJiDangAn, QString::fromLocal8Bit("�Ƽ�����"));
    createArchiveItem(topItemJnwj, ArchiveBook_WenShuDangAn, QString::fromLocal8Bit("���鵵��"));

    QTreeWidgetItem *topItemGdwj = createTopLevelItem(QString::fromLocal8Bit("�鵵�ļ�"));
    createArchiveItem(topItemGdwj, ArchiveArchv_WenShu, QString::fromLocal8Bit("�鵵�ļ�"));
}
