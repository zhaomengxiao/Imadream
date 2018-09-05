#pragma once

#include <QWidget>
#include <QPainter>
#include <qfiledialog.h>
#include <QMouseEvent>
#include <Qpen>
class Ximage : public QWidget
{
	Q_OBJECT

public:
	Ximage(QWidget *parent = 0);
	~Ximage();
	void paintEvent(QPaintEvent *ev);//重载绘制事件
	void mouseMoveEvent(QMouseEvent *ev);
	void mouseReleaseEvent(QMouseEvent *ev) {
		mpos = QPoint();
	}
public slots:
	void Open();
	void Save();
	void setPen(int size,QColor color);
	void setEraser(int size);
protected:
	QImage src;//存放原图
	QImage out;//输出用图像
	QPoint mpos;//上次的鼠标位子
	QPen pen;//画笔的设置

};
