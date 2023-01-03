#include <iostream>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;

/*
最长不重复子串
双指针 lo, hi 维护一个不重复的最长子序列，用unordered_set进行重复元素检查
*/

inline int max(int x, int y) {
    return x > y ? x : y;
}

int main() 
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> color, value;
    color.resize(n); 
    value.resize(n);

    for (int i = 0; i < n; i++) cin >> value[i];
    for (int i = 0; i < n; i++) cin >> color[i];

    unordered_set<int> colorSet;
    int lo = 0, hi = 0;
    int curVal = 0, maxLen = 0;
    tuple<int, int, int, int> ans(0, 0, 0, 0);
    while (lo < n && hi < n) {
        if (colorSet.find(color[hi]) == end(colorSet)) {
            colorSet.insert(color[hi]);
            curVal += value[color[hi]-1];
            maxLen = max(maxLen, hi-lo+1);
            if (maxLen > get<0>(ans) 
               || (maxLen == get<0>(ans) && curVal > get<1>(ans))) {
                ans = make_tuple(maxLen, curVal, lo, hi);
            }
            hi += 1;
        }
        else {
            colorSet.erase(color[lo]);
            curVal -= value[color[lo]-1];
            lo += 1;
        }
    }
    cout << get<1>(ans) << " " << get<2>(ans) << " " << get<3>(ans) << endl;
    return 0;
}