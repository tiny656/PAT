#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
using namespace std;

vector<int> elem;

int main()
{
	int k,i,e;
	scanf("%d", &k);
	while(scanf("%d", &e), e >= 0 )
	{
		elem.push_back(e);
	}
	if(elem.size()- k >= 0 && elem.size()- k < elem.size() )	cout << elem[elem.size()-k] << endl;
	else	cout << "NULL" << endl;
	return 0;
}


//链表
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
using namespace std;

list<int> elem;

int main()
{
	int k,i,e;
	scanf("%d", &k);
	while(scanf("%d", &e), e >= 0 )
	{
		elem.push_back(e);
	}
	if(elem.size()- k >= 0 && elem.size()- k < elem.size() )	
	{

		while(--k)
		{
			elem.pop_back();
		}
		cout << elem.back() << endl;
	}
	else	cout << "NULL" << endl;
	return 0;
}
