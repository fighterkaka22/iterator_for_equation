/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 02:00:32
 * @LastEditTime: 2020-11-10 12:07:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorWidget.h
 */
#ifndef ITERATOR_WIDGET_H
#define ITERATOR_WIDGET_H

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
class IteratorWidget : public QWidget
{
    Q_OBJECT
//变量
public:
    QPushButton _aitken;
    QPushButton _newton_original;
    QPushButton _newton_downhill;
    QPushButton _one_point;
    QPushButton _two_point;

    QPushButton _start;
    QPushButton _next;
    QPushButton _exit;

    QLineEdit _edit_fx;
    QLineEdit _edit_gx;
    QLineEdit _edit_x0;
    QLineEdit _edit_x1;

    int method = 0;
    double x0 = 0;
    double x1 = 0;
    string expression;
    string equivalent;
protected:
    queue<NumberType> point_queue;
    int time = 0;
    NumberType result_array[100]={0};

    Aitken aitken;
    NewtonOriginal newton_original;
    NewtonDownhill newton_downhill;
    OnePoint one_point;
    TwoPoint two_point;
private:
    QImage image;
    QString line;
    int drawline_flag=0;
    int drawpoint_flag=0;
    int flag=0;
    NumberType result;
//函数
public:
    IteratorWidget(QWidget *parent = 0);
    ~IteratorWidget();

    void paintEvent(QPaintEvent *event);
protected:
private:


};

#endif // WIDGET_H