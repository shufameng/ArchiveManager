#ifndef DELETEBUTTONCOMBOBOX_H
#define DELETEBUTTONCOMBOBOX_H

#include <QComboBox>
#include <QListWidget>
#include <QHBoxLayout>
#include <QToolButton>

///
/// \brief The DeleteButtonItemWidget class
/// ��Widget��һ��ˮƽ�������,ˮƽ���������һ������,�Ҳ���һ��ɾ����ť
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
/// ��Listwidget��ÿһ�е�item�ĺ󲿶���һ��ɾ����ť,
/// �����ɾ����ť����ɾ����Ӧ�е�item,
/// ��������DeleteButtonComboBox������������
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
/// ��Combobox���������е�ÿһ�ж�����һ��ɾ����ť,
/// �����ɾ����ť����ɾ����Ӧ��item
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
