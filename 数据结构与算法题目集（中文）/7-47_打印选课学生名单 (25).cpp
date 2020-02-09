#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, cnt, id;
    string name;
    scanf("%d%d", &n, &k);
    vector<vector<string>> course(k+1);
    for (int i = 0; i < n; i++) {
        cin >> name;
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &id);
            course[id].push_back(name);
        }
    }
    for (int i = 1; i <= k; i++) {
        sort(course[i].begin(), course[i].end());
        printf("%d %d\n", i, course[i].size());
        for (auto &c : course[i]) {
            printf("%s\n", c.c_str());
        }
    }

    return 0;
}