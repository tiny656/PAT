#include <iostream>
#include <string>
using namespace std;

string Compare(double me, double other) {
    if (other > me) return "Cong";
    else if (other < me) return "Gai";
    else return "Ping";
}


int main() {
    int a, b, c, m, x, y;
    double result[3] = {.0, .0, .0};
    cin >> m >> x >> y;
    for (a = 10; a <= 99; a++) {
        b = a%10*10 + a/10;
        if (abs(a - b) * y == b * x && a >= result[0])
        {
            result[0] = a;
            result[1] = b;
            result[2] = b * 1.0 / y;
        }
    }
    if (result[0] == 0) {
        cout << "No Solution" << endl;
    } else {
        cout << result[0]
             << " " << Compare(m, result[0])
             << " " << Compare(m, result[1])
             << " " << Compare(m, result[2])
             << endl;
    }
    return 0;
}
