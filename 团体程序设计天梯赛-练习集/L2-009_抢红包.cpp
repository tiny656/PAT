#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k, ni, pi;
    cin >> n;
    vector<int> redPacket(n+1, 0), count(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> ni >> pi;
            redPacket[i] -= pi;
            redPacket[ni] += pi;
            count[ni] += 1;
        }
    }

    vector<tuple<float, int, int>> ans;
    for (int i = 1; i <= n; i++) {
        ans.push_back({redPacket[i]/100.f, count[i], i});
    }

    sort(ans.begin(), ans.end(), [&](const tuple<float, int, int> &a, const tuple<float, int, int> &b) {
        float value = fabs(get<0>(a) - get<0>(b));
        if (value < 1e-3)
        {
            if (get<1>(a) == get<1>(b)) return get<2>(a) < get<2>(b);
            else return get<1>(a) > get<1>(b);
        } else return get<0>(a) > get<0>(b);
    });

    for (const auto &p : ans) {
        cout << get<2>(p) << " " << fixed << setprecision(2) << get<0>(p) << endl;
    }

    return 0;
}
