#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// sort algo can meet the data requirements
// otherwise maintain a small heap with M elements
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> elems(n);
    for (int i = 0; i < n; i++) {
        cin >> elems[i];
    }
    sort(elems.begin(), elems.end(), greater<int>());
    for (int i = 0; i < (n < m ? n : m); i++) {
        if (i == 0) cout << elems[i];
        else cout << " " << elems[i];
    }
    cout << endl;
    return 0;
}