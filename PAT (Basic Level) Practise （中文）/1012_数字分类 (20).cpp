/**********************************
 * Author: Tiny656
 * Created Date: 2013年8月20日
 **********************************
 */
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
typedef pair<int, int> PII;
typedef pair<int64, int64> PLL;
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
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define IOS ios::sync_with_stdio(false)

const double pi = 3.1415926535897932384626433832795028841971;
const double EPS = 1E-9;
const int64 INF64 = (int64) 1E18;
const int INF = 1000000000;

static inline bool get(int &v)
{
	int s = 1, c;
	while (!isdigit(c = getchar()) && c != '-')
	{
		if (c == EOF) break;
	}
	if (c == EOF) return 0;
	if (c == '-') s = 0, v = 0;
	else v = c ^ 48;
	for (; isdigit(c = getchar()); v = (v << 1) + (v << 3) + (c ^ 48))
		;
	v = (s ? v : -v);
	return 1;
}
#define out(x) printf("%d")

//#define __DEBUG__

void run()
{
	int n,e;
	int f[6],a[6];
	while(get(n))
	{
		int k = 1, num = 0;
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		rep(i,n)
		{
			get(e);
			if(e%5 == 0 && e%2 == 0)
			{
				f[1] = 1;
				a[1] += e;
			}
			if(e%5 == 1)
			{
				f[2] = 1;
				a[2] += (k==1) ? e : -e;
				k = !k;
			}
			if(e%5 == 2)
			{
				f[3] = 1;
				a[3]++;
			}
			if(e%5 == 3)
			{
				f[4] = 1;
				a[4] += e;
				num++;
			}
			if(e%5 == 4)
			{
				f[5] = 1;
				a[5] = max(a[5], e);
			}
		}
		if(f[1])	printf("%d ", a[1]);
		else		printf("N ");
		if(f[2])	printf("%d ", a[2]);
		else		printf("N ");
		if(f[3])	printf("%d ", a[3]);
		else		printf("N ");
		if(f[4])	printf("%.1lf ", (double)a[4]/(double)num);
		else		printf("N ");
		if(f[5])	printf("%d\n", a[5]);
		else		printf("N\n");
	}
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

