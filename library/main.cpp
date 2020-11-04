/*
 * @Author: your name
 * @Date: 2020-11-04 01:56:30
 * @LastEditTime: 2020-11-04 03:58:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /numerical_analysis_iterator/library/main.cpp
 */
#include <iostream>

#include "IteratorFunction.h"
#include "IteratorText.h"
#include "IteratorWidget.h"
#include "IteratorPaint.h"
#include "Aitken.h"
#include "NewtonOriginal.h"
#include "NewtonDownhill.h"
#include "OnePoint.h"
#include "TwoPoint.h"
using namespace std;
int main()
{
    string expression;
    string equivalent;
    double x0;
    double x1;
    int method;
    //method:1-Aitken,2-NewtonOriginal,3-NewtonDownhill,4-OnePoint,5-TwoPoint
    cin >> method;
    cin >> expression;
    cin >> equivalent;
    cin >> x0;
    cin >> x1;
    for(double x = x0 - 1.0; x <= x0 + 1.0; x += 0.01)
    {
        IteratorFunction iterator_function(expression, equivalent, x0, x1, x);
        iterator_function.cal();     
    }
    
    if(method == 1)
    {
    	Aitken aitken(expression, equivalent, x0, x1); 
    	while( fabs(aitken.x - aitken.x1) > YPSILON) 
    	{
			aitken.iterate();    		
		}
   		cout << "The result is " << aitken.x << endl;
	} 
    else if(method == 2)
    {
    	NewtonOriginal newton_original(expression, equivalent, x0, x1);
		while( fabs(newton_original.x - newton_original.x1) > YPSILON) 
    	{
			newton_original.iterate();    		
		}
   		cout << "The result is " << newton_original.x << endl;    	
	}
	else if(method == 3)
	{
		NewtonDownhill newton_downhill(expression, equivalent, x0, x1);	
		while( fabs(newton_downhill.x - newton_downhill.x1) > YPSILON) 
    	{
			newton_downhill.iterate();    		
		}
   		cout << "The result is " << newton_downhill.x << endl;	
	}
	else if(method == 4)
	{
    	OnePoint one_point(expression, equivalent, x0, x1);	
		while( fabs(one_point.xn - one_point.x_last) > YPSILON) 
    	{
			one_point.iterate();    		
		}
   		cout << "The result is " << one_point.x << endl;	
	} 
	else if(method == 5)
	{
		TwoPoint two_point(expression, equivalent, x0, x1);	
		while( fabs(two_point.xn - two_point.xn_1) > YPSILON) 
    	{
			two_point.iterate();    		
		}
   		cout << "The result is " << two_point.x << endl;	
	}

	return 0;
}
