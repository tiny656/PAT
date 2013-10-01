#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct box_info
{
	int id;
	int w;
}tmp;

vector<box_info> left_box_list;
int s[1005],ans[1005];
int main()
{
	int n,i,m = -1;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		tmp.id = i;
		tmp.w = 100;
		left_box_list.push_back(tmp);
	}
	for(i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	for(i = 1; i <= n; i++)
	{
		for(vector<box_info>::iterator iter = left_box_list.begin(); iter != left_box_list.end(); iter++)
		{
			if((*iter).w - s[i] >= 0)
			{
				(*iter).w -= s[i];
				ans[i] = (*iter).id;
				m = max((*iter).id, m);
				if((*iter).w == 0)
				{
					iter = left_box_list.erase(iter);
				}
				break;
			}
		}
	}
	for(i = 1; i <= n; i++)
	{
		cout << s[i] << " " << ans[i] << endl;
	}
	cout << m << endl;

	return 0;
}