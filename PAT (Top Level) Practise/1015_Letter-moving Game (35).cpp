#include <bits/stdc++.h>
using namespace std;
/*
移动最少的字符另S->T，即等价于保留原有字符中最多相对应不移动的字符
则S和T的公共串关系决定答案，即最长公共的S子序列和T子串是最多不移动的字符
*/
int main() {
    string s, t;
    cin >> s >> t;
    int size = s.size(), v = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0, k= i; j < size; j++) {
            if (k >= size) break;
            if (s[j] == t[k]) k++;
            v = max(v, k-i);
        }
    }
    cout << size - v << endl;
    return 0;
}