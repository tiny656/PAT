#include <bits/stdc++.h>
using namespace std;

// 遍历链表，分为三类，负数，小于等于k，大于k，再顺序连接成链表

unordered_map<int, pair<int, int>> linklist;
vector<pair<int, int>> neg, le_eq_k, gt_k;
vector<pair<int, int>> reshape;

int main() {
    int begin, n, k, addr, data, next;
    scanf("%d%d%d", &begin, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &addr, &data, &next);
        linklist[addr] = make_pair(data, next);
    }
    int p = begin;
    while (p != -1) {
        int data = linklist[p].first;
        int next = linklist[p].second;
        auto node = make_pair(p, data);
        if (data < 0) neg.push_back(node);
        else if (data <= k) le_eq_k.push_back(node);
        else gt_k.push_back(node);
        p = next;
    }
    reshape.insert(reshape.end(), neg.begin(), neg.end());
    reshape.insert(reshape.end(), le_eq_k.begin(), le_eq_k.end());
    reshape.insert(reshape.end(), gt_k.begin(), gt_k.end());
    int last = reshape.size() - 1;
    for (int i = 0; i < last; i++)
        printf("%05d %d %05d\n", reshape[i].first, reshape[i].second, reshape[i+1].first);
    printf("%05d %d -1\n", reshape[last].first, reshape[last].second);
    return 0;
}
