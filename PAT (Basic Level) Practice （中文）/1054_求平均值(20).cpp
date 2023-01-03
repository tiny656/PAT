#include <bits/stdc++.h>
using namespace std;

/*
1. 数值转换，注意判断合法性和正确转换
2. number是否需要加s
*/

bool convert(string num, double &r) {
    int op = 1, p = 0;
    if (num[p] == '-') { op = -1; p++; }
    int pointNum = 0, pointPos = num.size();
    bool ok = true;
    for (int i = p; i < num.size() && ok; i++) {
        if (num[i] == '.') {
            pointNum++;
            if (pointNum > 1) ok = false;
            pointPos = i;
            continue;
        }
        if (!(num[i] <= '9' && num[i] >= '0')) ok = false;
    }
    if (!ok || (num.size() != pointPos && (num.size() - pointPos - 1) > 2)) {
        cout << "ERROR: " << num << " is not a legal number" << endl;
        return false;
    } else {
        r = 0.0;
        for (int i = 0; i < pointPos - p; i++)
            r = r * 10 + num[p+i] - '0';
        double s = 0;
        for (int i = 0; i < (int)num.size()-pointPos-1; i++) {
            s = s * 10 + num[pointPos + i + 1] - '0';
        }
        s /= pow(10, (int)num.size()-pointPos-1);
        r += s;
        r *= op;
        if (r < -1000 || r > 1000) {
            cout << "ERROR: " << num << " is not a legal number" << endl;
            return false;
        } else return true;
    }
}

int main() {
    int n;
    double r, sum = 0.0;
    int tot = 0;
    string num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (convert(num, r)) {
            tot++;
            sum += r;
        }
    }
    cout << "The average of " << tot;
    if (tot == 0)
        cout << " numbers is Undefined" << endl;
    else cout << " number" << (tot==1 ? "" : "s") << " is " << setiosflags(ios::fixed) << setprecision(2) << (double)sum / tot << endl;
    return 0;
}
