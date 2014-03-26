#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

//模拟从后往前比较末尾字符串，存储后的结果翻转一下
string str[105];
int pos[105];
int main() {
	int n, i, loop = 260, j;
	cin >> n;
	getchar();
	for (i = 0; i < n; i++) {
		getline(cin, str[i], '\n');
		loop = min(loop, (int)str[i].size());
	}
	int cur_rpos = 0;
	string ans_str = "";
	for (i = 0; i < loop; i++) {
		char ch = str[0][str[0].size() - cur_rpos - 1];
		int ok = 1;
		for (j = 1; j < n; j++) {
			if (str[j][str[j].size() - cur_rpos - 1] != ch) {
				ok = 0;
				break;
			}
		}
		if (ok)	ans_str += ch;
		else break;
		cur_rpos++;
	}
	if (ans_str == "") cout << "nai" << endl;
	else {
		reverse(ans_str.begin(), ans_str.end());
		cout << ans_str << endl;
	}
	return 0;
}
