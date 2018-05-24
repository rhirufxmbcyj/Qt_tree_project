#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_treeview_demo.h"

class treeview_demo : public QMainWindow
{
    Q_OBJECT

public:
    treeview_demo(QWidget *parent = Q_NULLPTR);

private:
    Ui::treeview_demoClass ui;
};
