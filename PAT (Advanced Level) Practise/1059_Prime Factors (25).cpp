#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;



int main()
{
	long long n,i,val;
	cin >> n;
	val = n;
	cout << n << "=";
	int first = 1;
	int ok = 0;
	for(i = 2; i <= floor(sqrt((double)val)+0.5); i++)
	{
		int cnt = 0;
		while(n % i == 0)
		{

			cnt++;
			n /= i;
		}
		if(cnt)
		{
			ok = 1;
			if(first)
			{
				if(cnt == 1)	cout << i;
				else		cout << i << "^" << cnt;	
				first = 0;
			}
			else
			{
				if(cnt == 1)	cout << "*" << i;
				else		cout << "*" << i << "^" << cnt;
			}
		}
	}
	if(!ok) cout << val;
	cout << endl;
	return 0;
}