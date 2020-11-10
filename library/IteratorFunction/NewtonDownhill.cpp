#include "NewtonDownhill.h"
NewtonDownhill::NewtonDownhill():IteratorFunction()
{

}
void NewtonDownhill::initNewtonDownhill(string expression, string equivalent, NumberType x0, NumberType x1)
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
	this->lamda = 1;
	
	this->x1 = x0-1;
	
	this->x = x0;
	this->fx = this->cal();
	this->xx = this->x + 0.00000001; 
	
	NumberType x_temp = this->x;
	this->x = this->xx;	
	this->fxx = this->cal();
	this->x = x_temp;
	
	this->dfx = (this->fxx - this->fx)/0.00000001;
}
NumberType NewtonDownhill::iterate()
{
	this->lamda = 1;
	this -> x1 = this -> x;
	NumberType fx_temp = this->fx;
	NumberType x_temp = this->x;
	
	for( ; fabs(fx_temp) <= fabs(this->fx); this->lamda /= 2)
	{
		this->x = x_temp - this->lamda*fx_temp/this->dfx ;
		this->fx = this->cal();		
	}
	cout << "lamda=" << this->lamda << endl;

	this->xx = this->x + 0.00000001;
	x_temp = this->x;
	this->x = this->xx;	
	this->fxx = this->cal();
	this->x = x_temp;
	
	this->dfx = (this->fxx - this->fx)/0.00000001;
	
	cout << "x_new=" << this->x << endl;
}
