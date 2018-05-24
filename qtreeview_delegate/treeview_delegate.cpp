#include "treeview_delegate.h"
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QStandardItemModel>

QWidget *set_first_column_widget()
{
	QWidget *widget = new QWidget();
	QPushButton *icon = new QPushButton(widget);
	QLabel *label = new QLabel(widget);
	QHBoxLayout *layout = new QHBoxLayout(widget);

	icon->setFixedSize(QSize(15, 15));
	icon->setStyleSheet("QPushButton{border-image: url(:/treeview_delegate/test.ico);}");
	label->setText("test 1");

	layout->addWidget(icon);
	layout->addWidget(label);
	widget->setLayout(layout);

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
		QStandardItem *third_column = new QStandardItem("test3");
		m_model->setItem(first_index.row(), 2, third_column);
		QModelIndex third_index = m_model->indexFromItem(third_column);
		treeView->openPersistentEditor(third_index);
		//fourth column
		m_model->setItem(first_index.row(), 3, new QStandardItem(QIcon(":/treeview_delegate/test.ico"), NULL));
	}
}

treeview_delegate::treeview_delegate(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QStandardItemModel *m_model = new QStandardItemModel(ui.treeView);
	ui.treeView->setModel(m_model);
	ui.treeView->setItemDelegateForColumn(2, new ComboBoxDelegate(ui.treeView));
	//about 900ms
	init_tree(ui.treeView, m_model);
}


ComboBoxDelegate::ComboBoxDelegate(QObject *parent)
	:QItemDelegate(parent)
{

}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QComboBox *editor = new QComboBox(parent);
	editor->addItem("test1");
	editor->addItem("test2");
	editor->addItem("test3");
	return editor;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	QString value = index.data(Qt::EditRole).toString();
	QComboBox *cbox = static_cast<QComboBox*>(editor);
	cbox->setCurrentIndex(cbox->findText(value));
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	QComboBox *cbox = static_cast<QComboBox*>(editor);
	QString value = cbox->currentText();
	model->setData(index, value, Qt::DisplayRole);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	editor->setGeometry(option.rect);
}
