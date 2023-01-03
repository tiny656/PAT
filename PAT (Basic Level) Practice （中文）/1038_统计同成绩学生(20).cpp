#include <bits/stdc++.h>
using namespace std;

// unordered_map维护
int main(int argc, char const *argv[]) {
    int n, score, query;
    unordered_map<int, int> gradeCount;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &score);
        ++gradeCount[score];
    }
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        scanf("%d", &score);
        if (i == 0) printf("%d", gradeCount[score]);
        else printf(" %d", gradeCount[score]);
    }
    printf("\n");
    return 0;
}