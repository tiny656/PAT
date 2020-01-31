#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> record[182800];

int GetHash(char s[]) {
    return ((s[0] - 'A') * 26 * 26 + (s[1] - 'A') * 26 + (s[2] - 'A')) * 10 + s[3] - '0';
}

int main() {
    char name[5];
    int n, k, id, num;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d%d", &id, &num);
        for (int j = 0; j < num; j++) {
            scanf("%s", name);
            record[GetHash(name)].push_back(id);
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        auto courses = record[GetHash(name)];
        printf("%s %d", name, courses.size());
        if (courses.size() > 0) {
            sort (courses.begin(), courses.end());
            for (int j = 0; j < courses.size(); j++) {
                printf(" %d", courses[j]);
            }
        }
        printf("\n");
    }
    return 0;
}