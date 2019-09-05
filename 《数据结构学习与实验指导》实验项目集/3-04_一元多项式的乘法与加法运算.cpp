//map的使用 
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> A, B, C;

void printAns()
{
	map<int,int>::iterator iterC;
	for(iterC = C.begin(); iterC != C.end(); )
	{
		if(iterC->second == 0)
			iterC = C.erase(iterC);
		else
			iterC++;
	}
	if(C.size() == 0)	cout << "0 0" << endl;
	else
	{
		iterC = C.end();
		iterC--;
		if(iterC == C.begin()) cout << iterC->second << " " << iterC->first << endl;
		else
		{
			cout << iterC->second << " " << iterC->first;
			for(iterC--; iterC != C.begin(); iterC--)
			{
				cout << " " << iterC->second << " " << iterC->first;
			}
			if(C.begin() == iterC)	cout << " " << iterC->second << " " << iterC->first << endl;
			else	cout << endl;
		}
	}
	C.clear();
}

int main()
{
	map<int,int>::iterator iterA,iterB;
	int n,m,i,bom,mi;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> bom >> mi;
		A[mi] = bom;
	}
	cin >> m;
	for(i = 1; i <= m; i++)
	{
		cin >> bom >> mi;
		B[mi] = bom;
	}

	for(iterA = A.begin(); iterA != A.end(); iterA++)
	{
		for(iterB = B.begin(); iterB != B.end(); iterB++)
		{
			C[iterA->first + iterB->first] += iterA->second * iterB->second;
		}
	}
	printAns();

	for(iterA = A.begin(); iterA != A.end(); )
	{
		iterB = B.find(iterA->first);
		if(iterB != B.end())
		{
			C[iterA->first] += iterA->second + iterB->second;
			iterA = A.erase(iterA);
			iterB = B.erase(iterB);
		}
		else
		{
			C[iterA->first] += iterA->second;
			iterA = A.erase(iterA);
		}
	}
	for(iterB = B.begin(); iterB != B.end(); )
	{	
		C[iterB->first] += iterB->second;
		iterB = B.erase(iterB);
	}
	printAns();
	return 0;
}