#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <queue>
using namespace std;
//构造一棵树结构，使用BFS处理每个节点的深度，然后遍历每个子节点进行统计
class node {
public :
	int father;
	vector<int> son;
	int level;
} supply_train[100005];
int node_level[100005];
vector< pair<int, int> > retails;

void calculate_level() {
	int i;
	queue<int> q;
	q.push( 0 );
	node_level[0] = 0;

	while ( !q.empty() ) {
		int cur = q.front();
		q.pop();

		for ( i = 0; i < supply_train[cur].son.size(); i++ ) {
			node_level[supply_train[cur].son[i]] = node_level[cur] + 1;
			q.push( supply_train[cur].son[i] );
		}
	}
}


int main() {
	int n, i, e, j, id, amount;
	double p, r;
	scanf( "%d %lf %lf", &n, &p, &r );
	r /= 100.;

	for ( i = 0; i < n; i++ ) {
		scanf( "%d", &e );

		if ( e ) {
			for ( j = 0; j < e; j++ ) {
				scanf( "%d", &id );
				supply_train[i].son.push_back( id );
				supply_train[id].father = i;
			}
		} else {
			scanf( "%d", &amount );
			retails.push_back( make_pair( i, amount ) );
		}
	}

	calculate_level();
	double ans = 0.0;

	for ( i = 0; i < retails.size(); i++ )
		ans += p * pow( ( 1 + r ), node_level[ retails[i].first ] ) * retails[i].second;

	printf( "%.1lf\n", ans );
	return 0;
}

