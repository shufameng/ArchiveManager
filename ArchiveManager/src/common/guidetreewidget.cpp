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
    QTreeWidgetItem *itemQz = createTopLevelItem(QString::fromLocal8Bit("全宗管理"));
    createFuncItem(itemQz, ID_CREATE_QZ, QString::fromLocal8Bit("全宗录入"));
    createFuncItem(itemQz, ID_SEARCH_QZ, QString::fromLocal8Bit("全宗检索"));

    QTreeWidgetItem *itemAj = createTopLevelItem(QString::fromLocal8Bit("案卷管理"));
    createFuncItem(itemAj, ID_CREATE_AJ, QString::fromLocal8Bit("案卷录入"));
    createFuncItem(itemAj, ID_SEARCH_AJ, QString::fromLocal8Bit("案卷检索"));

    QTreeWidgetItem *itemJnwj = createTopLevelItem(QString::fromLocal8Bit("卷内管理"));
    createFuncItem(itemJnwj, ID_CREATE_JNWJ, QString::fromLocal8Bit("卷内录入"));
    createFuncItem(itemJnwj, ID_SEARCH_JNWJ, QString::fromLocal8Bit("卷内检索"));

    QTreeWidgetItem *itemGdwj = createTopLevelItem(QString::fromLocal8Bit("归档管理")); 
    createFuncItem(itemGdwj, ID_CREATE_GDWJ, QString::fromLocal8Bit("归档录入"));
    createFuncItem(itemGdwj, ID_SEARCH_GDWJ, QString::fromLocal8Bit("归档检索"));

    QTreeWidgetItem *itemImportExport = createTopLevelItem(QString::fromLocal8Bit("移交接收"));
    createFuncItem(itemImportExport, ID_EXPORT, QString::fromLocal8Bit("移交"));
    createFuncItem(itemImportExport, ID_IMPORT, QString::fromLocal8Bit("接收"));

    QTreeWidgetItem *itemBackupResume = createTopLevelItem(QString::fromLocal8Bit("备份还原"));
    createFuncItem(itemBackupResume, ID_BACKUP, QString::fromLocal8Bit("备份"));
    createFuncItem(itemBackupResume, ID_RESUME, QString::fromLocal8Bit("还原"));

    QTreeWidgetItem *itemSystemUser = createTopLevelItem(QString::fromLocal8Bit("系统用户"));
    createFuncItem(itemSystemUser, ID_CREATE_USER, QString::fromLocal8Bit("新建用户"));
    createFuncItem(itemSystemUser, ID_SEARCH_USER, QString::fromLocal8Bit("检索用户"));

    QTreeWidgetItem *itemSystemLog = createTopLevelItem(QString::fromLocal8Bit("系统日志"));
    createFuncItem(itemSystemLog, ID_SEARCH_LOG, QString::fromLocal8Bit("检索日志"));
}



