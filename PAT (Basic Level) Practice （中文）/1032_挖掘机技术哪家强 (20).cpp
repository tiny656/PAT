#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int stu[maxn];
int main() {
    int n, id, score;
    int ansId, ansScore = -1;
    cin >> n;
    while (n--) {
        cin >> id >> score;
        stu[id] += score;
        if (stu[id] > ansScore) {
            ansId = id;
            ansScore = stu[id];
        }
    }
    cout << ansId << " " << ansScore << endl;
    return 0;
}