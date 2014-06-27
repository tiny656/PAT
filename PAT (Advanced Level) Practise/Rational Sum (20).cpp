#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

void simplicity(int &num, int &denom) {
	int G = gcd(num, denom);
	num /= G;
	denom /= G;
}


int main() {

	char str[100];
	int n;
	int resNum = 0, resDenom = 0;
	int num, denom;
	cin >> n;
	if (n >= 1) {
		cin >> str;
		sscanf(str, "%d/%d", &resNum, &resDenom);
		simplicity(resNum, resDenom);
	}
	for (int i = 1; i < n; i++) {
		cin >> str;
		sscanf(str, "%d/%d", &num, &denom);
		simplicity(num, denom);
		int G = gcd(resDenom, denom);
		int L = resDenom*denom / G;
		resNum = resNum*(L/resDenom) + num*(L/denom);
		resDenom = L;
	}
	
	if (resNum == 0)	cout << "0" << endl;
	else {
		if (resNum % resDenom == 0)	cout << resNum / resDenom << endl;
		else {
			int integ = resNum / resDenom;
			resNum = resNum % resDenom;
			simplicity(resNum, resDenom);
			if (integ != 0) cout << integ << " ";
			cout << resNum << "/" << resDenom << endl;
		}
	}
	return 0;
}