/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 02:00:39
 * @LastEditTime: 2020-11-10 04:53:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorWidget/IteratorWidget.cpp
 */
#include"IteratorWidget.h"

IteratorWidget::IteratorWidget(QWidget *parent)
    : 
    _edit_fx(this),
    _edit_gx(this),
    _edit_x0(this),
    _edit_x1(this),
    _aitken(this),
    _newton_original(this),
    _newton_downhill(this),
    _one_point(this),
    _two_point(this)
{
    line="";
    this->image=QImage(1200,1200,QImage::Format_RGB32);
    QColor backColor=qRgb(255,255,255);
    this->image.fill(backColor);

    setFixedSize(1200,1200);
    setWindowTitle("迭代法解方程");

    _aitken.setText("埃特肯法");
    _aitken.move(70,30);

    _newton_original.setText("牛顿迭代法");
    _newton_original.move(70,90);

    _newton_downhill.setText("牛顿下山法");
    _newton_downhill.move(70,150);

    _one_point.setText("单点弦截法");
    _one_point.move(70,210);

    _two_point.setText("双点弦截法");
    _two_point.move(70,270);

    _edit_fx.setGeometry(800,500,120,60);
    _edit_gx.setGeometry(800,550,120,60);
    _edit_x0.setGeometry(800,600,120,60);
    _edit_x1.setGeometry(800,650,120,60);
}

void IteratorWidget::paintEvent(QPaintEvent *event)
{  
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    int pointx=300,pointy=150+5;
    int width=300,height=300;
    painter.drawRect(300,5,500,300);
    painter.drawLine(300+150,pointy,pointx+width/2+100,pointy);
    //painter.drawLine(pointx,pointy-height/2,pointx,pointy+height/2);

    //绘制COS函数图像
    QPainter my_paint(this);
    my_paint.translate(-400,50);
    my_paint.setPen(QColor(0,0,255)); 
    double num_x[1000] = {0.0};
    int num_y[1000] = {0};
    double encrease = 0.1;
    for(int i = 0;i < 1000;i++)
    {
        num_x[i] += encrease;
        encrease += 0.1;
    }
    for (int i = 0;i < 1000; i++)
    {
        num_y[i] = 15*cos(num_x[i]);
    }
    for (int i = 0;i < 1000; i++) 
    {
        my_paint.drawPoint(i,400+num_y[i]);
    }
}


IteratorWidget::~IteratorWidget()
{

}
