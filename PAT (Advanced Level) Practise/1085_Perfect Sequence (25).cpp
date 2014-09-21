#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cctype>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;

vector<long long> vec;

int main() {
	int n;
	long long p, e;
	scanf("%d%lld", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &e);
		vec.push_back(e);
	}
	sort(vec.begin(), vec.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int pos = upper_bound(vec.begin(), vec.end(), vec[i]*p) - vec.begin();
		if (pos-1 >= 0) pos -= 1;
		// cout << vec[i]*p << " " << pos << endl;
		ans = max(ans, pos-i+1);
	}
	printf("%d\n", ans);
	return 0;
}