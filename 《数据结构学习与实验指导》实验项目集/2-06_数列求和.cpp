#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;


vector<int> ans;

int main()
{
	int n,i,a,c;
	scanf("%d %d", &a, &n);
	
	i = 0;
	c = 0;
	while(n) 
	{
		ans.push_back((c + a * n) % 10);
		c = (c + a * n) / 10;
		n--;
	}
	if(c) ans.push_back(c);
	if(ans.size() == 0) printf("0");
	else
	{
		for( i = ans.size()-1 ; i >= 0; i--)
		{
			printf("%d", ans[i]);
		}
	}
	return 0;
}