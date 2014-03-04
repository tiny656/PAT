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
#define REP(i,n) FOR(i,1,(n))
#define REPT(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define IOS ios::sync_with_stdio(false)

const double pi = 3.1415926535897932384626433832795028841971;
const double EPS = 1E-9;
const int64 INF64 = ( int64 )1E18;
const int INF = 1000000000;

static inline bool get( int &v ) {
	int s = 1, c;
	while( !isdigit( c = getchar() ) && c != '-' )
		if( c == EOF )    break ;
	if( c == EOF ) return 0;
	if( c == '-' ) s = 0 , v = 0;
	else v = c ^ 48;
	for( ; isdigit( c = getchar() ); v = ( v << 1 ) + ( v << 3 ) + ( c ^ 48 ) );
	v = ( s ? v : -v );
	return 1 ;
}

vector<int> adj[1005];//邻接表
int vis[1005];//是否访问
int n, limit;

//BFS一圈一圈向外查找符合要求的，不符合要求就不加入队列
//pair<int, int> 第一个记录当前点序号，第二个记录当前的Level
int solve(int start) {
	int i;
	memset(vis, 0, sizeof(vis));
	queue< pair<int, int> > q;
	q.push(make_pair(start, 0));
	vis[start] = 1;
	int num = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		if (cur.second <= limit && cur.second != 0)	
			num++;
		q.pop();
		if (cur.second > limit) continue;
		for (i = 0; i < adj[cur.first].size(); i++) {
			if (!vis[adj[cur.first][i]]) {
				vis[adj[cur.first][i]] = 1;
				q.push(make_pair(adj[cur.first][i], cur.second+1));
			}
		}
	}
	return num;
}

void run() {
	int i, j, from, num, query;
	cin >> n >> limit;
	for (i = 1; i <= n; i++) {
		cin >> num;
		for (j = 1; j <= num; j++) {
			cin >> from;
			adj[from].push_back(i);
		}
	}

	cin >> num;
	for (i = 1; i <= num; i++) {
		cin >> query;
		cout << solve(query) << endl;
	}
}

int main() {
#ifdef __DEBUG__
	freopen( "test.in", "r", stdin );
	freopen( "test.out", "w", stdout );
	time_t st = clock();
#endif
	run();
#ifdef __DEBUG__
	printf( "\n=============\n" );
	printf( "Time: %.2lf sec\n", ( clock() - st ) / double( CLOCKS_PER_SEC ) );
#endif
	return 0;
}