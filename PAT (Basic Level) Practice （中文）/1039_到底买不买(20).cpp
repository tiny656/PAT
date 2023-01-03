#include <bits/stdc++.h>
using namespace std;

// unordered_map 统计一下 原始 和 目标的字符数量
// 计算两者差值，设置ok变量标记是缺少还是多余，并分别用两个变量维护
int main(int argc, char const *argv[]) {
    string origin, target;
    cin >> origin >> target;
    unordered_map<char, int> cntOri, cntTar;
    for (int i = 0; i < target.size(); i++)
        cntTar[target[i]]++;
    for (int i = 0; i < origin.size(); i++)
        cntOri[origin[i]]++;
    int sum = origin.size(), lack = 0;
    bool ok = true;
    for (auto it = cntTar.begin(); it != cntTar.end(); it++) {
        if (cntOri[it->first] < it->second) {
            ok = false;
            lack += it->second - cntOri[it->first];
        } else {
            sum -= it->second;
        }
    }
    printf("%s %d\n", ok ? "Yes": "No", ok ? sum : lack);
    return 0;
}