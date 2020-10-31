#ifndef NEWTONORIGINAL_H
#define NEWTONORIGINAL_H
#include "IteratorFunction.h"
class NewtonOriginal : public IteratorFunction
{
	public:
	protected:
		NumberType dfx;
		NumberType fx;
		NumberType xx;
		NumberType fxx;
	public:
		NewtonOriginal(string expression, string equivalent, NumberType x0, NumberType x1);
		NumberType iterate();
	protected:
};

#endif
