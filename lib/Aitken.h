#ifndef AITKEN_H
#define AITKEN_H
#include "IteratorFunction.h"
class Aitken : public IteratorFunction
{
	public:
	protected:
		NumberType y;
		NumberType z;
	public:
		Aitken(string expression, string equivalent, NumberType x0, NumberType x1);
		NumberType iterate();		
	protected:
};

#endif
