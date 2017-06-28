#include "DeleteButtonComboBox.h"

DeleteButtonComboBox::DeleteButtonComboBox(QWidget *parent) :
    QComboBox(parent)
{
    setEditable(true);
    mPopWidget = new DeleteButtonListWidget(this);
    setModel(mPopWidget->model());
    setView(mPopWidget);
    connect(mPopWidget, SIGNAL(itemRemoved(QString)), this, SIGNAL(itemRemoved(QString)));
}

void DeleteButtonComboBox::addItem(const QString &text)
{
    mPopWidget->addItem(text);
}

void DeleteButtonComboBox::addItems(const QStringList &texts)
{
    mPopWidget->addItems(texts);
}

void DeleteButtonComboBox::removeItem(int index)
{
    mPopWidget->removeItem(index);
}





DeleteButtonListWidget::DeleteButtonListWidget(QWidget *parent) :
    QListWidget(parent)
{

}

void DeleteButtonListWidget::updateItemWidgets()
{
    DeleteButtonItemWidget *w;
    for (int i = 0; i < count(); i ++) {
        w = dynamic_cast<DeleteButtonItemWidget*>(itemWidget(item(i)));
        if (w) {
            w->setRow(i);
        } else {
            w = new DeleteButtonItemWidget(i, this);
            setItemWidget(item(i), w);
            connect(w, SIGNAL(deleteButtonClicked(int)), this, SLOT(removeItem(int)));
        }
    }
}

void DeleteButtonListWidget::addItem(const QString &label)
{
    QListWidget::addItem(label);
    updateItemWidgets();
}

void DeleteButtonListWidget::addItems(const QStringList &labels)
{
    QListWidget::addItems(labels);
    updateItemWidgets();
}

void DeleteButtonListWidget::removeItem(const QString &label)
{
    for (int i = 0; i < count(); i ++) {
        if (item(i)->text() == label) {
            QListWidgetItem *item = takeItem(i);
            emit itemRemoved(item->text());
            updateItemWidgets();
            delete item;
            break;
        }
    }
}

void DeleteButtonListWidget::removeItem(const int row)
{
    if (row < count()) {
        QListWidgetItem *item = takeItem(row);
        emit itemRemoved(item->text());
        updateItemWidgets();
        delete item;
    }
}





DeleteButtonItemWidget::DeleteButtonItemWidget(const int row, QWidget *parent) :
    QWidget(parent),
    mRow(row)
{
    QToolButton *delBtn = new QToolButton(this);
    QHBoxLayout *hLay = new QHBoxLayout(this);
    hLay->setContentsMargins(0, 0, 0, 0);
    hLay->addStretch();
    hLay->addWidget(delBtn);
    delBtn->setIcon(style()->standardIcon(QStyle::SP_DialogCloseButton));
    delBtn->setFixedSize(16, 16);
    connect(delBtn, SIGNAL(clicked()), this, SLOT(onDeleteButtonClicked()));
}
