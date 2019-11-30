#include <cstdio>
#include <stack>
using namespace std;

struct Param {
    int n;
    char from, to, temp;
};

/*
n, A, C, B
=> n-1, A, B, C
=> n, A, C, B
=> n-1, B, C, A
*/

void Hanoi(int n, char from, char to, char temp) {
    stack<Param> s;
    Param call = {n, from, to, temp};
    while (call.n != 0 || !s.empty()) {
        Param p = call;
        while (p.n > 0) {
            s.push(p);
            p.n--;
            swap(p.to, p.temp);
        }

        call = s.top(); s.pop();
        printf("%c -> %c\n", call.from, call. to);

        call.n--;
        swap(call.from, call.temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Hanoi(n, 'a', 'c', 'b');
    return 0;
}