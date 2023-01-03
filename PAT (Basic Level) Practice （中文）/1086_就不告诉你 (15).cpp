#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c = a * b;
	if (c == 0) cout << c << endl;
	else {
		bool firstNotZero = false;
		while (c != 0) {
			if (c % 10 == 0) {
				if (firstNotZero)
					cout << c % 10;
			} else {
				firstNotZero = true;
				cout << c % 10;
			}
			c /= 10;
		}
		cout << endl;
	}
	return 0;
}