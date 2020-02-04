#pragma once
#include "ph.hpp"
//#include <QtWidgets/QMainWindow>
#include "ui_fromqtgui.h"

class fromQtGUI : public QMainWindow
{
	Q_OBJECT

public:
	fromQtGUI(QWidget *parent = Q_NULLPTR);
	QBoxLayout *centralLayout;
	QBoxLayout *mainTLayout;

private:
	Ui::fromQtGUIClass ui;
	QPushButton *generateB;
	QTextEdit *status;

	QTableView *configxTbl;
	QTableView *conceptxTbl;
	QTableView *setxTbl;
};
