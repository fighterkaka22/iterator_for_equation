#ifndef __NEWTONDOWNHILL_H__
#define __NEWTONDOWNHILL_H__
#include "IteratorFunction.h"
class NewtonDownhill : public IteratorFunction
{
	public:		
	protected:
		NumberType dfx;
		NumberType fx;
		NumberType xx;
		NumberType fxx;
		double lamda;
	public:
		NewtonDownhill();
		void initNewtonDownhill(string expression, string equivalent, NumberType x0, NumberType x1);
		NumberType iterate(); 
	protected:
};

#endif
