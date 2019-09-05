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
struct info
{
	int ID;
	int D;
	int C;
	int tot;
}tmp;

vector<info> elem1,elem2,elem3,elem4;

int cmp(const info &a, const info &b)
{
	if(a.tot == b.tot)
	{
		if(a.D == b.D)	return a.ID < b.ID;
		else return a.D > b.D;
	}
	else return a.tot>b.tot;
}

void run()
{
	int n,l,h,num;
	get(n),get(l),get(h);
	num = n;
	rep(i,n)
	{
		get(tmp.ID),get(tmp.D),get(tmp.C);
		tmp.tot = tmp.D + tmp.C;
		if(tmp.C < l || tmp.D < l)
		{
			num--;
			continue;
		}
		if( tmp.D >= h && tmp.C >= h )
		{//1
			elem1.push_back(tmp);
		}
		else if(tmp.D >= h && tmp.C < h)
		{//2
			elem2.push_back(tmp);
		}
		else if(tmp.D < h && tmp.C < h && tmp.D >= tmp.C)
		{//3
			elem3.push_back(tmp);
		}
		else
		{//4
			elem4.push_back(tmp);
		}
	}
	sort(all(elem1),cmp);
	sort(all(elem2),cmp);
	sort(all(elem3),cmp);
	sort(all(elem4),cmp);
	printf("%d\n",num);
	rept(i, elem1.size())	printf("%d %d %d\n", elem1[i].ID,elem1[i].D,elem1[i].C);
	rept(i, elem2.size())	printf("%d %d %d\n", elem2[i].ID,elem2[i].D,elem2[i].C);
	rept(i, elem3.size())	printf("%d %d %d\n", elem3[i].ID,elem3[i].D,elem3[i].C);
	rept(i, elem4.size())	printf("%d %d %d\n", elem4[i].ID,elem4[i].D,elem4[i].C);
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

