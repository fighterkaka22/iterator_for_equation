#ifndef ONEPOINT_H
#define ONEPOINT_H
#include "IteratorFunction.h"
class OnePoint : public IteratorFunction
{
	public:
		OnePoint(string expression, string equivalent, NumberType x0, NumberType x1);
	protected:
};

#endif
