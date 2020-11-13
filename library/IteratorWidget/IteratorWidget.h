/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 02:00:32
 * @LastEditTime: 2020-11-13 00:37:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorWidget.h
 */
#ifndef __ITERATOR_WIDGET_H__
#define __ITERATOR_WIDGET_H__

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QString>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QMessageBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QDebug>
#include <queue>

#include "IteratorFunction.h"
#include "Aitken.h"
#include "NewtonOriginal.h"
#include "NewtonDownhill.h"
#include "OnePoint.h"
#include "TwoPoint.h"

//@brief:Qt窗口类，可以通过构造函数将窗口类中的按钮、文本框等设置为子对象，并通过信号和槽机制与底层函数连接，为子对象实现对应的功能，利用循环机制实时更新窗口内容
//@brief:可以通过void paintEvent(QPaintEvent * event)成员函数实现函数图像、迭代点、文本的绘制
//@example:
//    IteratorWidget w;
//    w.show();
//    return a.exec();
class IteratorWidget : public QWidget
{
    Q_OBJECT
//变量
public:
    //按钮
    QPushButton _aitken;
    QPushButton _newton_original;
    QPushButton _newton_downhill;
    QPushButton _one_point;
    QPushButton _two_point;

    QPushButton _start;
    QPushButton _next;
    QPushButton _exit;

    QPushButton _ypsilon_00001;
    QPushButton _ypsilon_000001;
    QPushButton _ypsilon_0000001;
    QPushButton _ypsilon_00000001;

    QPushButton _multiple_001;
    QPushButton _multiple_01;
    QPushButton _multiple_1;
    QPushButton _multiple_10;

    //文本框
    QTextEdit _edit_fx;
    QTextEdit _edit_gx;
    QTextEdit _edit_x0;
    QTextEdit _edit_x1;

    QTextEdit _edit_time;
    QTextEdit _edit_result;
    QTextEdit _edit_lambda;
private:
    int method = 0;
    int time = 0;
    int drawline_flag=0;
    int drawpoint_flag=0;
    int flag = 0;

    double x0 = 0;
    double x1 = 0;
    double ypsilon = 0.00001;
    double ypsilon_num = 5;
    double multiple = 0.1;

    string expression;
    string equivalent;

    NumberType result;
    NumberType result_array[100]={0};    
    queue<NumberType> point_queue;

    Aitken aitken;
    NewtonOriginal newton_original;
    NewtonDownhill newton_downhill;
    OnePoint one_point;
    TwoPoint two_point;    
    
//函数
public:
    IteratorWidget(QWidget *parent = 0);
    ~IteratorWidget();
private:
    /*
     * @Author: Sun Yuxin
     * @Description: 绘制窗口背景框架，绘制函数图像，绘制文字，不允许外部调用
     * @Param: QPaintEvent * event：进入函数即Q_UNUSED
     * @Return: void
     * @Throw: 
     */
    void paintEvent(QPaintEvent *event);
};

#endif // __ITERATOR_WIDGET_H__