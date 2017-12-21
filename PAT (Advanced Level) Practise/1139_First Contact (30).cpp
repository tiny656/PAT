#include <bits/stdc++.h>
using namespace std;

// 分别维护每个人的男女朋友关系
// 1. 对于A,B时候，其C，D的朋友中应该分别把B,A给排除掉

class Human {
public:
    int gender;
    unordered_set<string> maleFriends;
    unordered_set<string> femaleFriends;

    void addFriend(string id) {
        if (id[0] == '-')
            femaleFriends.insert(id);
        else
            maleFriends.insert(id);
    }

    bool isFriend(string id) {
        return femaleFriends.find(id) != femaleFriends.end() || maleFriends.find(id) != maleFriends.end();
    }
};

unordered_set<string> findFriends(const Human &human, bool sameGender=true) {
    if ((!human.gender && sameGender) || (human.gender && !sameGender))
        return human.femaleFriends;
    else
        return human.maleFriends;
}

int toID(string s) {
    int r = 0;
    for (int i = (s[0] == '-' ? 1 : 0); i < s.size(); i++)
        r = r*10 + s[i]-'0';
    return r;
}

int main() {
    int n, m, k;
    string p, q;
    unordered_map<string, Human> humans;
    cin >> n >> m;
    for (int i = 0 ;i < m; i++) {
        cin >> p >> q;
        humans[p].gender = p[0] == '-' ? 0 : 1;
        humans[p].addFriend(q);
        humans[q].gender = q[0] == '-' ? 0 : 1;
        humans[q].addFriend(p);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> p >> q;
        vector<pair<int, int>> ans;
        if (humans.find(p) != humans.end() && humans.find(q) != humans.end() && p != q) {
            auto pFriends = findFriends(humans[p]);
            auto qFriends = findFriends(humans[q]);
            bool sameGender = humans[p].gender == humans[q].gender;
            for (auto &pID : pFriends) {
                for (auto &qID : qFriends) {
                    if (pID != qID && pID != q && qID != p && humans[pID].isFriend(qID))
                        ans.push_back(make_pair(toID(pID), toID(qID)));
                }
            }
            sort(ans.begin(), ans.end());
        }
        cout << ans.size() << endl;
        for (auto &it : ans) cout << setfill('0') << setw(4) << it.first << " " << setfill('0') << setw(4) << it.second << endl;
    }
    return 0;
}