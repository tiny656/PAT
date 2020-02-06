#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, p;
    string key;
    cin >> n >> p;
    vector<bool> hasValue(p, false);
    unordered_map<string, int> keyMapPos;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> key;

        if (keyMapPos.find(key) != keyMapPos.end()) {
            ans.push_back(keyMapPos[key]);
            continue;
        }
        int sz = key.size();
        int h = 0;
        // in case key size less than 3
        for (int j = (3 < sz ? 3 : sz); j >= 1; j--) {
            h = h*32 + key[sz-j] - 'A';
        }
        int b = 0;
        int c = h;
        while (true) {
            h = (c % p + b * b) % p;
            if (!hasValue[h]) break;
            h = ((c % p - b * b) % p + p) % p; // negative mod
            if (!hasValue[h]) break;
            b += 1;
        }
        hasValue[h % p] = true;
        keyMapPos[key] = h % p;
        ans.push_back(h % p);
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}