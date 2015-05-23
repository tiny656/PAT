#include <bits/stdc++.h>
using namespace std;
// 预处理sumT[i]，表示从i到末尾有多少个T
// 枚举A的位置，统计前面P的个数乘以当前位置到后面T的个数
int sumT[100005];
int main(int argc, char const *argv[]) {
    string str;
    cin >> str;
    for (int i = str.size()-1; i >= 0; i--) {
        if (str[i] == 'T') sumT[i] = sumT[i+1] + 1;
        else sumT[i] = sumT[i+1];
    }

    int sum = 0, numP = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'P') numP++;
        else if (str[i] == 'A') {
            sum += (numP * sumT[i+1]) % 1000000007;
            sum %= 1000000007;
        }
    }
    cout  << sum << endl;
    return 0;
}