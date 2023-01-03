#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int k) {
    for (int i = 2; i <= (int)sqrt((double)k); i++) {
        if (k % i == 0) return false;
    }
    return true;
}

int GetInteger(string s, int pos, int numOfBis) {
    int r = 0;
    for (int i = 0; i < numOfBis; i++, pos++) {
        r = r*10 + s[pos] - '0';
    }
    return r;
}

int main() {
    int L, K;
    bool isOk = false;
    string N;
    cin >> L >> K >> N;
    for (int i = 0; i <= L-K; i++) {
        int val = GetInteger(N, i, K);
        if (isPrime(val)) {
            isOk = true;
            cout << N.substr(i, K) << endl; // 前导0也需要输出
            break;
        }
    }
    if (!isOk) cout << "404" << endl;

    return 0;
}