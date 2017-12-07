#include <bits/stdc++.h>
using namespace std;
// 离散化+树状数组

typedef long long int64;
class BinaryIndexedTree {
public:
    vector<int64> A;
    int length;
    BinaryIndexedTree(int length) {
        this->A.resize(length+1, 0LL);
        this->length = length;
    }
    int lowbit(int x) {return x&-x;}
    void add(int x, int64 c) {for (int i=x; i<=length; i+=lowbit(i)) A[i] += c;}
    int64 sum(int x) {int64 s=0; for (int i=x; i>0; i-=lowbit(i)) s+=A[i]; return s;}
};

int main() {
    int n;
    vector<pair<int, int>> arr;
    scanf("%d", &n);
    arr.resize(n);
    auto bit = BinaryIndexedTree(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first; });
    for (int i = 0; i < n; i++)
        arr[arr[i].second].first = i+1;

    stack<int64> ans;
    bit.add(arr[n-1].first, 1);
    ans.push(bit.sum(arr[n-1].first-1));
    for (int i = n-2; i >= 0; i--) {
        bit.add(arr[i].first, 1);
        ans.push(bit.sum(arr[i].first-1));
    }
    printf("%lld", ans.top());
    ans.pop();
    while (!ans.empty()) {
        printf(" %lld", ans.top());
        ans.pop();
    }
    printf("\n");
    return 0;
}