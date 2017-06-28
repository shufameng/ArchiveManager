#ifndef GUIDETREEWIDGET_H
#define GUIDETREEWIDGET_H

#include <QTreeWidget>

class GuideTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit GuideTreeWidget(QWidget *parent = 0);
    ~GuideTreeWidget();

    typedef enum _FuncID {
        ID_CREATE_QZ,
        ID_SEARCH_QZ,
        ID_CREATE_AJ,
        ID_SEARCH_AJ,
        ID_CREATE_JNWJ,
        ID_SEARCH_JNWJ,
        ID_CREATE_GDWJ,
        ID_SEARCH_GDWJ,
        ID_CREATE_USER,
        ID_SEARCH_USER,
        ID_SEARCH_LOG,
        ID_BACKUP,
        ID_RESUME,
        ID_IMPORT,
        ID_EXPORT,

        ID_UNKNOWN_FUNC
    }FuncID;

protected:
    QTreeWidgetItem *createTopLevelItem(const QString &text);
    QTreeWidgetItem *createFuncItem(QTreeWidgetItem *parent, FuncID type, const QString &text);
    int itemFuncID(QTreeWidgetItem *item);

protected slots:
    void onItem(QTreeWidgetItem *item, int column);

signals:
    void funcRequest(int funcID);

private:
    void initItems();
};

#endif // GUIDETREEWIDGET_H
