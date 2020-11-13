/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-09 04:09:52
 * @LastEditTime: 2020-11-13 01:01:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorFunction/TwoPoint.h
 */
#ifndef __TWOPOINT_H__
#define __TWOPOINT_H__
#include "IteratorFunction.h"
//@brief:迭代函数类，内涵读取并计算表达式函数，可以计算函数值，子类为五种迭代法
//@brief:可以通过void initTwoPoint()成员函数实现初始化成员变量
//@brief:可以通过NumberType iterate()成员函数实现单步迭代
//@example:
//    TwoPoint a;
//    a.initTwoPoint(expression,equivalent,x0,x1);
//    a.iterate();
class TwoPoint : public IteratorFunction
{
	public:	
		NumberType xn_1;
		NumberType xn;		
	protected:
		NumberType fxn_1;
		NumberType fxn; 
	public:
		TwoPoint();
		//init
		void initTwoPoint(string expression, string equivalent, NumberType x0, NumberType x1);
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
