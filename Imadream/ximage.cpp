#include "ximage.h"
#include <iostream>
#include <Qimage>
Ximage::Ximage(QWidget *parent)
	: QWidget(parent)
{
}

Ximage::~Ximage()
{
}

void Ximage::Open() {
	//��ͼ�� �û�ѡ��ͼƬ
	QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("��ͼƬ"),
		"", QStringLiteral("֧�ָ�ʽ(*.png *.jpg *.bmp)"));
	if (filename.isEmpty()) {
		std::cout << "cant read filename";
		return;
	}
	src.load(filename);
	if (src.isNull()) {
		std::cout << "cant load" << std::endl;
		return;
	}

	resize(src.size());
	update();
	mpos = QPoint();
	out = src.copy();
}

void Ximage::paintEvent(QPaintEvent * ev)
{
	QPainter p(this);
	//��ʾԭͼ
	if (!out.isNull())
		p.drawImage(0, 0, out);
}

void Ximage::mouseMoveEvent(QMouseEvent * ev)
{
	if (out.isNull()) return;
	//���Ƶ����ͼout��
	QPainter p(&out);
	
	
	p.setPen(pen);
	p.setRenderHint(QPainter::Antialiasing);//�����
	if (mpos.isNull()){
		mpos = ev->pos();
	}
	p.drawLine(QLine(mpos,ev->pos()));
	mpos = ev->pos();
	update();
}

void Ximage::setPen(int size, QColor color)
{
	pen.setBrush(color);
	pen.setWidth(size);
	pen.setCapStyle(Qt::RoundCap);//Բ��
	pen.setJoinStyle(Qt::RoundJoin);
}

void Ximage::setEraser(int size)
{
	pen.setWidth(size);
	//��ԭͼ�൱�ڸ�ԭ
	pen.setBrush(src);
}

void Ximage::Save()
{
	if (out.isNull())return;
	QString filename = QFileDialog::getSaveFileName(this,
		QStringLiteral("�����ļ�"),"", QStringLiteral("֧���ļ�(*.png *.jpg *.bmp)"));
	if (filename.isNull())return;
	if (!out.save(filename))return;
}