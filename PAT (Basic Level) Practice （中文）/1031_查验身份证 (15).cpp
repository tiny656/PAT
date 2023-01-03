#include <bits/stdc++.h>
using namespace std;

int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int check[] = {1,0,10,9,8,7,6,5,4,3,2};

int main() {
	int n;
	string id;
	vector<string> id_arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id;
		int z = 0;
		bool ok = true;
		for (int j = 0; j < id.size()-1; j++) {
			if (id[j] == 'X')	ok = false;
			else	z = (z + weight[j] * (id[j]-'0')) % 11;
		}
		int check_bit = (id[id.size()-1] == 'X') ? 10 : id[id.size()-1]-'0';
		if (ok && check_bit != check[z]) ok = false;
		if (ok) continue;
		else id_arr.push_back(id);
	}
	if (id_arr.size() == 0)	cout << "All passed" << endl;
	else {
		for (int i = 0; i < id_arr.size(); i++)
			cout << id_arr[i] << endl;
	}
	return 0;
}