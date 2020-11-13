/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-09 04:09:52
 * @LastEditTime: 2020-11-13 00:09:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorFunction/Aitken.cpp
 */
#include "Aitken.h"
Aitken::Aitken():IteratorFunction()
{

}
void Aitken::initAitken(string expression, string equivalent, NumberType x0, NumberType x1)
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
	
	this->x = x0;
	this->x1 = x0-1;
}
NumberType Aitken::iterate()
{
	this -> x1 = this -> x;
	NumberType x_temp = this -> x;
	
	string expression_temp = this -> expression;
	this -> expression = this -> equivalent;
	
	this -> x = this -> y = this -> cal();
	this -> z = this -> cal();
	this -> x = x_temp; 
	
	this -> expression = expression_temp;
	
	cout << "x=" << this -> x << endl;
	cout << "y=" << this -> y << endl;
	cout << "z=" << this -> z << endl;
	this -> x = ( x*z - y*y ) / ( x-2*y+z );
	cout << "x_new=" << this -> x << endl;
	return this -> x;
}
