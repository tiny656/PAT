#include <iostream>
#include <set>
using namespace std;
/*
Principle: maintain the set of the smallest end of the trains
1. if coming train's number is larger than all exist numbers in ordered set, then add it to the set
2. else, remove next larger train's number(use lower_bound to find it) in set, and add the new train to the set
*/
int main() {
    ios::sync_with_stdio(false);
    int n, t;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        auto it = s.lower_bound(t);
        if (it == s.end()) s.insert(t); 
        else {
            s.erase(it);
            s.insert(t);
        }
    }
    cout << s.size() << endl;
    return 0;
}