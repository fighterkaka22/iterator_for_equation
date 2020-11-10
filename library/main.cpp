/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 01:56:30
 * @LastEditTime: 2020-11-09 05:59:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/main.cpp
 */
#include <QApplication>

#include "IteratorWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IteratorWidget w;
    w.show();

    return a.exec();
}

