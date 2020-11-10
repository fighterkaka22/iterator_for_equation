#ifndef __AITKEN_H__
#define __AITKEN_H__
#include "IteratorFunction.h"
class Aitken : public IteratorFunction
{
	public:
	protected:
		NumberType y;
		NumberType z;
	public:
		Aitken();
		void initAitken(string expression, string equivalent, NumberType x0, NumberType x1);
		NumberType iterate();		
	protected:
};

#endif
