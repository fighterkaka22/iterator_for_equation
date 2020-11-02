#ifndef __ITERATOR_FUNCTION__
#define __ITERATOR_FUNCTION__
#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <math.h>
#include <map>
#include <stdlib.h> 
using namespace std;

#define YPSILON 0.000001 
typedef double NumberType;

class  IteratorFunction
{
protected:
	map<char, NumberType> opt_priority;
	stack<NumberType> OPND;
	stack<char> OPTR;
	int error; //error == 1, divided by 0; error == 2, expression is wrong
public:
	string expression;
    string equivalent;
    double x0;
    double x1;
	double x;
protected:
	NumberType sTOi(NumberType first_index, NumberType last_index); //transport expression to number
	void pushExpression();
	void pushOpt(int index); //push the operation at index into OPTR and calculate value if necessary
	void compute(char opt); //comput 'a opt b'
	void Error(); //do when error occurs
public:
	IteratorFunction(string expression, string equivalent, NumberType x0, NumberType x1,NumberType x);
	//overload
	IteratorFunction(string expression, string equivalent, NumberType x0, NumberType x1);
	NumberType cal(); //calculate the final value and print it.
};

#endif
