#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, string> BuildChildParentMap(int n) {
    unordered_map<string, string> child_parent_map;
    stack<string> s;
    string line, id;

    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        int depth = line.find_first_not_of(' ');
        id = line.substr(depth);
        while (s.size() > depth) s.pop();
        if (!s.empty()) child_parent_map[id] = s.top();
        s.push(id);
    }
    return child_parent_map;
}

// Function to trace back the path from a node to the root
string GetPath(const string& id, const unordered_map<string, string>& child_parent_map) {
    vector<string> path;
    string cur = id;

    while (child_parent_map.find(cur) != child_parent_map.end()) {
        path.push_back(cur);
        cur = child_parent_map.at(cur);
    }
    path.push_back("0000"); // Root ID

    string path_str;
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        if (it != path.rbegin()) path_str += "->";
        path_str += *it;
    }

    return path_str;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline after reading n

    auto child_parent_map = BuildChildParentMap(n);

    string queries_line;
    getline(cin, queries_line);
    istringstream iss(queries_line);
    string query;
    iss >> query; // Skip the first part, which indicates the number of queries

    while (iss >> query) {
        if (child_parent_map.find(query) != child_parent_map.end() || query == "0000") cout << GetPath(query, child_parent_map) << endl;
        else cout << "Error: " << query << " is not found." << endl;
    }

    return 0;
}