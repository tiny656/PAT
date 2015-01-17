#include <bits/stdc++.h>
using namespace std;

vector<int> target, ret;

// 判断两个vecotr中元素是否相同
bool same(const vector<int> &s, const vector<int> &t) {
    assert(s.size() == t.size());
    for (int i = 0; i < s.size(); i++)
    if (s[i] != t[i]) return false;
    return true;
}

// 打印vector元素
void printAns(const vector<int> &ans) {
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
    printf("\n");
}

// 插入排序
void insertSort(vector<int> v) {
    bool find = false;
    for (int i = 1; i < v.size(); i++) {
        if (same(v, target)) find = true;
        // 保证是交换过得，才能得到下一个序列
        bool isSwap = false;
        for (int j = i; j >= 1 && v[j - 1] > v[j]; j--) { swap(v[j], v[j - 1]); isSwap = true; }
        if (isSwap && find) {
            for (int j = 0; j < v.size(); j++) ret.push_back(v[j]);
            break;
        }
    }
}

// 合并
void merge(vector<int> &v, vector<int> &aux, int lo, int mid, int hi) {
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid) aux[k] = v[j++];
        else if (j > hi) aux[k] = v[i++];
        else if (v[i] < v[j]) aux[k] = v[i++];
        else aux[k] = v[j++];
    }
    for (int k = lo; k <= hi; k++)
        v[k] = aux[k];
}

// bottom-up 归并排序
void mergeSort(vector<int> v) {
    bool find = false;
    vector<int> aux(v.size());
    for (int n = 1; n < v.size() && !find; n = n + n) {
        if (same(v, target)) { find = true; }
        for (int i = 0; i < v.size() - n; i += n + n) {
            int lo = i, mid = i + n - 1, hi = min(i + n + n - 1, (int)v.size() - 1);
            merge(v, aux, lo, mid, hi);
        }
        // Merge总是会合并两个
        if (find) {
            for (int j = 0; j < v.size(); j++) ret.push_back(v[j]);
        }
    }
}

int main() {
    int n, e;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &e);
        v.push_back(e);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &e);
        target.push_back(e);
    }
    insertSort(v);
    if (ret.size() != 0) {
        printf("Insertion Sort\n");
        printAns(ret);
        return 0;
    }
    ret.clear();
    mergeSort(v);
    if (ret.size() != 0) {
        printf("Merge Sort\n");
        printAns(ret);
        return 0;
    }
    return 0;
}

/*
输入样例1：
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例1：
Insertion Sort
1 2 3 5 7 8 9 4 6 0

输入样例2：
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
输出样例2：
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/