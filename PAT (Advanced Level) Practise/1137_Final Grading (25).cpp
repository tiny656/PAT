#include <bits/stdc++.h>
using namespace std;

class Grade {
public:
    string id;
    int Gprog;
    int Gmid;
    int Gfinal;
    float Gtot;

    Grade() {
        this->Gprog = -1;
        this->Gmid = -1;
        this->Gfinal = -1;
        this->Gtot = 0;
    }
};

int main() {
    int p, m, n, score;
    string stuID;
    unordered_map<string, Grade> scores;
    cin >> p >> m >> n;
    for (int i = 0; i < p; i++) {
        cin >> stuID >> score;
        scores[stuID].id  = stuID;
        scores[stuID].Gprog = score;
    }
    for (int i = 0; i < m; i++) {
        cin >> stuID >> score;
        scores[stuID].id  = stuID;
        scores[stuID].Gmid = score;
    }
    for (int i = 0; i < n; i++) {
        cin >> stuID >> score;
        scores[stuID].id  = stuID;
        scores[stuID].Gfinal = score;
    }
    vector<Grade> vec;
    for (const auto &it : scores) {
        auto id = it.first;
        auto g = it.second;
        if (g.Gprog < 200) continue;
        if (g.Gmid <= g.Gfinal) g.Gtot = g.Gfinal;
        else g.Gtot = g.Gmid <= g.Gfinal ? g.Gfinal : floor((g.Gmid*0.4 + max(g.Gfinal, 0)* 0.6) + 0.5);
        if (g.Gtot < 60) continue;
        vec.push_back(g);
    }
    sort(vec.begin(), vec.end(), [](const Grade &a, const Grade &b) {
        if (a.Gtot == b.Gtot) return a.id < b.id;
        else return a.Gtot > b.Gtot;
    });
    for (const auto &it : vec) cout << it.id << " " << it.Gprog << " " << it.Gmid << " " << it.Gfinal << " " << it.Gtot << endl;
    return 0;
}