#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
using namespace std;

list<int> A,B,C;


int main()
{
	int e;
	while(scanf("%d", &e), e!= -1)
	{
		A.push_back(e);
	}
	while(scanf("%d", &e), e!= -1)
	{
		B.push_back(e);
	}
	while(!A.empty() && !B.empty())
	{
		if(A.front() > B.front())
		{
			C.push_back(B.front());
			B.pop_front();
		}
		else
		{
			C.push_back(A.front());
			A.pop_front();
		}
	}
	while(!A.empty())
	{
		C.push_back(A.front());
		A.pop_front();
	}
	while(!B.empty())
	{
		C.push_back(B.front());
		B.pop_front();
	}
	if(C.empty())	cout << "NULL" << endl;
	else
	{
		cout << C.front();
		C.pop_front();
		while(!C.empty())
		{
			cout << " " << C.front();
			C.pop_front();
		}
		cout << endl;
	}
	return 0;
}