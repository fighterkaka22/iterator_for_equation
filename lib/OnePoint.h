#ifndef ONEPOINT_H
#define ONEPOINT_H
#include "IteratorFunction.h"
class OnePoint : public IteratorFunction
{
	public:
		NumberType x_last;
		NumberType xn;		
	protected:
		NumberType fx0;
		NumberType fxn; 
	public:
		OnePoint(string expression, string equivalent, NumberType x0, NumberType x1);
		NumberType iterate();
	protected:
};

#endif
