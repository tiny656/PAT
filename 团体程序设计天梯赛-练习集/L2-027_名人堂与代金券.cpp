#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
	string mail;
	int score;
	int rank;
};

int main() {
	ios::sync_with_stdio(false);
	int n, g, k;
	cin >> n >> g >> k;

	int coupon = 0;
	vector<Student> stu(n);
	for (int i = 0; i < n; i++) {
		cin >> stu[i].mail >> stu[i].score;
		if (stu[i].score >= g) coupon += 50;
		else if (stu[i].score >= 60) coupon += 20;
	}

	sort(stu.begin(), stu.end(), [&](const Student &a, const Student &b) {
		return a.score == b.score ? a.mail < b.mail : a.score > b.score;
	});

	int rank = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && stu[i].score < stu[i - 1].score) rank = i + 1;
		stu[i].rank = rank;
	}

	cout << coupon << endl;
	for (auto &s : stu) {
		if (s.rank > k) break;
		cout << s.rank << " " << s.mail << " " << s.score << endl;
	}

	return 0;
}