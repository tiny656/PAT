#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu {
	string name;
	string ID;
	int grade;
	bool operator() (const stu &o) {
		return this->grade < o.grade;
	}
} tmp, L, R;

bool cmp(const stu &a, const stu &b) {
	return a.grade < b.grade;
}

vector<stu> vec;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp.name >> tmp.ID >> tmp.grade;
		vec.push_back(tmp);
	}
	//按照分数的从小到大排序
	sort(vec.begin(), vec.end(), cmp);
	cin >> L.grade >> R.grade;
	// 考察二分算法，这里直接使用STL算法高效简洁
	// STL算法使用，cmp最好写成仿函数的形式
	vector<stu>::iterator itL, itR, iter;
	itL = lower_bound(vec.begin(), vec.end(), L, cmp);
	itR = upper_bound(vec.begin(), vec.end(), R, cmp);

	if (itL == vec.end()) cout << "NONE" << endl;
	else {
		//从大到小输出结果
		itR--;
		for (iter = itR; iter >= itL; iter--) {
			cout << iter->name << " " << iter->ID << endl;
		}
	}
	return 0;
}