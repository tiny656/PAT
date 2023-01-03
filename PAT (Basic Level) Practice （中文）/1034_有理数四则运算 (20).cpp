/**
 * 练习C++符号重载，参考《C++ Primer》
 * 注意溢出，使用64位整数
 * Fraction 类
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int64 gcd(int64 a, int64 b) {
	a = abs(a);
	b = abs(b);
	return b == 0 ? a : gcd(b, a%b);
}

class Fraction {
public:
	int64 numerator, denominator;
	int state;
	// read number
	Fraction(int64 a, int64 b, bool state = true) {
		this->state = state;
		if (state) {
			if (a % b == 0) {
				numerator = a / b;
				denominator = 1;
			}
			else {
				int64 c_d = gcd(a, b);
				numerator = a / c_d;
				denominator = b / c_d;
			}
		}
	}

	friend Fraction operator+ (const Fraction &lhs, const Fraction &rhs) {
		int64 a = lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator;
		int64 b = lhs.denominator * rhs.denominator;
		int64 c_d = gcd(a, b);
		return Fraction(a / c_d, b / c_d);
	}

	friend Fraction operator- (const Fraction &lhs, const Fraction &rhs) {
		int64 a = lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator;
		int64 b = lhs.denominator * rhs.denominator;
		int64 c_d = gcd(a, b);
		return Fraction(a / c_d, b / c_d);
	}

	friend Fraction operator* (const Fraction &lhs, const Fraction &rhs) {
		int64 a = lhs.numerator * rhs.numerator;
		int64 b = lhs.denominator * rhs.denominator;
		int64 c_d = gcd(a, b);
		return Fraction(a / c_d, b / c_d);
	}

	friend Fraction operator/ (const Fraction &lhs, const Fraction &rhs) {
		int64 a = lhs.numerator * rhs.denominator;
		int64 b = lhs.denominator * rhs.numerator;
		if (b < 0) { a *= -1; b *= -1; }
		int64 c_d = gcd(a, b);
		if (b == 0) return Fraction(a / c_d, b / c_d, false);
		else return Fraction(a / c_d, b / c_d);
	}

	friend ostream& operator << (ostream &os, const Fraction &f) {
		if (f.state) {
			bool bracket = false;
			if (f.numerator < 0) bracket = true;
			if (f.denominator == 1) {
				if (bracket) os << "(" << f.numerator << ")";
				else os << f.numerator;
			}
			else {
				if (bracket) os << "(";
				if (f.numerator / f.denominator != 0)	os << f.numerator / f.denominator << " ";
				else if (f.numerator < 0) os << "-";
				os << abs(f.numerator) % f.denominator << "/" << f.denominator;
				if (bracket) os << ")";
			}
		}
		else {
			os << "Inf";
		}
		return os;
	}


};


int main() {
	int64 a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	Fraction num1(a, b), num2(c, d);
	cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
	cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
	cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
	return 0;
}

/* Test Case
2/3 -4/2
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

5/3 0/6
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/