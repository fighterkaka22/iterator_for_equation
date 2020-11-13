/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-09 04:09:52
 * @LastEditTime: 2020-11-13 00:08:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorFunction/TwoPoint.cpp
 */
#include "TwoPoint.h"
TwoPoint::TwoPoint():IteratorFunction()
{

}
void TwoPoint::initTwoPoint(string expression, string equivalent, NumberType x0, NumberType x1)
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
	
	this->xn_1 = x0;
	this->x = x0;
	this->fxn_1 = this->cal();
	this->xn = x1;
	this->x = x1;
	this->fxn = this->cal();
}
NumberType TwoPoint::iterate()
{
	NumberType xn_last = this->xn;
	this->xn = (xn_1*fxn - xn*fxn_1)/(fxn - fxn_1);
	cout << "x_new = " << this->xn << endl;
	this->xn_1 = xn_last;
	this->fxn_1 = this->fxn;
	this->x = this->xn;
	this->fxn = this->cal();
	return this->xn;
}
