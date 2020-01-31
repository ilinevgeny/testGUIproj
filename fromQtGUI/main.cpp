#include "fromqtgui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	fromQtGUI w;
	w.show();
	return a.exec();
}
