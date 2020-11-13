/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-11 06:41:05
 * @LastEditTime: 2020-11-13 00:59:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorFunction/Aitken.h
 */
#ifndef __AITKEN_H__
#define __AITKEN_H__
#include "IteratorFunction.h"
//@brief:迭代函数类，内涵读取并计算表达式函数，可以计算函数值，子类为五种迭代法
//@brief:可以通过void initAitken()成员函数实现初始化成员变量
//@brief:可以通过NumberType iterate()成员函数实现单步迭代
//@example:
//    Aitken a;
//    a.initAitken(expression,equivalent,x0,x1);
//    a.iterate();
class Aitken : public IteratorFunction
{
	public:
	protected:
		NumberType y;
		NumberType z;
	public:
		Aitken();
		//init
		void initAitken(string expression, string equivalent, NumberType x0, NumberType x1);
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
