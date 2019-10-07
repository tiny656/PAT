#include <iostream>
using namespace std;

const int maxn = 100005;
int s1[maxn], s2[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s1[i];
    for (int i = 0; i < n; i++) cin >> s2[i];

    int lo = 0, hi = 0, pos = 0;
    while (lo < n || hi < n) {
        int v;
        if (lo >= n) v = s2[hi++];
        else if (hi >= n) v = s1[lo++];
        else if (s1[lo] < s2[hi]) v = s1[lo++];
        else v = s2[hi++];
        pos += 1;
        if (pos == n) {
            cout << v << endl;
            break;
        }
    }
    return 0;
}