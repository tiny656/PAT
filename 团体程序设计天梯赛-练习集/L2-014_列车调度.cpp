#include <iostream>
#include <set>
using namespace std;
/*
Principle: maintain the set of the smallest end of the trains
1. if coming train's number is larger than all exist numbers in ordered set, then add it to the set
2. else, remove next larger train's number(use lower_bound/upper_bound to find it) in set, and add the new train to the set
*/
int main() {
    ios::sync_with_stdio(false);
    int n, t;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        auto it = s.upper_bound(t);
        if (it == s.end()) s.insert(t); 
        else {
            s.erase(it);
            s.insert(t);
        }
    }
    cout << s.size() << endl;
    return 0;
}

/* 
//another implementation version
#include <iostream>
#include <vector>
using namespace std;
// Principle: maintain the set of the smallest end of the trains
// 1. if coming train's number is larger than all exist numbers in ordered set, then add it to the set
// 2. else, remove next larger train's number(use lower_bound/upper_bound to find it) in set, and add the new train to the set

int UpperBound(const vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    int n, t;
    vector<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        int pos = UpperBound(s, t);
        if (pos == s.size()) s.push_back(t); 
        else s[pos] = t;
    }
    cout << s.size() << endl;
    return 0;
}
*/
