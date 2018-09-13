#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, m, k, e;
    vector<pair<int, int>> rules;
    pair<int, int> r;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> r.first >> r.second;
        rules.push_back(r);
    }
    for (int i = 0; i < m; i++) {
        cin >> k;
        bool isOk = true;
        unordered_set<int> menu;
        for (int j = 0; j < k; j++) {
            cin >> e;
            menu.insert(e);
        }
        for (const auto &p : rules) {
            if (menu.find(p.first) != menu.end() && menu.find(p.second) != menu.end()) {
                isOk = false;
                break;
            }
        }
        cout << (isOk ? "Yes" : "No") <<endl;
    }
    return 0;
}