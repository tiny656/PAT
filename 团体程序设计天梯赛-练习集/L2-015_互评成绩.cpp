#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k, m;
    cin >> n >> k >> m;
    vector<float> scores(n);
    for (int i = 0; i < n; i++) {
        int lo = 100, hi = 0;
        int sum = 0;
        for (int j = 0; j < k; j++) {
            int score;
            cin >> score;
            sum += score;
            lo = min(lo, score);
            hi = max(hi, score);
        }
        sum -= lo + hi;
        scores[i] = sum / (float)(k - 2);
    }
    sort(scores.begin(), scores.end());
    cout << fixed << setprecision(3) << scores[n - m];
    for (int i = n - m + 1; i < n; i++) {
        cout << " " << fixed << setprecision(3) << scores[i];
    }
    cout << endl;
    return 0;
}