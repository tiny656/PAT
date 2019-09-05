#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <typeinfo>
#include <utility>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstddef>
#include <complex>
#include <ctime>
#include <cassert>
using namespace std;

/*计算n出现k的个数(1<=k<=9)*/
int cal1to9(int n,int k)
{
	int fact = 1,res = 0;
	while(n/fact!=0)
	{
		int high = (n / fact) / 10;
		int low = n % fact;
		int cur = (n-low)%(fact*10)/fact;
		if(cur > k)
			res += (high+1)*fact;
		else if(cur == k)
			res += high*fact + low + 1;
		else
			res += high*fact;
		fact *= 10;
	}
	return res;
}

static inline bool get(int &v)//fast to read huge input
{
	int s = 1, c;
	while(!isdigit(c = getchar())&&c != '-')
	{
		if(c == EOF)
			break ;
	}
	if(c == EOF) return 0;
	if(c == '-') s = 0 , v = 0;
	else v = c^48;
	for(;isdigit(c = getchar());v = (v << 1) + (v << 3) + (c ^ 48));
	v = (s ? v : -v);
	return 1 ;
}

int main()
{
	int n;
	get(n);
	printf("%d\n",cal1to9(n,1)-cal1to9(0,1));
	return 0;
}