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
	void paintEvent(QPaintEvent *ev);//���ػ����¼�
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
	QImage src;//���ԭͼ
	QImage out;//�����ͼ��
	QPoint mpos;//�ϴε����λ��
	QPen pen;//���ʵ�����

};
