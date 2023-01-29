#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, v;
	char op;
	cin >> n;
	stack<int> s1;
	stack<char> s2;
	for (int i = 0; i < n; i++) {
		cin >> v;
		s1.push(v);
	}
	for (int i = 0; i < n-1; i++) {
		cin >> op;
		s2.push(op);
	}

	while (!s2.empty()) {
		int a = s1.top(); s1.pop();
		int b = s1.top(); s1.pop();
		char op = s2.top(); s2.pop();
		if (op == '+') s1.push(b+a);
		else if (op == '-') s1.push(b-a);
		else if (op == '*') s1.push(b*a);
		else if (op == '/') {
			if (a == 0) {
				cout << "ERROR: " << b << "/0" << endl;
				return 0;
			}
			s1.push(b/a);
		}
	}
	cout << s1.top() << endl;
	return 0;
}