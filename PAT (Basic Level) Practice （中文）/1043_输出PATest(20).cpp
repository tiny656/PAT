#include <bits/stdc++.h>
using namespace std;

int main() {
    string trans = "PATest";
    int cnt[6];
    memset(cnt, 0 , sizeof(cnt));
    string line;
    cin >> line;
    for (int i = 0; i < line.size(); i++) {
        for (int j = 0; j < trans.size(); j++) {
            if (trans[j] == line[i]) {
                cnt[j]++;
                break;
            }
        }
    }
    while (cnt[0] || cnt[1] || cnt[2] || cnt[3] || cnt[4] || cnt[5]) {
        for (int i = 0; i < trans.size(); i++) {
            if (cnt[i]) {
                cout << trans[i];
                cnt[i]--;
            }
        }
    }
    cout << endl;
    return 0;
}
