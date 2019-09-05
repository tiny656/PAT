#include <iostream>
using namespace std;


/*
   宝石分配方案 | P 
		D-1 0 1 | 3
      D-3 0 1 2 | 4
	D-3 0 1 2 0 | 5
  D-4 0 1 2 0 1 | 6
D-4 0 1 2 0 1 0 | 7
......
满足利益最大化 
*/

int main()
{
	int d,p,i;
	int ans[101] = {0,0,0,1,3,3};
	int cur = 4; 
	for(i = 6; i <= 100; )
	{
		int cnt = 2;
		while(cnt--)
		{
			ans[i++] = cur;
		}
		cur++;
	}
	
	cin >> d >> p;
	cout << d-ans[p] << endl;
	return 0;
}