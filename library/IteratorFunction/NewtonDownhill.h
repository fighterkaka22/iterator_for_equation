/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-09 04:09:52
 * @LastEditTime: 2020-11-13 01:00:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorFunction/NewtonDownhill.h
 */
#ifndef __NEWTONDOWNHILL_H__
#define __NEWTONDOWNHILL_H__
#include "IteratorFunction.h"
//@brief:迭代函数类，内涵读取并计算表达式函数，可以计算函数值，子类为五种迭代法
//@brief:可以通过void initNewtonDownhill()成员函数实现初始化成员变量
//@brief:可以通过NumberType iterate()成员函数实现单步迭代
//@example:
//    NewtonDownhill a;
//    a.initNewtonDownhill(expression,equivalent,x0,x1);
//    a.iterate();
class NewtonDownhill : public IteratorFunction
{
	public:		
		double lambda = 1;	
	protected:
		NumberType dfx;
		NumberType fx;
		NumberType xx;
		NumberType fxx;

	public:
		NewtonDownhill();
		//init
		void initNewtonDownhill(string expression, string equivalent, NumberType x0, NumberType x1);
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
