#include <iostream>
using namespace std;

int sales[1005] = {0};

int main() {
    int n, m, v;
    int maxSales = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v;
            sales[j] += v;
            maxSales = maxSales > sales[j] ? maxSales : sales[j];
        }
    }
    cout << maxSales << endl;
    bool first = true;
    for (int i = 0; i < n; i++) {
        if (maxSales == sales[i]) {
            if (first) {
                cout << i+1;
                first = false;
            } else {
                cout << " " << i+1;
            }
        }
    }
    cout << endl;
    return 0;
}