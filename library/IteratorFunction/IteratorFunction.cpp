#ifndef __ITERATOR_FUNCTION__
#include"IteratorFunction.h"
using namespace std;
IteratorFunction::IteratorFunction(string expression, string equivalent, NumberType x0, NumberType x1 , NumberType x)
{
	this->expression = expression;
	this->equivalent = equivalent;
    this->x0 = x0;
    this->x1 = x1;
	this->x = x;
	
	while(!OPTR.empty())OPTR.pop();
	while(!OPND.empty())OPND.pop();
	
	error = 0;
	opt_priority['('] = 0;
	opt_priority['-'] = 1;
	opt_priority['+'] = 1;
	opt_priority['*'] = 2;
	opt_priority['/'] = 2;
	opt_priority['^'] = 3;
	opt_priority['#'] = 4;
}
// IteratorFunction::IteratorFunction(string expression, string equivalent, NumberType x0, NumberType x1)
// {
// 	this->expression = expression;
// 	this->equivalent = equivalent;
//     this->x0 = x0;
//     this->x1 = x1;
	
// 	error = 0;
// 	opt_priority['('] = 0;
// 	opt_priority['-'] = 1;
// 	opt_priority['+'] = 1;
// 	opt_priority['*'] = 2;
// 	opt_priority['/'] = 2;
// 	opt_priority['^'] = 3;
// 	opt_priority['#'] = 4;
// }
IteratorFunction::IteratorFunction()
{

}
NumberType IteratorFunction::sTOi(NumberType first_index, NumberType last_index)
{
	string tmp = expression.substr(first_index, last_index - first_index);
	NumberType num_tmp = 0;
	for (int i = 0; i < (int)tmp.size(); i++)
	{
		num_tmp *= 10;
		num_tmp += tmp[i] - '0';
	}
	return num_tmp;
}

void IteratorFunction::compute(char opt)
{
	if (OPND.empty()) //not enough number
	{
		if (!error)
			error = 2;
		return;
	}
	if (opt == '#')
	{
		NumberType b = OPND.top();
		OPND.pop();
		OPND.push(-b);
		return;
	}

	NumberType b = OPND.top();
	OPND.pop();
	if (OPND.empty()) //not enough number
	{
		if (!error)
			error = 2;
		return;
	}
	NumberType a = OPND.top();
	OPND.pop();
	NumberType c = 0;
	double ad = a, bd = b;
	switch (opt)
	{
	case '-':
		c = a - b;
		break;
	case '+':
		c = a + b;
		break;
	case '*':
		c = a * b;
		break;
	case '/':
		if (b < 0.00000000001)
		{
			if (!error)
				error = 1; //divided by 0
		}
		else
			c = a / b;
		break;
	case '^':
		if (b < 0)
		{
			if (!error)
				error = 2;
		}
		c = pow(ad, bd);
		break;
	default:
		if (!error)
			error = 2;
		break;
	}
	OPND.push(c);
	return;
}

void IteratorFunction::Error()
{
	if (error == 1)
	{
		cout << "Divide 0.\n";
	}
	else
	{
		cout << "error.\n";
	}
	return;
}

void IteratorFunction::pushOpt(int index)
{
	char opt = expression[index];
	if (opt == '(' || opt == '#')
	{
		OPTR.push(opt);
		return;
	}
	else
	{
		if (opt == ')')
		{
			int flag = 1; //mark expression is wrong for there is no '('
			while (!OPTR.empty())
			{
				char opt_tmp = OPTR.top();
				OPTR.pop();
				if (opt_tmp == '(')
				{
					flag = 0;
					break;
				}
				compute(opt_tmp);
				if (error)
					return;
			}
			if (flag) //there is no '('
			{
				if (!error)
					error = 2;
				return;
			}
		}
		else
		{
			if (index)
			{
				if (expression[index - 1] == '(')
				{
					error = 2;
					return;
				}
			}
			while (!OPTR.empty())
			{
				char opt_tmp = OPTR.top();
				OPTR.pop();
				if (opt_priority[opt] >= opt_priority[opt_tmp])
				{
					//��һ���ǿ��ǵ�ָ����������������ڽ���ͬ������ʱ�Ĳ�֮ͬ��
					//��������ͬ�����������
					//ָ�������Ǵ��ϵ��£�Ҳ���Ǳ���ʽ�еĴ�������
					if (opt == '^')
					{
						OPTR.push(opt_tmp);
						break;
					}
					else
					{
						if (opt_priority[opt] > opt_priority[opt_tmp])
						{
							OPTR.push(opt_tmp);
							break;
						}
					}
				}
				compute(opt_tmp);
				if (error)
				{
					return;
				}
			}
			OPTR.push(opt);
		}
	}
	return;
}
void IteratorFunction::pushExpression()
{
	for (int i = 0; i < (int)expression.size(); ++i)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			int j = i;
			for (; expression[j] >= '0' && expression[j] <= '9'; j++)
				;
			OPND.push(sTOi(i, j));
			i = j - 1;
		}
		else if(expression[i] == 'x')
		{
			OPND.push(this->x);
		}
		else if(expression[i] == 'e')
		{
			OPND.push(2.7182818);
		}
		else
		{
			pushOpt(i);
		}
		if (error)
			return;
	}
	return;
}
NumberType IteratorFunction::cal()
{
	pushExpression();
	while (!OPTR.empty())
	{
		if (error)
			break;
		char opt_tmp = OPTR.top();
		OPTR.pop();
		if (opt_tmp == '(')
		{
			if (!error)
				error = 2;
		}
		compute(opt_tmp);
	}
	if (OPND.size() < 1)//error
	{
		if (!error)
			error = 2;
	}

	if (error)
	{
		Error();
		return -1;
	}
	//cout << "cal=" << OPND.top() << endl;
	return OPND.top();
}

#endif
