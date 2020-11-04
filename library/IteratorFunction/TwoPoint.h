#ifndef __TWOPOINT_H__
#define __TWOPOINT_H__
#include "IteratorFunction.h"
class TwoPoint : public IteratorFunction
{
	public:	
		NumberType xn_1;
		NumberType xn;		
	protected:
		NumberType fxn_1;
		NumberType fxn; 
	public:
		TwoPoint(string expression, string equivalent, NumberType x0, NumberType x1);
		NumberType iterate();
	protected:
};

#endif
