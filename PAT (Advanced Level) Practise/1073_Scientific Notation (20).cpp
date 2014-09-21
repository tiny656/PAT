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



void run() {

	//如果这里应该可以按照sscanf，这种format的格式来读入数据，感觉要比这样的输入简单一些。

	string str;
	int pos, i;
	cin >> str;
	string front = "";//记录E之前的
	int s1 = ( str[0] == '+' ) ? 1 : 0;//标记符号
	for ( i = 1; i < str.size(); i++ ) {
		if ( str[i] == '.' ) {//存储.的应该在哪一个数之后
			pos = i-1;
		} else if ( isdigit(str[i]) ) {
			front += str[i];
		} else if ( str[i] == 'E' ) {
			break;
		}
	}
	//处理E之后的
	int s2 = ( str[i+1] == '+' ) ? 1 : -1;//标记指数符号
	//读取指数大小
	stringstream ss;
	ss << str.substr( i+2 );
	int e;
	ss >> e;
	//计算.移动到的位置
	pos = pos + s2*e;
	//输出结果符号
	if ( !s1 ) cout << '-';
	//默认点位置为1，根据计算.移动向前还是向后，分开输出结果
	if ( pos <= 0 ) {
		cout << "0.";
		for ( i = 1; i <= -pos; i++ ) {
			cout << "0";
		}
		cout << front << endl;
	} else if ( pos > 0 ) {
		for ( i = 0; i < front.size(); i++ ) {
			cout << front[i];
			//注意这里判断恰好为front长度，末尾不能出现.
			if ( i+1 == pos && pos != front.size() ) {
				cout << '.';
			}
		}
		//front不够，就在后面补0，直到.所在pos的位置
		while ( i+1 <= pos ) {
			cout << '0';
			i++;
		}
		cout << endl;
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