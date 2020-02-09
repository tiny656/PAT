#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    unordered_map<string, int> score;
    string id;
    int n, k, v;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> id >> v;
        score[id] += (v < k ? k : v);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id;
        if (score.find(id) == score.end()) {
            cout << "No Info" << endl;
        } else {
            cout << score[id] << endl;
        }
    }

    return 0;
}