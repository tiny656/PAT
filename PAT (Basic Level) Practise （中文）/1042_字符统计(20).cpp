#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt['z'+1];
    memset(cnt, 0, sizeof(cnt));
    string line;
    getline(cin, line);
    for (int i = 0; i < line.size(); i++) {
        if (line[i] >= 'a' && line[i] <= 'z')
            cnt[line[i]]++;
        else if (line[i] <= 'Z' && line[i] >= 'A')
            cnt[line[i]-'A'+'a']++;
    }
    int maxCnt = 0;
    char ch;
    for (int i = 'a'; i <= 'z'; i++) {
        if (cnt[i] > maxCnt) {
            maxCnt = cnt[i];
            ch = (char)i;
        }
    }
    cout << ch << " " << maxCnt << endl;
    return 0;
}
