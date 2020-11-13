/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-04 01:56:30
 * @LastEditTime: 2020-11-13 00:58:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/lib/IteratorFunction.h
 */
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
typedef double NumberType;
//@brief:迭代函数类，内涵读取并计算表达式函数，可以计算函数值，子类为五种迭代法
//@brief:可以通过NumberType cal()成员函数实现函数值计算
//@example:
//    IteratorFunction i;
//    i.cal();
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
    NumberType x0;
    NumberType x1;
	NumberType x;
protected:
	/*
		入栈规则：
		1.左括号直接入栈
		2.右括号入栈前，逐次弹出所有操作符并进行运算直到左括号
		3.五层优先级((),(-,+),(*,/),(^)(#)
	*/
	NumberType sTOi(NumberType first_index, NumberType last_index); //transport expression to number
	void pushExpression();
	void pushOpt(int index); //push the operation at index into OPTR and calculate value if necessary
	void compute(char opt); //comput 'a opt b'
	void Error(); //do when error occurs
public:
	IteratorFunction(string expression, string equivalent, NumberType x0, NumberType x1,NumberType x);
	//overload
	IteratorFunction();
	/*
     * @Author: Sun Yuxin
     * @Description: 读取表达式并得出结果
     * @Return: NumberType:计算结果
     * @Throw: 
     */
	NumberType cal(); //calculate the final value and print it.
};

#endif
