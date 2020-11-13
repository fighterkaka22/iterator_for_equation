/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-09 04:09:52
 * @LastEditTime: 2020-11-13 00:06:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorFunction/OnePoint.h
 */
#ifndef __ONEPOINT_H__
#define __ONEPOINT_H__
#include "IteratorFunction.h"
//@brief:迭代函数类，内涵读取并计算表达式函数，可以计算函数值，子类为五种迭代法
//@brief:可以通过void initOnePoint()成员函数实现初始化成员变量
//@brief:可以通过NumberType iterate()成员函数实现单步迭代
//@example:
//    OnePoint a;
//    a.initOnePoint(expression,equivalent,x0,x1);
//    a.iterate();
class OnePoint : public IteratorFunction
{
	public:
		NumberType x_last;
		NumberType xn;		
	protected:
		NumberType fx0;
		NumberType fxn; 
	public:
		OnePoint();
		//init
		void initOnePoint(string expression, string equivalent, NumberType x0, NumberType x1);
		/*
		 * @Author: Sun Yuxin
		 * @Description: 利用类成员变量进行单步迭代
		 * @Return: NumberType:迭代结果
		 * @Throw: 
		*/
		NumberType iterate();
	protected:
};

#endif
