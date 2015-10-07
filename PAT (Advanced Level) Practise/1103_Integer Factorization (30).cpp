/*
dfs+回溯，
还有DP做法，类似于背包
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
int n, p, k;
vector<int> power;

int pow(int x, int p) {
    int res = 1;
    while (p--) res *= x;
    return res;
}

void printAnswer(vector<int> num) {
    cout << n << " = ";
    for (int i = power.size(); i >= 1; i--) {
        if (num[i] != 0) {
            cout << i << "^" << p;
            num[i]--;
            break;
        }
    }
    for (int i = power.size(); i >= 1; i--) {
        for (int j = 1; j <= num[i]; j++) {
            cout << " + " << i << "^" << p;
        }
    }
    cout << endl;
}

void solve(vector<int> &num, int val, int size, int start) {
    if (size == k && val == 0) {
        ans.push_back(num);
        return;
    }
    if (start >= power.size() || size > k || val < 0) return;
    for (int j = 0; (val >= j*power[start]) && (size+j <= k) && (ceil(val/(double)power[start])+j+size >= k); j++) {
        num[start+1] = j;
        val -= power[start]*j;
        size += j;
        solve(num, val, size, start+1);
        size -= j;
        val += power[start]*j;
        num[start+1] = 0;
    }
}

int main() {
    vector<int> num;
    scanf("%d %d %d", &n, &k, &p);
    for (int i = 1; ; i++) {
        int val = pow(i, p);
        if (val <= n)  power.push_back(val);
        else break;
    }
    num.resize(power.size()+1);
    solve(num, n, 0, 0);
    sort(ans.begin(), ans.end(), [](const vector<int> &a, const vector<int> &b)
    {
        int na = 0, nb = 0;
        for (int i = a.size()-1; i >= 1; i--) {na += i * a[i]; nb += i * b[i];}
        if (na == nb) {
            for (int i = a.size()-1; i >= 1; i--) {
                if (a[i] > b[i]) return true;
                else if (a[i] < b[i]) return false;
            }
            return true;
        }
        else return na > nb;
    });
    if (ans.empty()) cout << "Impossible" << endl;
    else printAnswer(ans[0]);
    return 0;
}
