#include <bits/stdc++.h>
using namespace std;
// preOrd和inOrd构造postOrd,每次舍弃掉一半, 直到剩下一个元素
int findFirstNumInPostOrder(
    const vector<int> &preOrd, int preLeft, int preRight,
    const vector<int> &inOrd, int inLeft, int inRight) {
    auto root = preOrd[preLeft];
    int pos;
    for (pos = inLeft; pos <= inRight; pos++)
        if (inOrd[pos] == root) break;
    auto leftSize = pos - inLeft;
    auto rightSize = inRight - pos;
    if (leftSize > 0)
        return findFirstNumInPostOrder(preOrd, preLeft+1, preLeft+leftSize, inOrd, inLeft, pos-1);
    else if (rightSize > 0)
        return findFirstNumInPostOrder(preOrd, preLeft+leftSize+1, preRight, inOrd, pos+1, inRight);
    else return root;

}

int main() {
    int n;
    cin >> n;
    vector<int> preOrd(n), inOrd(n);
    for (int i = 0; i < n; i++)
        cin >> preOrd[i];
    for (int i = 0; i < n; i++)
        cin >> inOrd[i];
    cout << findFirstNumInPostOrder(preOrd, 0, n-1, inOrd, 0, n-1) << endl;
    return 0;
}
