#include <bits/stdc++.h>
using namespace std;

// set + 仿函数自定义排序

class RecommendCampare {
public:
    bool operator () (const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.second == b.second) return a.first < b.first;
        else return a.second > b.second;
    }
};

class RecommendList {
public:
    RecommendList(int k) { limit = k; }

    void print_recommend(int cur) {
        if (data.empty()) return;
        printf("%d:", cur);
        int cnt = 0;
        for (auto it = data.begin(); it != data.end() && cnt < limit; ++it) {
            printf(" %d", it->first);
            cnt += 1;
        }
        printf("\n");
    }

    void add(int x) {
        tot[x] += 1;
        auto p = make_pair(x, tot[x]-1);
        auto it = data.find(p);
        if (it != data.end()) data.erase(it);
        p.second += 1;
        data.insert(p);
    }

private:
    unordered_map<int, int> tot;
    set<pair<int, int>, RecommendCampare> data;
    int limit;
};


int main() {
    int n, k, v;
    scanf("%d%d", &n, &k);
    auto rs = RecommendList(k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        rs.print_recommend(v);
        rs.add(v);
    }
    return 0;
}
