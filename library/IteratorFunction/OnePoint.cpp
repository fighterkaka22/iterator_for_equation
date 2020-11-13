/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-11 06:41:05
 * @LastEditTime: 2020-11-13 00:03:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorFunction/OnePoint.cpp
 */
#include "OnePoint.h"
OnePoint::OnePoint():IteratorFunction()
{

}
void OnePoint::initOnePoint(string expression, string equivalent, NumberType x0, NumberType x1)
{
	this->expression = expression;
	this->equivalent = equivalent;
    this->x0 = x0;
    this->x1 = x1;
	
	error = 0;
	opt_priority['('] = 0;
	opt_priority['-'] = 1;
	opt_priority['+'] = 1;
	opt_priority['*'] = 2;
	opt_priority['/'] = 2;
	opt_priority['^'] = 3;
	opt_priority['#'] = 4;
	
	this->x0 = x0;
	this->x_last = x0;
	this->x = x0;
	this->fx0 = this->cal();
	this->xn = x1;
	this->x = x1;
	this->fxn = this->cal();
}
NumberType OnePoint::iterate()
{
	this->x_last = this->xn;
	this->xn = (x0*fxn - xn*fx0)/(fxn - fx0);
	cout << "x_new = " << this->xn << endl;
	this->x = this->xn;
	this->fxn = this->cal();
	return this->xn;
}
