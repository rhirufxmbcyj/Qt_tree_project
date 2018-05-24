#include "treeview_demo.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QComboBox>
#include <QStandardItemModel>

QWidget *set_first_column_widget()
{
    QWidget *widget = new QWidget();
    QPushButton *icon = new QPushButton(widget);
    QLabel *label = new QLabel(widget);
    QHBoxLayout *layout = new QHBoxLayout(widget);

    icon->setFixedSize(QSize(15, 15));
    icon->setStyleSheet("QPushButton{border-image: url(:/treeview_demo/test.ico);}");
    label->setText("test 1");

    layout->addWidget(icon);
    layout->addWidget(label);
    widget->setLayout(layout);

    return widget;
}

QWidget *set_third_column_widget()
{
    QWidget *widget = new QWidget();
    QComboBox *combo = new QComboBox(widget);

    combo->addItem("test1");
    combo->addItem("test2");
    combo->addItem("test3");
    //name,style,slot,etc.

    return widget;
}

void init_tree(QTreeView *treeView, QStandardItemModel *m_model)
{
    QModelIndex first_index;
    //display 13 item in one page
    for (int i = 0; i < 13; i++)
    {
        QStandardItem *treeNode = new QStandardItem();
        m_model->appendRow(treeNode);
        first_index = m_model->indexFromItem(treeNode);
        //first column
        QWidget *first_widget = set_first_column_widget();
        treeView->setIndexWidget(first_index, first_widget);
        //second column
        m_model->setItem(first_index.row(), 1, new QStandardItem("test2"));
        //third column
        QWidget *third_widget = set_third_column_widget();
        QStandardItem *third_column = new QStandardItem();
        m_model->setItem(first_index.row(), 2, third_column);
        QModelIndex third_index = m_model->indexFromItem(third_column);
        treeView->setIndexWidget(third_index, third_widget);
        //fourth column
        m_model->setItem(first_index.row(), 3, new QStandardItem(QIcon(":/treeview_demo/test.ico"), NULL));
    }
}

treeview_demo::treeview_demo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QStandardItemModel *m_model = new QStandardItemModel(ui.treeView);
    ui.treeView->setModel(m_model);
    //about 1000ms
    init_tree(ui.treeView, m_model);
}
