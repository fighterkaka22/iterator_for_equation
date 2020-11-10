/*
 * @Author: Sun Yuxin
 * @Date: 2020-11-09 04:09:52
 * @LastEditTime: 2020-11-10 08:07:25
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/IteratorFunction/TwoPoint.h
 */
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
		TwoPoint();
		void initTwoPoint(string expression, string equivalent, NumberType x0, NumberType x1);
		NumberType iterate();
	protected:
};

#endif
