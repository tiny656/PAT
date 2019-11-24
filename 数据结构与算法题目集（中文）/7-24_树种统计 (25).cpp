#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    int n, count = 0;
    map<string, int> records;
    cin >> n;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        records[s]++;
        count++;
    }

    for (auto &r : records) {
        cout.setf(ios::fixed);
        cout << r.first << " " << setprecision(4)  << 100 * r.second / (float) count << "%" << endl;
    }

    return 0;
}