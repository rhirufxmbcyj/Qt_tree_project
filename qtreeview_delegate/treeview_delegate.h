#ifndef TREE_VIEW_DELEGATE_H
#define TREE_VIEW_DELEGATE_H

#include <QtWidgets/QMainWindow>
#include "ui_treeview_delegate.h"
#include <QItemDelegate>

class treeview_delegate : public QMainWindow
{
	Q_OBJECT

public:
	treeview_delegate(QWidget *parent = Q_NULLPTR);

private:
	Ui::treeview_delegateClass ui;
};

class ComboBoxDelegate : public QItemDelegate
{
	Q_OBJECT
public:
	ComboBoxDelegate(QObject *parent = 0);

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
	void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif