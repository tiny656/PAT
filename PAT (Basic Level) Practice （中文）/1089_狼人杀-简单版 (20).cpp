#include <iostream>
using namespace std;
// 枚举两个狼人，检查所有人说的话，狼人不是这两个人，或者好人是这两个狼人，那么这个角色说的就是假话

int main() {
    int member[101];
    int n;
    cin >> n;
    pair<int, int> result = {0,0};
    for (int i = 1; i <= n; i++)
        cin >> member[i];
    for (int i = 1; i < n && result.first == 0; i++) {
        for (int j = i+1; j <= n && result.first == 0; j++) {
            int lier = 0, wolf = 0;
            for (int k = 1; k <= n; k++) {
                if (member[k] < 0 && abs(member[k]) != i && abs(member[k]) != j 
                    || member[k] > 0 && (abs(member[k]) == i || abs(member[k]) == j)) {
                    if (k != i && k != j) lier += 1;
                    else wolf += 1;
                }
            }
            if (lier == 1 && wolf == 1)
                result = {i, j};
        }
    }
    if (result.first == 0) cout << "No Solution" << endl;
    else cout << result.first << " " << result.second << endl;
    return 0;
}