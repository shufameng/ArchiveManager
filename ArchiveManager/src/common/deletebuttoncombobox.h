#ifndef DELETEBUTTONCOMBOBOX_H
#define DELETEBUTTONCOMBOBOX_H

#include <QComboBox>
#include <QListWidget>
#include <QHBoxLayout>
#include <QToolButton>

///
/// \brief The DeleteButtonItemWidget class
/// 该Widget由一个水平布局组成,水平布局左侧是一个拉伸,右侧是一个删除按钮
///
class DeleteButtonItemWidget : public QWidget
{
    Q_OBJECT
public:
    DeleteButtonItemWidget(const int row, QWidget *parent);
public slots:
    void setRow(const int row)  { mRow = row; }
    int     row() const                 { return mRow; }
protected slots:
    void onDeleteButtonClicked() { emit deleteButtonClicked(mRow); }
signals:
    void deleteButtonClicked(const int row);
private:
    int mRow;
};

///
/// \brief The DeleteButtonListWidget class
/// 该Listwidget的每一行的item的后部都有一个删除按钮,
/// 点击该删除按钮即可删除对应行的item,
/// 该类用作DeleteButtonComboBox类的下拉框组件
///
class DeleteButtonListWidget : public QListWidget
{
    Q_OBJECT
public:
    DeleteButtonListWidget(QWidget *parent = 0);
protected slots:
    void updateItemWidgets();
public slots:
    void addItem(const QString &label);
    void addItems(const QStringList &labels);
    void removeItem(const QString &label);
    void removeItem(const int row);
signals:
    void itemRemoved(const QString &itemText);
};

///
/// \brief The DeleteButtonComboBox class
/// 该Combobox的下拉框中的每一行都带有一个删除按钮,
/// 点击该删除按钮即可删除对应的item
///
class DeleteButtonComboBox : public QComboBox
{
    Q_OBJECT
public:
    DeleteButtonComboBox(QWidget *parent = 0);
public slots:
    void addItem(const QString &text);
    void addItems(const QStringList &texts);
    void removeItem(int index);
signals:
    void itemRemoved(const QString &itemText);
private:
    DeleteButtonListWidget *mPopWidget;
};

#endif // DELETEBUTTONCOMBOBOX_H
