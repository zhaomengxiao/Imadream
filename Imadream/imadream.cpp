#include "imadream.h"

Imadream::Imadream(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.action_open, SIGNAL(triggered()), ui.imageWindow, SLOT(Open()));
	connect(ui.action_save, SIGNAL(triggered()), ui.imageWindow, SLOT(Save()));
	color = QColor(200, 0, 0, 255);
	setPen();
	//橡皮和画笔排他选择

	QButtonGroup *gp = new QButtonGroup(this);
	gp->addButton(ui.pushButton_pen);
	gp->addButton(ui.pushButton_eraser);
	gp->setExclusive(true);

}

void Imadream::setColor()
{
	color = QColorDialog::getColor(Qt::red, this);
	QString sty = QString("background-color:rgba(%1,%2,%3,%4)")
		.arg(color.red()).arg(color.green()).arg(color.blue()).arg(color.alpha());
	ui.pushButton_palette->setStyleSheet(sty);

	setPen();


}
void Imadream::setBrushSize()
{
	brushsize = ui.Slider_pensize->value();
	if (status == PEN){setPen();}
	else{setEraser();}
}

void Imadream::setPen() {
	ui.imageWindow->setPen(brushsize, color);
	status = PEN;
	ui.pushButton_pen->setChecked(true);

}

void Imadream::setEraser()
{
	ui.imageWindow->setEraser(brushsize);
	status = ERASER;
	ui.pushButton_eraser->setChecked(true);
}

void Imadream::Save()
{
	ui.imageWindow->Save();
	ui.statusBar->showMessage(QStringLiteral("图像已保存(=^ ^=)"),5000);

}
