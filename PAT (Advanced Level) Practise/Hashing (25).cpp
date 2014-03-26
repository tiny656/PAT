#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn = 50000;
int is_prime[maxn];
int prime[maxn];
int vis[maxn];
int cnt;

//预处理素数表
void init() {
	memset( vis, 0, sizeof( vis ) );
	memset( is_prime, 0, sizeof( is_prime ) );
	is_prime[0] = is_prime[1] = 1;
	int i, j;

	for ( i = 2; i < maxn; i++ ) {
		for ( j = 2; j * i < maxn; j++ )
			is_prime[i * j] = 1;
	}

	cnt = 0;

	for ( i = 2; i < maxn; i++ ) {
		if ( !is_prime[i] )
			prime[cnt++] = i;
	}
}

int find( int key ) {
	int left = 0, right = cnt - 1;

	while ( left <= right ) {
		int mid = ( left + right ) >> 1;

		if ( prime[mid] == key ) return key;
		else if ( prime[mid] < key )  left = mid + 1;
		else right = mid - 1;
	}

	return prime[left];
}

string str[105];
int pos[105];
int main() {
	init();
	int m_size, n, e, i, j, h;
	cin >> m_size >> n;

	if ( is_prime[m_size] )
		m_size = find( m_size );

	vector<int> ans;

	for ( i = 0; i < n; i++ ) {
		cin >> e;
		h = e % m_size;

		if ( !vis[h] ) {
			ans.push_back( h );
			vis[h] = 1;
		} else {
			int ok = 0;
			//二次探测 quadrtic probing
			for ( j = 1; j <= (m_size+1)>>1; j++ ) {
				h = ( e + j*j ) % m_size;

				if ( !vis[ h ] ) {
					ans.push_back( h );
					vis[h] = 1;
					ok = 1;
					break;
				}
			}

			if( !ok ) ans.push_back( -1 );
		}
	}

	if ( !ans.empty() )
		cout << ans[0];

	for ( i = 1; i < ans.size(); i++ ) {
		cout << " ";

		if ( ans[i] == -1 )   cout << "-";
		else cout << ans[i];
	}

	cout << endl;
	return 0;
}

