#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
// 树状数组
// f[i]表示当前i位之前比arr[i]大的元素数量, 也就等于 （i - 前i位之前比i小的元素数量），
// 也就是第i位的二元逆序数
// sigma(f[j]), A[i] > A[j] 即表示当前第j位的三元逆序数
// 所以分别用两个树状数组来维护，可推广到k元

class BinaryIndexedTree {
public:
    vector<int64> A;
    int length;

    BinaryIndexedTree(int length) {
        A.resize(length+1, 0LL);
        this->length = length;
    }

    int lowbit(int x) { return x & -x;}
    void add(int x, int64 c) { for (int i = x; i <= length; i+=lowbit(i)) A[i] += c; }
    long long sum(int x) {int64 s=0; for (int i = x; i > 0; i-=lowbit(i)) s += A[i]; return s;}

};

int main() {
    int n;
    int64 e;
    vector<int> arr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &e);
        arr.push_back(e);
    }
    auto bit1 = BinaryIndexedTree(n), bit2 = BinaryIndexedTree(n);
    int64 tot = 0, invCnt3 = 0;
    for (int i = 0; i < n; i++) {
        int64 val = arr[i];
        int64 gt2Num = i - bit1.sum(val-1);
        bit1.add(val, 1);
        int64 gt3Num = tot - bit2.sum(val-1);
        invCnt3 += gt3Num;
        tot += gt2Num;
        bit2.add(val, gt2Num);
    }
    printf("%lld\n", invCnt3);
    return 0;
}