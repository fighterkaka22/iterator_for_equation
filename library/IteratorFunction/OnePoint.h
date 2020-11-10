#ifndef __ONEPOINT_H__
#define __ONEPOINT_H__
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
		OnePoint();
		void initOnePoint(string expression, string equivalent, NumberType x0, NumberType x1);
		NumberType iterate();
	protected:
};

#endif
