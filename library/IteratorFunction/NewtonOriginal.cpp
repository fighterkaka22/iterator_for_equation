/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-09 04:09:52
 * @LastEditTime: 2020-11-13 00:03:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorFunction/NewtonOriginal.cpp
 */
#include "NewtonOriginal.h"
NewtonOriginal::NewtonOriginal():IteratorFunction()
{
	
}
void NewtonOriginal::initNewtonOriginal(string expression, string equivalent, NumberType x0, NumberType x1)
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
	this->x1 = x0 - 1;
	
	this->x = x0;
	this->fx = this->cal();
	this->xx = this->x + 0.0000000000001; 
	
	NumberType x_temp = this->x;
	this->x = this->xx;	
	this->fxx = this->cal();
	this->x = x_temp;
	
	this->dfx = (this->fxx - this->fx)/0.0000000000001;
}
NumberType NewtonOriginal::iterate()
{
	this -> x1 = this -> x;
	
	this->x = this->x - this->fx/this->dfx ;
	this->fx = this->cal();
	this->xx = this->x + 0.0000000000001; 
	
	NumberType x_temp = this->x;
	this->x = this->xx;	
	this->fxx = this->cal();
	this->x = x_temp;
	
	this->dfx = (this->fxx - this->fx)/0.0000000000001;
	
	cout << "x_new = " << this->x << endl;
	return this->x;
}
