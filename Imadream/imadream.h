#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_imadream.h"
#include "ximage.h"
#include <qcolordialog.h>
#include <qbuttongroup.h>

enum STATUS_pen
{
	PEN,ERASER
};
class Imadream : public QMainWindow
{
	Q_OBJECT

public:
	STATUS_pen status = PEN;
	Imadream(QWidget *parent = Q_NULLPTR);
public slots:
	void setBrushSize();
	void setColor();
	void setPen();
	void setEraser();
	void Save();
private:
	Ui::ImadreamClass ui;
	QColor color;
	int brushsize = 1;
};
