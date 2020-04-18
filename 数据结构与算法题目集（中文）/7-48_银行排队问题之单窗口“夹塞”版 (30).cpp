#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

class Customer {
public:
    int arriveTime;
    int transactionTimeSpan;
    string name;
    bool isProcessed;
};

int main() {
    string name;
    int n, m, k;
    cin >> n >> m;

    vector<Customer> line(n);
    unordered_map<string, int> nameMapFriendListIndex;
    unordered_map<string, int> nameMapLineIndex;
    vector<vector<string>> friendList(m);
    for (int i = 0; i < m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> name;
            friendList[i].push_back(name);
            nameMapFriendListIndex[name] = i;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> line[i].name >> line[i].arriveTime >> line[i].transactionTimeSpan;
        line[i].isProcessed = false;
        nameMapLineIndex[line[i].name] = i;
        // override transactoin time if gt 60
        if (line[i].transactionTimeSpan > 60)
            line[i].transactionTimeSpan = 60;
    }
    
    // sort each circle list of friend names, order by index of line 
    for (auto &friends : friendList) {
        sort(friends.begin(), friends.end(), [&](const string a, const string b) {
            return nameMapLineIndex[a] < nameMapLineIndex[b];
        });
    }

    int waitTime = 0, totalTime = 0;
    for (int cur = 0; cur < n; cur++) {
        Customer *c = &line[cur];
        if (c->isProcessed) continue;
        cout << c->name << endl;
        c->isProcessed = true;

        // c->arriveTime >= totalTime means spare time for business window
        if (c->arriveTime >= totalTime) {
            totalTime = c->arriveTime + c->transactionTimeSpan;
        } else {
            // no spare time, we need update waitTime and elapsed totalTime
            waitTime += totalTime - c->arriveTime;
            totalTime += c->transactionTimeSpan;
        } 

        if (nameMapFriendListIndex.find(c->name) == nameMapFriendListIndex.end()) continue;

        // loop for all friends of customer c
        for (string name : friendList[nameMapFriendListIndex[c->name]]) {
            Customer *f = &line[nameMapLineIndex[name]];
            // if friend already arrived and not got processed
            if (!f->isProcessed && f->arriveTime <= totalTime) {
                cout << f->name << endl;
                f->isProcessed = true;
                waitTime += totalTime - f->arriveTime;
                totalTime += f->transactionTimeSpan;
            }
        }
    }

    cout << setiosflags(ios::fixed) << setprecision(1) << float(waitTime) / n;
    return 0;
}


/*
6 2
3 ANN BOB JOE
2 JIM ZOE
JIM 0 20
BOB 0 15
ANN 0 30
AMY 0 2
ZOE 1 61
JOE 3 10
*/