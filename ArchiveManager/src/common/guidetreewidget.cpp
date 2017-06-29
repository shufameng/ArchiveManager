#include "guidetreewidget.h"

GuideTreeWidget::GuideTreeWidget(QWidget *parent) :
    QTreeWidget(parent)
{
    setMinimumWidth(200);
    initItems();

    connect(this, SIGNAL(itemClicked(QTreeWidgetItem*,int)),
            this, SLOT(onItem(QTreeWidgetItem*,int)));
}

GuideTreeWidget::~GuideTreeWidget()
{

}

QTreeWidgetItem *GuideTreeWidget::createTopLevelItem(const QString &text)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(this, QStringList() << text);
    addTopLevelItem(item);
    return item;
}

QTreeWidgetItem *GuideTreeWidget::createFuncItem(QTreeWidgetItem *parent, GuideTreeWidget::FuncID type, const QString &text)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent, QStringList() << text);
    item->setData(0, Qt::UserRole + 1, type);
    return item;
}

int GuideTreeWidget::itemFuncID(QTreeWidgetItem *item)
{
    if (!item)
        return ID_UNKNOWN_FUNC;

    if (item->data(0, Qt::UserRole + 1).isNull())
        return ID_UNKNOWN_FUNC;

    return item->data(0, Qt::UserRole + 1).toInt();
}

void GuideTreeWidget::onItem(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);
    if (!item)
        return;

    int id = itemFuncID(item);
    if (ID_UNKNOWN_FUNC != id)
        emit funcRequest(id);
}

void GuideTreeWidget::initItems()
{
    QTreeWidgetItem *itemQz = createTopLevelItem(QString::fromLocal8Bit("ȫ�ڹ���"));
    createFuncItem(itemQz, ID_CREATE_QZ, QString::fromLocal8Bit("ȫ��¼��"));
    createFuncItem(itemQz, ID_SEARCH_QZ, QString::fromLocal8Bit("ȫ�ڼ���"));

    QTreeWidgetItem *itemAj = createTopLevelItem(QString::fromLocal8Bit("�������"));
    createFuncItem(itemAj, ID_CREATE_AJ, QString::fromLocal8Bit("����¼��"));
    createFuncItem(itemAj, ID_SEARCH_AJ, QString::fromLocal8Bit("�������"));

    QTreeWidgetItem *itemJnwj = createTopLevelItem(QString::fromLocal8Bit("���ڹ���"));
    createFuncItem(itemJnwj, ID_CREATE_JNWJ, QString::fromLocal8Bit("����¼��"));
    createFuncItem(itemJnwj, ID_SEARCH_JNWJ, QString::fromLocal8Bit("���ڼ���"));

    QTreeWidgetItem *itemGdwj = createTopLevelItem(QString::fromLocal8Bit("�鵵����")); 
    createFuncItem(itemGdwj, ID_CREATE_GDWJ, QString::fromLocal8Bit("�鵵¼��"));
    createFuncItem(itemGdwj, ID_SEARCH_GDWJ, QString::fromLocal8Bit("�鵵����"));

    QTreeWidgetItem *itemImportExport = createTopLevelItem(QString::fromLocal8Bit("�ƽ�����"));
    createFuncItem(itemImportExport, ID_EXPORT, QString::fromLocal8Bit("�ƽ�"));
    createFuncItem(itemImportExport, ID_IMPORT, QString::fromLocal8Bit("����"));

    QTreeWidgetItem *itemBackupResume = createTopLevelItem(QString::fromLocal8Bit("���ݻ�ԭ"));
    createFuncItem(itemBackupResume, ID_BACKUP, QString::fromLocal8Bit("����"));
    createFuncItem(itemBackupResume, ID_RESUME, QString::fromLocal8Bit("��ԭ"));

    QTreeWidgetItem *itemSystemUser = createTopLevelItem(QString::fromLocal8Bit("ϵͳ�û�"));
    createFuncItem(itemSystemUser, ID_CREATE_USER, QString::fromLocal8Bit("�½��û�"));
    createFuncItem(itemSystemUser, ID_SEARCH_USER, QString::fromLocal8Bit("�����û�"));

    QTreeWidgetItem *itemSystemLog = createTopLevelItem(QString::fromLocal8Bit("ϵͳ��־"));
    createFuncItem(itemSystemLog, ID_SEARCH_LOG, QString::fromLocal8Bit("������־"));
}



