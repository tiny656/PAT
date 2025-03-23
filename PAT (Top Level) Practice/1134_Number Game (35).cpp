#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int LIMIT = 120000;
const int OFFSET = 120000;

// BFS to find the minimum steps to reach from A to B using operations +1, -1, and *N
int minSteps(int A, int B, int N) {
    bool visited[LIMIT + OFFSET + 1] = {false};
    if (A == B) return 0;

    queue<pair<int, int>> q;  // (value, steps)
    q.push({A, 0});
    visited[A + OFFSET] = true;

    while (!q.empty()) {
        auto [curr, steps] = q.front();
        q.pop();

        if (curr == B) return steps;

        if (curr < LIMIT && !visited[curr + 1 + OFFSET]) {
            visited[curr + OFFSET] = true;
            q.push({curr + 1, steps + 1});
        }

        if (curr > -LIMIT && !visited[curr - 1 + OFFSET]) {
            visited[curr - 1 + OFFSET] = true;
            q.push({curr - 1, steps + 1});
        }

        int mult = curr * N;
        if (mult >= -LIMIT && mult <= LIMIT && !visited[mult + OFFSET]) {
            visited[mult + OFFSET] = true;
            q.push({mult, steps + 1});
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    int K;
    cin >> K;

    int A, B, N;
    for (int i = 0; i < K; i++) {
        cin >> A >> B >> N;
        cout << minSteps(A, B, N) << endl;
    }

    return 0;
}