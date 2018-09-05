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
	//打开图像 用户选择图片
	QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("打开图片"),
		"", QStringLiteral("支持格式(*.png *.jpg *.bmp)"));
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
	//显示原图
	if (!out.isNull())
		p.drawImage(0, 0, out);
}

void Ximage::mouseMoveEvent(QMouseEvent * ev)
{
	if (out.isNull()) return;
	//绘制到输出图out中
	QPainter p(&out);
	
	
	p.setPen(pen);
	p.setRenderHint(QPainter::Antialiasing);//抗锯齿
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
	pen.setCapStyle(Qt::RoundCap);//圆角
	pen.setJoinStyle(Qt::RoundJoin);
}

void Ximage::setEraser(int size)
{
	pen.setWidth(size);
	//画原图相当于复原
	pen.setBrush(src);
}

void Ximage::Save()
{
	if (out.isNull())return;
	QString filename = QFileDialog::getSaveFileName(this,
		QStringLiteral("保存文件"),"", QStringLiteral("支持文件(*.png *.jpg *.bmp)"));
	if (filename.isNull())return;
	if (!out.save(filename))return;
}