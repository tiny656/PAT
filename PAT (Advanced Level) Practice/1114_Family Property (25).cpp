/*
bfs + sort
*/
#include <bits/stdc++.h>
using namespace std;

class Family {
public:
    vector<int> member;
    int M_estate;
    int area;
};

class Estate {
public:
    int id;
    int people;
    int tot_M_estate;
    int tot_area;
    double avg_sets;
    double avg_areas;

    Estate():id(10000),people(0),tot_M_estate(0),tot_area(0) { }
};

unordered_map<int, Family> G;

int main() {
    int n, id, pa[2], M_estate, area, child, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &id, &pa[0], &pa[1]);
        for (int j = 0; j < 2; j++) {
            if (pa[j] != -1) {
                G[id].member.push_back(pa[j]);
                G[pa[j]].member.push_back(id);
            }
        }
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            G[id].member.push_back(child);
            G[child].member.push_back(id);
        }
        scanf("%d%d", &M_estate, &area);
        G[id].M_estate = M_estate;
        G[id].area = area;
    }

    unordered_map<int, bool> vis;
    vector<Estate> ans;

    for (const auto &g : G) {
        int id = g.first;
        Estate e;

        if (!vis[id]) {
            queue<int> q;
            q.push(id);
            vis[id] = true;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                Family &f = G[cur];
                e.id = min(cur, e.id);
                e.people += 1;
                e.tot_M_estate += f.M_estate;
                e.tot_area += f.area;
                for (int i = 0; i < f.member.size(); i++) {
                    int id = f.member[i];
                    if (!vis[id]) {
                        q.push(id);
                        vis[id] = true;
                    }
                }
            }
            e.avg_sets = e.tot_M_estate / (double)e.people;
            e.avg_areas = e.tot_area / (double)e.people;
            ans.push_back(e);
        }
    }

    sort(ans.begin(), ans.end(), [&](const Estate &e1, const Estate &e2) {
        if (e1.avg_areas == e2.avg_areas) return e1.id < e2.id;
        else return e1.avg_areas > e2.avg_areas;
    });

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        Estate &e = ans[i];
        printf("%04d %d %.3f %.3f\n", e.id, e.people, e.avg_sets, e.avg_areas);
    }

    return 0;
}