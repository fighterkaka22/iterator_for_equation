/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 02:00:39
 * @LastEditTime: 2020-11-09 06:32:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorWidget/IteratorWidget.cpp
 */
#include"IteratorWidget.h"

IteratorWidget::IteratorWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(1200,1200);
    setWindowTitle("迭代法解方程");

    QPushButton *aitken = new QPushButton;
    aitken->setParent(this);
    aitken->setText("埃特肯法");
    aitken->move(70,30);
}

void IteratorWidget::paintEvent(QPaintEvent *event)
{  
    Q_UNUSED(event);

    QPainter my_paint(this);
    my_paint.setPen(QColor(0,0,255));           //画笔是用来画轮廓的
    my_paint.setBrush(Qt::blue);                     //画刷是用来填充轮廓的
    my_paint.setRenderHint(QPainter::Antialiasing);             //反走样
    my_paint.drawEllipse(QPoint(200,200),100,100);
    
    my_paint.translate(205,0);                          //这相当于把画笔移动到(405,200)这里做画。
    my_paint.setPen(QColor(0,255,0));           //画笔是用来画轮廓的
    my_paint.setBrush(Qt::green);                   //画刷是用来填充轮廓的
    my_paint.drawEllipse(QPoint(200,200),100,100);

    //绘制COS函数图像
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
