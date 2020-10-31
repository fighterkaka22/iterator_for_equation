#include "Aitken.h"
Aitken::Aitken(string expression, string equivalent, NumberType x0, NumberType x1):IteratorFunction(expression, equivalent, x0, x1)
{  
	this->x = this->x0;
	this->x1 = this->x0-1; 
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
