#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:66777216")
#include <algorithm>
#include <string>
#include <complex>
#include <cassert>
#include <memory>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <deque>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <bitset>
using namespace std;
 
#if defined(_MSC_VER) || defined(__BORLANDC__)
    typedef unsigned __int64 uint64;
    typedef signed __int64 int64;
#else
    typedef unsigned long long uint64;
    typedef signed long long int64;
#endif
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef pair<int64,int64> PLL;
typedef vector<int64> VL;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pdd pair<double,double>
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define REP(i,n) FOR(i,1,(n))
#define REPT(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define IOS ios::sync_with_stdio(false)
 
const double pi = 3.1415926535897932384626433832795028841971;
const double EPS = 1E-9;
const int64 INF64 = (int64)1E18;
const int INF = 1000000000;
 
static inline bool get(int &v)
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

/*
去除已经在正常位置的元素，把其他的转换成一个一个的闭环，使用0去连接。
如果存在闭环的话。
结果是闭环个数-1加上他们元素之和-1.
*/
int e[100005];
int vis[100005];
VI loop[100005];

void run()
{
	C(vis);
	int n;
	get(n);
	REPT(i, n)
	{
		cin >> e[i];
	}
	int cur = 0, ok = 0;
	REPT(i, n)
	{
		if ( !vis[e[i]] )
		{
			int tmp = e[i];
			if ( i == 0 && e[0] == 0 ) ok = 1;//注意0在位置0的情况

			while ( !vis[tmp] )
			{
				loop[cur].push_back(tmp);
				vis[tmp] = 1;
				tmp = e[tmp];
			}

			cur++;
		}
	}
	int cnt = 0;
	int sum = 0;
	FOR(i, 0, cur-1)
	{
		if ( loop[i].size() != 1 )
		{
			cnt++;
			sum += loop[i].size();
		}
	}
	if (ok)
	{
		cnt++;
		sum++;
	}
	cnt = cnt ? cnt-1 : cnt;
	sum = sum ? sum-1 : sum;
	printf("%d\n", cnt+sum);


}
 
 
int main()
{
#ifdef __DEBUG__
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st = clock();
#endif
    run();
#ifdef __DEBUG__
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}
