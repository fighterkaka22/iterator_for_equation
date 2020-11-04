/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 02:00:39
 * @LastEditTime: 2020-11-04 03:31:47
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

    QPushButton *newtonOriginal = new QPushButton;
    newtonOriginal->setParent(this);
    newtonOriginal->setText("牛顿法");
    newtonOriginal->move(70,230);
    
    this->hanhan=new Paint(this);
    connect(aitken,&QPushButton::clicked,hanhan,&Paint::paintEvent);
}



IteratorWidget::~IteratorWidget()
{

}
