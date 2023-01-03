#include <bits/stdc++.h>
using namespace std;

// 带限制条件的01背包，需要先考虑deadline小的，这样才能更新到后面deadline大的情况
class Project {
public:
    int profit, lasting, deadline;

    Project() {}

    Project(int p, int l, int d) {
        this->profit = p;
        this->lasting = l;
        this->deadline = d;
    }

    bool operator< (const Project &p) const {
        return this->deadline < p.deadline;
    }

};

int main() {
    int n, p, l, d, max_deadline = 0, ans = 0;
    scanf("%d", &n);
    vector<Project> projects(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &p, &l, &d);
        max_deadline = max(max_deadline, d);
        projects[i] = Project(p, l, d);
    }
    sort(projects.begin(), projects.end());
    vector<int> dp(max_deadline+1, 0);
    for (int i = 0; i < n; i++) {
        auto p = projects[i];
        for (int j = p.deadline; j >= p.lasting; j--) {
            dp[j] = max(dp[j-p.lasting] + p.profit, dp[j]);
            ans = max(ans, dp[j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
