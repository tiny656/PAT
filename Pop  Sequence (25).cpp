#include <iostream>
#include <cstring>
#include <stack>
using namespace std;



int main()
{
	int m,n,k,cur,i,val;
	scanf("%d %d %d", &m, &n, &k);
	while(k--)
	{
		stack<int> s;
		while(!s.empty()) s.pop();
		s.push(1);
		cur = 2;
		int ok = 1;
		for(i = 1; i <= n; i++)
		{
			scanf("%d", &val);
			while( (s.empty() || val != s.top()) && (cur <= n) && ((int)s.size() < m) )
			{
				s.push(cur);
				cur++;
			}
			if(val == s.top())
			{
				s.pop();
			}
			else
			{
				ok = 0;
			}
		}
		if(!ok)	puts("NO");
		else puts("YES");
	}
	return 0;
}