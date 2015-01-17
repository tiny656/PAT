#include <bits/stdc++.h>
using namespace std;

bool brokenKey[256];

int main() {
    string brokenKeyStr;
    string inputStr;
    memset(brokenKey, false, sizeof(brokenKey));
    // 必须第一行，test case可能有空白字符
    getline(cin, brokenKeyStr);
    getline(cin, inputStr);
    cin >> brokenKeyStr >> inputStr;
    for (int i = 0; i < brokenKeyStr.size(); i++) {
        char ch = brokenKeyStr[i];
        brokenKey[ch] = true;
    }
    string outputStr = "";
    for (int i = 0; i < inputStr.size(); i++) {
        char ch = inputStr[i];
        if (ch <= 'Z' && ch >= 'A' && (brokenKey[ch] || brokenKey['+'])) continue;
        else if (ch <= 'z' && ch >= 'a' && (brokenKey[ch-'a'+'A'])) continue;
        else if (brokenKey[ch]) continue;
        else outputStr += ch;
    }
    cout << outputStr << endl;
    return 0;
}