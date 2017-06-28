#ifndef ARCHIVECONTENTTREEWIDGET_H
#define ARCHIVECONTENTTREEWIDGET_H


#include <QTreeWidget>

class ArchiveContentTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:  
    ArchiveContentTreeWidget(QWidget *parent = 0);

    QTreeWidgetItem *createTopLevelItem(const QString &text);
    QTreeWidgetItem *createArchiveItem(QTreeWidgetItem *parent, const int archiveType, const QString &text);

protected:
    void initItems();

    enum DataRole {
        ArchiveTypeRole = Qt::UserRole + 1
    };

};

#endif // ARCHIVECONTENTTREEWIDGET_H
