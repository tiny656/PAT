#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<string, int> seat[1005];
    int n, test, real;
    string id;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> test >> real;
        seat[test] = {id, real};
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> test;
        cout << seat[test].first << " " << seat[test].second << endl;
    }
    return 0;
}
