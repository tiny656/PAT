#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int lo = 0, hi = v.size() - 1;
    int diff = 0;
    while (lo <= hi) {
        if (lo == hi) {
            diff += v[lo];
            break;
        }
        diff += v[hi] - v[lo];
        lo++;
        hi--;
    }
    cout << "Outgoing #: " << (n + 1) / 2 << endl;
    cout << "Introverted #: " << n / 2 << endl;
    cout << "Diff = " << diff << endl;
    return 0;
}