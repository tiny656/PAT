#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
/*
前缀表达式求值，通过符号栈和数字栈，从右往左进行运算。 
1.数字入栈
2.符号入栈
3.IF 数字栈 >= 2 && 符号栈 >= 1
	弹出数字A,B 符号op
	进行运算 C = A op B 
	把C压入数字栈
   	直到数字栈 大小 为  1
4.注意出错情况的判断 
*/
stack<char> 	opStack;
stack<double> 	valStack;

double Convert(string str)
{
	int i,j;
	double val;
	char valChar[50];
	for(i = str.size()-1,j = 0; i >= 0; i--, j++)
		valChar[j] = str[i];
	sscanf(valChar, "%lf", &val);
	return val;
} 

void Work(string str)
{
	int i,Error = 0;
	string tmp = "";
	for(i = str.size()-1; i >= 0; i--)
	{
		if(str[i] == ' ')
		{
			if(tmp == "+")		opStack.push('+');
			else if(tmp == "-")	opStack.push('-');	
			else if(tmp == "*")	opStack.push('*');
			else if(tmp == "/")	opStack.push('/');
			else				valStack.push(Convert(tmp));	
			tmp = "";
			while(valStack.size() >= 2 && opStack.size() >= 1)
			{//进行运算 
				double a = valStack.top(); valStack.pop();
				double b = valStack.top(); valStack.pop();
				char op  = opStack.top();  opStack.pop();
				if(op == '+')	 	valStack.push(a+b);
				else if(op == '-') 	valStack.push(a-b);
				else if(op == '*') 	valStack.push(a*b);
				else if(op == '/')
				{
					if(b==0) 
					{
						Error = 1;
						break;
					}
					else valStack.push(a/b);
				} 	
			}
		}	
		else
		{
			tmp += str[i];
		}
	}
	
	if(Error == 1)
	{
		puts("ERROR"); return;
	}
	
	if(tmp == "+")		opStack.push('+');
	else if(tmp == "-")	opStack.push('-');	
	else if(tmp == "*")	opStack.push('*');
	else if(tmp == "/")	opStack.push('/');
	else				valStack.push(Convert(tmp));	
	tmp = "";
	while(valStack.size() >= 2 && opStack.size() >= 1)
	{//进行运算 
		double a = valStack.top(); valStack.pop();
		double b = valStack.top(); valStack.pop();
		char op  = opStack.top();  opStack.pop();
		if(op == '+')	 	valStack.push(a+b);
		else if(op == '-') 	valStack.push(a-b);
		else if(op == '*') 	valStack.push(a*b);
		else if(op == '/')
		{
			if(b==0) 
			{
				Error = 1;
				break;
			}
			else valStack.push(a/b);
		}
	}
	
	if(Error == 1)
	{
		puts("ERROR"); return;
	}
	
	if(opStack.size() == 0 && valStack.size() == 1)
	{
		printf("%.1lf\n", valStack.top());
	}
	else
	{
		puts("ERROR");
	}
}

int main()
{
	string str;
	getline(cin, str);
	Work(str);
	system("pause");
	return 0;
} 