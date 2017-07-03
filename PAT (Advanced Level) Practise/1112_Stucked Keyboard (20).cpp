/*
模拟题意，使用count记录连续的键位，然后更新状态
*/
#include <bits/stdc++.h>
using namespace std;

int isStucked['z'+1]; // 记录键盘是否被卡住

int main() {
    int k, cnt;
    char c;
    string s, stuckedKey = "";
    cin >> k >> s;
    c = s[0];
    cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) cnt++;
        if (s[i] != c || i == s.size()-1) {
            if (!(cnt % k) && (isStucked[c] != 1)) {
                if (isStucked[c] == 0) stuckedKey += c;
                isStucked[c] = 2;
            } else isStucked[c] = 1;
            c = s[i];
            cnt = 1;
        }
    }

    string ans = "";
    for (const char &c : stuckedKey) {
        if (isStucked[c] == 2) ans += c;
    }
    ans += "\n";
    for (int i = 0; i < s.size(); ) {
        ans += s[i];
        i += (isStucked[s[i]] == 2 ? k : 1);
    }
    cout << ans << endl;

    return 0;
}