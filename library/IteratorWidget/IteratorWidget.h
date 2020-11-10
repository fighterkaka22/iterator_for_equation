/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 02:00:32
 * @LastEditTime: 2020-11-09 06:44:07
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

public:
    IteratorWidget(QWidget *parent = 0);
    ~IteratorWidget();

    void paintEvent(QPaintEvent *event);
private:
};

#endif // WIDGET_H