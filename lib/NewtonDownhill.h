#ifndef NEWTONDOWNHILL_H
#define NEWTONDOWNHILL_H
#include "IteratorFunction.h"
class NewtonDownhill : public IteratorFunction
{
	public:		
	protected:
		NumberType dfx;
		NumberType fx;
		NumberType xx;
		NumberType fxx;
		NumberType lamda;
	public:
		NewtonDownhill(string expression, string equivalent, NumberType x0, NumberType x1);
		NumberType iterate(); 
	protected:
};

#endif
