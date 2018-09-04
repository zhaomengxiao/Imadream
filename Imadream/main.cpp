#include "imadream.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Imadream w;
	w.show();
	return a.exec();
}
