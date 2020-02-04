#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, c;
    string id, name;
    int score;
    cin >> n >> c;
    vector<tuple<string, string, int>> stu;
    for (int i = 0; i < n; i++) {
        cin >> id >> name >> score;
        stu.push_back({id, name, score});
    }

    sort(stu.begin(), stu.end(), [&](tuple<string, string, int> a, tuple<string, string, int> b) {
        if (c == 1) {
            return get<0>(a) < get<0>(b);
        } else if (c == 2) {
            if (get<1>(a) == get<1>(b)) {
                return get<0>(a) < get<0>(b);
            } else {
                return get<1>(a) < get<1>(b);
            }
        } else if (c == 3) {
            if (get<2>(a) == get<2>(b)) {
                return get<0>(a) < get<0>(b);
            } else {
                return get<2>(a) < get<2>(b);
            }
        }
    });
    for (int i = 0; i < stu.size(); i++) {
        cout << get<0>(stu[i]) << " " << get<1>(stu[i]) << " " << get<2>(stu[i]) << endl;
    }

    return 0;
}