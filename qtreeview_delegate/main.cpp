#include "treeview_delegate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	treeview_delegate w;
	w.show();
	return a.exec();
}
