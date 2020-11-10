/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 02:00:32
 * @LastEditTime: 2020-11-10 04:15:14
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

    QTextEdit _edit_fx;
    QTextEdit _edit_gx;
    QTextEdit _edit_x0;
    QTextEdit _edit_x1;
protected:
private:
    QImage image;
    QString line;
//函数
public:
    IteratorWidget(QWidget *parent = 0);
    ~IteratorWidget();

    void paintEvent(QPaintEvent *event);
protected:
private:
};

#endif // WIDGET_H