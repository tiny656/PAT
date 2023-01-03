#include <iostream>
#include <cmath>
using namespace std;

int GetBits(int k) {
    int b;
    for (b = 0; k != 0; b++) k /= 10;
    return b;
}

int main() {
    int n, m, k;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        bool isOk = false;
        for (int n = 1; n < 10; n++) {
            if (n*k*k % int(pow(10, GetBits(k))) == k) {
                isOk = true;
                cout << n << " " << n*k*k << endl;
                break;
            }
        }
        if (!isOk) cout << "No" << endl;
    }
    return 0;
}