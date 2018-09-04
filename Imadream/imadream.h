#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_imadream.h"

class Imadream : public QMainWindow
{
	Q_OBJECT

public:
	Imadream(QWidget *parent = Q_NULLPTR);

private:
	Ui::ImadreamClass ui;
};
