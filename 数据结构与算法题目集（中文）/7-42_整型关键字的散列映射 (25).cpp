#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, p, e;
    bool first = true;
    cin >> n >> p;
    vector<int> elems(p, -1);
    unordered_map<int, bool> vis; // duplicate elements regard as same
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++) {
        cin >> e;
        int key = e % p;
        if (vis[e]) cout << " " << pos[e];
        else {
            if (elems[key] == -1) {
                elems[key] = e;
                vis[e] = true;
                pos[e] = key;
                if (first) {
                    first = false;
                    cout << key;
                } else {
                    cout << " " << key;
                }
            } else {
                for (int j = e + 1;; j++) {
                    if (elems[j % p] == -1) {
                        cout << " " << j % p;
                        elems[j % p] = e;
                        vis[e] = true;
                        pos[e] = j % p;
                        break;
                    }
                }
            }
        }
    }
    cout << endl;
    return 0;
}
