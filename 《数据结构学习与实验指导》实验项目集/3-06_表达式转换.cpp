#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

/*
中缀转后缀表达式
算法思路:
中缀表达式a + b*c + (d * e + f) * g，其转换成后缀表达式则为a b c * + d e * f  + g * +。
转换过程需要用到栈，具体过程如下：
1）如果遇到操作数，我们就直接将其输出。
2）如果遇到操作符，则我们将其放入到栈中，遇到左括号时我们也将其放入栈中。
3）如果遇到一个右括号，则将栈元素弹出，将弹出的操作符输出直到遇到左括号为止。注意，左括号只弹出并不输出。
4）如果遇到任何其他的操作符，如 + ，- , * ，\ , ( 等，
从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止。
弹出完这些元素后，才将遇到的操作符压入到栈中。
有一点需要注意，只有在遇到 ) 的情况下我们才弹出 ( ，其他情况我们都不会弹出 ( 。
也就是说这种操作， + -的优先级最低, ( 优先级最高。
5）如果我们读到了输入的末尾，则将栈中所有元素依次弹出。

注意事项 
1. 注意格式末尾没有 空格，用firstPrint来控制 
2. 注意-2+(+3)+(-2)这一类的输入 
2. 优先级关系
3. 数字和符号输入的方法
4. 用 = 来当栈底进行保护 
*/


//优先级判断 
int OperPrior(char op)
{
	int key;
	switch(op)
	{
		case '=':
			return 0;
		case '+':
		case '-': 
			return 1; 
		case '*': 
		case '/': 
			return 2; 
		case '(':
		case ')': 
			return 3;
	}
}

void Run() 
{	
	stack<char> optr;			//操作符栈
	optr.push('=');				//压入'='作为保护
	char ch;
	double operand;
	int First = 1;
	int LastType;
	int firstPrint = 1;
	ch = getchar();
	while(ch != '\n') 
	{//当前表达式还未运算结束，继续运算
		if( (ch <= '9' && ch >= '0') || 
			( (ch == '+' || ch == '-') && 
			  ( First || (optr.top() == '(' && LastType == 1) ) ))
		{//ch为第一个操作数的第一个字符
			cin.putback(ch);			//将字符ch放回输入流
			cin >> operand;				//读入操作数
			if(firstPrint)	
			{
				firstPrint = 0;
				cout << operand;
			}
			else	cout << " " << operand;
			First = 0;
			LastType = 0;
			ch = getchar();				//读入下一个字符
		}
		else 
		{//ch为操作符
			LastType = 1;
			if ( ch == ')' )
			{
				while (optr.top() != '(')
				{
					if(firstPrint)	
					{
						firstPrint = 0;
						cout << optr.top();
					}
					else cout << " " << optr.top();
					optr.pop();
				}
				optr.pop();
			}
			else if ( OperPrior(optr.top()) < OperPrior(ch) )
			{
				optr.push(ch);					//ch入optr栈
			}
			else if ( OperPrior(optr.top()) >= OperPrior(ch) )
			{//opreTop大于或等于ch的优先级
				while(optr.top() != '(' && OperPrior(optr.top()) >= OperPrior(ch))
				{
					if(firstPrint)	
					{
						firstPrint = 0;
						cout << optr.top();
					}
					else	cout << " " << optr.top();
					optr.pop();
				}
				optr.push(ch);
			}
			ch = getchar();//读入新字符
		}
	}

	while( !optr.empty() ) 
	{
		if(optr.top() == '=')	break;
		if(firstPrint)	
		{
			firstPrint = 0;
			cout << optr.top();
		}
		else	cout << " " << optr.top();
		optr.pop();
	}
	cout << endl; 
}

int main()
{
	Run(); 
	return 0;
}