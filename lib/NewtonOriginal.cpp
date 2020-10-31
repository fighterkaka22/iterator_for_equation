#include "NewtonOriginal.h"
NewtonOriginal::NewtonOriginal(string expression, string equivalent, NumberType x0, NumberType x1):IteratorFunction(expression, equivalent, x0, x1)
{ 
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
NumberType NewtonOriginal::iterate()
{
	this -> x1 = this -> x;
	
	this->x = this->x - this->fx/this->dfx ;
	this->fx = this->cal();
	this->xx = this->x + 0.00000001; 
	
	NumberType x_temp = this->x;
	this->x = this->xx;	
	this->fxx = this->cal();
	this->x = x_temp;
	
	this->dfx = (this->fxx - this->fx)/0.00000001;
	
	cout << "x_new=" << this->x << endl;
}
