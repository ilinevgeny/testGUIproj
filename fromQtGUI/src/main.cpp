#include "ph.hpp"
#include "fromqtgui.hpp"
#include <QtWidgets/QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//a.setStyle(QStyleFactory::create("Vega"));
	fromQtGUI w;
	w.show();
	return a.exec();
}
