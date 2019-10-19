#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;

void update(string phone, int count, tuple<string, int, int> &ans) {
    if (count > get<1>(ans)) {
        get<0>(ans) = phone;
        get<1>(ans) = count;
        get<2>(ans) = 1;
    } else if (count == get<1>(ans)) {
        get<0>(ans) = phone < get<0>(ans) ? phone : get<0>(ans);
        get<2>(ans)++;
    }
}

int main() {
    int n;
    string a, b;
    tuple<string, int, int> ans("", 0, 0);
    unordered_map<string, int> record;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        record[a] += 1;
        record[b] += 1;
    }

    for (auto &v : record)
        update(v.first, v.second, ans);

    cout << get<0>(ans) << " " << get<1>(ans);
    if (get<2>(ans) != 1) 
        cout << " " << get<2>(ans);
    cout << endl;

    return 0;
}