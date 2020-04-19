#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

string &Trim(string &s) {
    if (s.empty()) return s;
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

string &RemoveExtraSpace(string &s) {
    string result = "";
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') result += s[i];
        else {
            if (s[i + 1] != ' ')
                result += s[i];
        }
    }

    s = result;
    return s;
}

int main() {
    int n;
    string weibo;
    unordered_map<string, unordered_set<int>> topicMapWeiboIndexSet;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, weibo);

        string topic = "";
        bool recording = false;

        for (const char &c : weibo) {
            if (c == '#') {
                recording = !recording;
                if (!recording) {
                    if (topic != "") { 
                        string processedTopic = RemoveExtraSpace(Trim(topic));
                        topicMapWeiboIndexSet[processedTopic].insert(i);
                        topic = "";
                    }
                }
                continue;
            }

            if (!recording) continue;

            // only keep a-z, A-Z, 0-9, replace others with space
            char target;
            if (c >= 'A' && c <= 'Z') target = c - 'A' + 'a';
            else if (c >= 'a' && c <= 'z') target = c;
            else if (c >= '0' && c <= '9') target = c;
            else target = ' ';
            topic += target;
        }
    }

    // post process, push <topic, count> to vector, sort by count, topic order
    vector<pair<string, size_t>> topicCount;
    for (auto &elem : topicMapWeiboIndexSet) {
        topicCount.push_back({elem.first, elem.second.size()});
    }

    sort(topicCount.begin(), topicCount.end(), [&](const pair<string, size_t> a, const pair<string, size_t> b) {
        if (a.second == b.second) return a.first < b.first;
        else return a.second > b.second;
    });

    // output for hottest topic
    pair<string, size_t> &hottest = topicCount[0];
    if (hottest.first[0] >= 'a' && hottest.first[0] <= 'z') {
        cout << (char)(hottest.first[0] - 'a' + 'A');
    } else {
        cout << hottest.first[0];
    }
    for (int i = 1; i < hottest.first.size(); i++) {
        cout << hottest.first[i];
    }
    cout << endl;
    cout << hottest.second << endl;

    // check same count with hottest topic
    int sameCount = 0;
    for (int i = 1; i < topicCount.size(); i++) {
        if (topicCount[i].second == hottest.second)
            sameCount++;
    }
    if (sameCount > 0) cout << "And " << sameCount << " more ..." << endl;

    return 0;
}