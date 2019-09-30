#include <iostream>
#include <vector>
using namespace std;
/*
B[i][j]表示i个节点，black-height为j的root为黑色的Red-Black Tree的数量
R[i][j]表示i个节点，black-height为j的root为红色的Red-Black Tree的数量

红色节点只有两个黑色节点作为子节点
黑色节点共有红红，红黑，黑红，黑黑四种情况作为子节点
所以
对于R[i][j], 则R[i][j] += B[k][j] * B[i-1-k][j]，其中 0<=k<i 
对于B[i][j], 则
B[i][j] += 
    R[k][j-1]*R[i-1-k][j-1] + 
    R[k][j-1]*B[i-1-k][j-1] + 
    B[k][j-1]*R[i-1-k][j-1] +
    B[k][j-1]*B[i-1-k][j-1]
    =(R[k][j-1] + B[k][j-1])*(R[i-1-k][j-1] + B[i-1-k][j-1])
因为节点最大数量为500,所以2^H-1 = 500, H最大不会超过8.
初始化R[1][0] = B[0][0] = 1。

最后统计Sum(B[n])
*/

typedef long long int64;

const int64 M = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    int64 n;
    cin >> n;
    vector<vector<int64>> B(n+1, vector<int64>(9, 0LL)), R(n+1, vector<int64>(9, 0LL));
    R[1][0] = B[0][0] = 1LL;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 8; j++) {
            for (int k = 0; k < i; k++) {
                B[i][j] += ((B[k][j-1] + R[k][j-1]) * (B[i-1-k][j-1] + R[i-1-k][j-1])) % M;
                B[i][j] %= M;
                R[i][j] += (B[k][j] * B[i-1-k][j]) % M;
                R[i][j] %= M;
            }
        }
    }
    int64 result = 0LL;
    for (auto &v : B[n]) {
        result = (result + v) % M;
    }
    cout << result << endl;
    return 0;
}