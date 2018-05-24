#include "treewidget_demo.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QComboBox>

QWidget *set_first_column_widget()
{
    QWidget *widget = new QWidget();
    QPushButton *icon = new QPushButton(widget);
    QLabel *label = new QLabel(widget);
    QHBoxLayout *layout = new QHBoxLayout(widget);

    icon->setFixedSize(QSize(15, 15));
    icon->setStyleSheet("QPushButton{border-image: url(:/treewidget_demo/test.ico);}");
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

void init_tree(QTreeWidget *treeWidget)
{
    //display 13 item in one page
    for (int i = 0; i < 13; i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget);
        //first column
        QWidget *first_widget = set_first_column_widget();
        treeWidget->setItemWidget(item, 0, first_widget);
        //second column
        item->setText(1, "test 2");
        //third column
        QWidget *third_widget = set_third_column_widget();
        treeWidget->setItemWidget(item, 2, third_widget);
        //fourth column
        item->setIcon(3, QIcon(":/treewidget_demo/test.ico"));
    }
}

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.treeWidget->setColumnCount(4);
    //about 1000ms
    init_tree(ui.treeWidget);
}
