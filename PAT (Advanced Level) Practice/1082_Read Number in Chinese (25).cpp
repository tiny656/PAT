#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string num[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" }; //每位的数值
string p[] = { "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi", "Shi", "Bai", "Qian"};//每位的权值

vector<string> ans;//存储结果用于输出

int main() {
	int sign = 1;
	string in;
	cin >> in;
	if (in[0] == '-') {//处理符号
		sign = 0;
		in = in.substr(1);
	}
	while (in.size() > 1 && in[0] == '0') { //预处理前置0的情况
		in = in.substr(1);
	}

	if (in == "0") {//结果就为0的话
		cout << "ling" << endl;	
	} else {
		//负数
		if (!sign)	ans.push_back("Fu");
		reverse(in.begin(), in.end());
		int ok = 1;
		int ok_p = 1;//处理亿和万
		for (int i = in.size() - 1; i >= 0; i--) {
			if (in[i] == '0') {
				ok = 0;
				if (ok_p && (i == 8 || i == 4) ) {//处理亿和万 , 100000000 yi Yi 不要输出成yi Yi Wan
					ans.push_back(p[i]);
					ok_p = 0;
				}

			} else {
				if (!ok) {
					ans.push_back(num[0]);
					ok = 1;
				}
				ans.push_back(num[in[i] - '0']);
				if (i != 0)	ans.push_back(p[i]);
				if (i == 8) {//处理亿和万 , 100000000 yi Yi 不要输出成yi Yi Wan
					ok_p = 0;
				}
			}
		}
		cout << ans[0];
		for (int i = 1; i < ans.size(); i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}