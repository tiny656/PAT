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

struct stu {
	int id;	//学生ID
	int score[6]; //每一道题得分
	int tot_score;//总得分
	int perfect_solve;//完全做对的题目数
	bool show;
}stu_list[10005];

int p[6];

bool cmp(const stu& a, const stu& b) {
	if (a.tot_score == b.tot_score) {
		if (a.perfect_solve == b.perfect_solve) {
			return a.id < b.id;
		} else {
			return a.perfect_solve > b.perfect_solve;
		}
	} else {
		return a.tot_score > b.tot_score;
	}
}

void run() {
	int n, k, m, i, j, stu_id, prob_id, pts;
	cin >> n >> k >> m;
	for (i = 0; i < k; i++) {
		cin >> p[i];
	}
	//初始化没有人答题
	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			stu_list[i].score[j] = -2;
		}
		stu_list[i].id = i+1;
		stu_list[i].perfect_solve = 0;
		stu_list[i].tot_score = 0;
		stu_list[i].show = false;
	}

	//读入得分
	for (i = 1; i <= m; i++) {
		cin >> stu_id >> prob_id >> pts; 
		if (pts >= stu_list[stu_id-1].score[prob_id-1]) {
			stu_list[stu_id-1].score[prob_id-1] = pts;
		}
	}
	//计算得分
	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			if (stu_list[i].score[j] >= 0) {
				stu_list[i].tot_score += stu_list[i].score[j];
				stu_list[i].show = true;
			}
			if (stu_list[i].score[j] == p[j])
				stu_list[i].perfect_solve += 1;
		}
	}
	//按照rank规则排序
	sort(stu_list, stu_list+n, cmp);
	//计算Rank并且输出答案
	int rank = 1;
	int curpts = 0;
	//判断是否有数据
	if(n >= 1) {
		if (stu_list[0].show == true) {
			curpts = stu_list[0].tot_score;
			printf("%d %05d %d", rank, stu_list[0].id, stu_list[0].tot_score);
			for (i = 0; i < k; i++) {
				if (stu_list[0].score[i] == -1) {
					printf(" 0");
				} else if(stu_list[0].score[i] == -2) {
					printf(" -");
				} else {
					printf(" %d", stu_list[0].score[i]);
				}
			}
			printf("\n");
		}
	} 
	//输出后面的
	int tmp = 1;
	for (i = 1; i < n; i++) {
		if (stu_list[i].show == true) {
			if (stu_list[i].tot_score < curpts) {
				rank += tmp ;
				curpts = stu_list[i].tot_score;
				tmp = 1;
			} else {
				tmp++;
			}
			printf("%d %05d %d", rank, stu_list[i].id, stu_list[i].tot_score);
			for (j = 0; j < k; j++) {
				if (stu_list[i].score[j] == -1) {
					printf(" 0");
				} else if(stu_list[i].score[j] == -2) {
					printf(" -");
				} else {
					printf(" %d", stu_list[i].score[j]);
				}
			}
			printf("\n");
		}
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