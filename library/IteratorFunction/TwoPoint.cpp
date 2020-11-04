#include "TwoPoint.h"
TwoPoint::TwoPoint(string expression, string equivalent, NumberType x0, NumberType x1):IteratorFunction(expression, equivalent, x0, x1)
{  
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
	cout << "x_new=" << this->xn << endl;
	this->xn_1 = xn_last;
	this->fxn_1 = this->fxn;
	this->x = this->xn;
	this->fxn = this->cal();
}
