/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-09 04:09:52
 * @LastEditTime: 2020-11-11 05:40:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorFunction/NewtonDownhill.h
 */
#ifndef __NEWTONDOWNHILL_H__
#define __NEWTONDOWNHILL_H__
#include "IteratorFunction.h"
class NewtonDownhill : public IteratorFunction
{
	public:		
		double lamda = 1;	
	protected:
		NumberType dfx;
		NumberType fx;
		NumberType xx;
		NumberType fxx;

	public:
		NewtonDownhill();
		void initNewtonDownhill(string expression, string equivalent, NumberType x0, NumberType x1);
		NumberType iterate(); 
	protected:
};

#endif
