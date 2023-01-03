#include <bits/stdc++.h>
using namespace std;

// 直接打印
int main() {
    int col, row;
    char ch;
    cin >> col >> ch;
    row = (int)((double)col / 2.0 + 0.5);
    for (int i = 0; i < col; i++) cout << ch;
    cout << endl;
    for (int i = 0; i < row-2; i++) {
        cout << ch;
        for (int j = 0; j < col-2; j++) cout << " ";
        cout << ch << endl;
    }
    for (int i = 0; i < col; i++) cout << ch;
    cout << endl;
    return 0;
}