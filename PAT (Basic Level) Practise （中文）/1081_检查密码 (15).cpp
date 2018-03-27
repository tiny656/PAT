#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string checkPassword(const string &password) {
	string ret = "Your password ";
	
	if (password.size() < 6) return ret + "is tai duan le.";
	
	int hasAlpha = 0, hasDigit = 0;
	for (auto const &ch : password) {
		hasAlpha |= isalpha(ch);
		hasDigit |= isdigit(ch);
		if (!(ch == '.' || isdigit(ch) || isalpha(ch)))
			return  ret + "is tai luan le.";
	}

	if (!hasAlpha && hasDigit) return ret + "needs zi mu.";
	else if (hasAlpha && !hasDigit) return ret + "needs shu zi.";
	else if (hasAlpha && hasDigit) return ret + "is wan mei.";
}


int main() {
	int n;
	string password;
	cin >> n; cin.get();
	while (n--) {
		getline(cin, password, '\n');
		cout << checkPassword(password) << endl;
	}
	return 0;
}