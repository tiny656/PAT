#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Student {
    string raw;
    char level;
    int examRoom;
    string date;
    string id;
    int score;
    Student(string raw, int score) {
        this->raw = raw;
        this->level = raw[0];
        this->examRoom = (raw[1]-'0')*100 + (raw[2]-'0')*10 + (raw[3]-'0');
        this->date = raw.substr(4, 6);
        this->id = raw.substr(10, 3);
        this->score = score;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, command, score;
    string raw, param;
    cin >> n >> m;
    unordered_map<char, vector<pair<string, int>>> c1;
    unordered_map<int, pair<int, int>> c2;
    unordered_map<string, unordered_map<int, int>> c3;
    for (int i = 0; i < n; i++) {
        cin >> raw >> score;
        Student s = Student(raw, score);
        c1[s.level].push_back({raw, score});
        c2[s.examRoom].first += 1;
        c2[s.examRoom].second += score;
        c3[s.date][s.examRoom] += 1;
    }

    for (int i = 1; i <= m; i++) {
        cin >> command >> param;
        cout << "Case " << i << ": " << command << " " << param << endl;
        if (command == 1) {
            char level = param[0];
            if (c1.find(level) == c1.end()) cout << "NA" << endl;
            else {
                sort(c1[level].begin(), c1[level].end(), [&](const auto &a, const auto &b){
                    if (a.second == b.second) return a.first < b.first;
                    else return a.second > b.second;
                });
                for (const auto &v : c1[level]) {
                    cout << v.first << " " << v.second << endl;
                }
            }
        } else if (command == 2) {
            int room = stoi(param);
            if (c2.find(room) == c2.end()) cout << "NA" << endl;
            else cout << c2[room].first << " " << c2[room].second << endl;
        } else if (command == 3) {
            if (c3.find(param) == c3.end()) cout << "NA" << endl;
            else {
                vector<pair<int, int>> t;
                for (const auto &kv : c3[param]) 
                    t.push_back({kv.first, kv.second});
                sort(t.begin(), t.end(), [&](const auto &a, const auto &b){
                    if (a.second == b.second) return a.first < b.first;
                    else return a.second > b.second;
                });
                for (const auto &v : t) {
                    cout << v.first << " " << v.second << endl;
                }
            }
        }
    }

    return 0;
}