#include "NewtonDownhill.h"
NewtonDownhill::NewtonDownhill(string expression, string equivalent, NumberType x0, NumberType x1):IteratorFunction(expression, equivalent, x0, x1)
{  
	this->lamda = 1;
	
	this->x1 = this->x0-1;
	
	this->x = this->x0;
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
