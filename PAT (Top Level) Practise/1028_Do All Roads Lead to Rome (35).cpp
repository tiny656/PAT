#include <iostream>
#include <unordered_map>
#include <string>
#include <bitset>
using namespace std;

int n;
int dp[1<<19][19];
bool G[20][20];
unordered_map<string, int> cityIndex;
bool vis[20] = {false};
bool isValid = true;
int connectedState = 0;

bool check(int state, int pos) {
    if (state == 0 && pos == -1) return true;

    if ((state & (1<<pos)) &&
        ((pos!=n-2 && (state&(1<<(n-2))) == 0) || (pos == n-2))) // city target n-2 cant in state i if j is not target
        return true;

    return false;
}

void search(int city) {
    connectedState |= (1 << city);
    if (city == n-1) return;
    bool isConnected = false;
    for (int i = 0; i < n; i++) {
        if (vis[i] || !G[city][i]) continue;
        vis[i] = true;
        search(i);
        vis[i] = false;
        isConnected = true;
    }
    // cout << "search:" << city << " " << isConnected << endl;
    if (!isConnected) isValid = false;
}

int get(string city, int* index) {
    if (cityIndex.find(city) == cityIndex.end()) 
        cityIndex[city] = (*index)++;
    return cityIndex[city];
}

int main() {
    ios::sync_with_stdio(false);
    int k, index = 0;
    string seed, a, b;
    cin >> n >> k >> seed;
    cityIndex[string(seed)] = index++;
    cityIndex["ROM"] = n-1;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        int ca = get(a, &index), cb = get(b, &index);
        G[ca][cb] = G[cb][ca] = true;
    }

    for (int i = 0; i < 1 << (n-1); i++) {
        for (int j = -1; j < n-1; j++) {
            if (check(i, j)) {
                // cout << "valid: " <<  bitset<7>(i) << " " << j << endl;
                for (int k = 0; k < n-1; k++) {
                    if ((i & (1 << k)) == 0 && G[j+1][k+1]) {
                        int state = i | (1<<k);
                        if (j == -1) dp[state][k] += 1;
                        else dp[state][k] += dp[i][j];
                        // cout << "update: " <<  bitset<7>(state) << " " << k << endl;
                        // cout << "path: " <<  bitset<7>(i) << " " << j << endl;
                    }
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 1 << (n-1); i++) result += dp[i][n-2];

    vis[0] = true;
    search(0);
    vis[0] = false;

    int full = (1 << n) - 1;
    // cout << "connectedStaet: " <<  bitset<20>(connectedState)  << endl;
    // cout << "full:           " <<  bitset<20>(full)  << endl;
    // cout << "ROM:            " <<  bitset<20>((1<<n-1))  << endl;
    // cout << (connectedState == full)  << endl;
    // cout << isValid << endl;
    bool isOk;
    // no path to ROM
    if (result == 0) isOk = false;
    // issue here for this condition, why sub connected graph not respect isValid!!!
    else if (connectedState != full) isOk = true;
    else isOk = isValid;

    cout << (isOk ? "Yes" : "No") << endl << result << endl;

    return 0;
}

