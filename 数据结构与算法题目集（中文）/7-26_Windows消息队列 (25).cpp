#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Message {
    int priority;
    string content;

    bool operator<(const Message &a) const {
        return priority > a.priority; // 小顶堆
    }
};

int main() {
    ios::sync_with_stdio(false);
    priority_queue<Message> pq;
    int n;
    string cmd;
    Message m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "PUT") {
            cin >> m.content >> m.priority;
            pq.push(m);
        } else if (cmd == "GET") {
            if (pq.empty()) {
                cout << "EMPTY QUEUE!" << endl;
            } else {
                cout << pq.top().content << endl;
                pq.pop();
            }
        }
    }

    return 0;
}
