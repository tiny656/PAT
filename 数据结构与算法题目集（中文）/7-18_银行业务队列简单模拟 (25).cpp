#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, v;
    queue<int> A, B;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        if (v % 2 != 0) A.push(v);
        else B.push(v);

    }

    vector<int> result;

    while (!A.empty() || !B.empty()) {
        if (!A.empty()) { result.push_back(A.front()); A.pop(); }
        if (!A.empty()) { result.push_back(A.front()); A.pop(); }
        if (!B.empty()) { result.push_back(B.front()); B.pop(); }
    }

    for (int i = 0; i < result.size(); i++) {
        if (i == 0) cout << result[0];
        else cout << " " << result[i];
    }
    cout << endl;

    return 0;
}