#include "OnePoint.h"
OnePoint::OnePoint(string expression, string equivalent, NumberType x0, NumberType x1):IteratorFunction(expression, equivalent, x0, x1)
{
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
	cout << "x_new=" << this->xn << endl;
	this->x = this->xn;
	this->fxn = this->cal();
}
