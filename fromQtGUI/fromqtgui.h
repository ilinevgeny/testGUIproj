#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_fromqtgui.h"

class fromQtGUI : public QMainWindow
{
	Q_OBJECT

public:
	fromQtGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::fromQtGUIClass ui;
};
