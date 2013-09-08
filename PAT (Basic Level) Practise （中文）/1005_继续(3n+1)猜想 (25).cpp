#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

int f[100000];
vector<int> ee;
vector<int> ans;
int main()
{
	int n,i,e;
	memset(f, 0, sizeof(f));
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> e;
		ee.push_back(e);
	}
	for(i = 0; i < ee.size(); i++)
	{
		int  tmp = ee[i];
		while(tmp != 1)
		{
			if(tmp & 1)	
			{
				tmp = (3*tmp+1) >> 1;
			}
			else
			{
				tmp >>= 1;
			}
			f[tmp] = 1;
		}
	}
	for(i = 0; i < ee.size(); i++)
	{
		if(!f[ee[i]])	ans.push_back(ee[i]);
	}
	sort(ans.begin(), ans.end(), greater<int>());
	cout << ans[0];
	for(i = 1; i < ans.size(); i++)
	{
		cout << " " << ans[i];
	}	
	cout << endl;
}