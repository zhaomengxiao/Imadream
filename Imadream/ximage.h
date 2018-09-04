#pragma once

#include <QWidget>

class Ximage : public QWidget
{
	Q_OBJECT

public:
	Ximage(QWidget *parent);
	~Ximage();

public slots:
	void open();
};
