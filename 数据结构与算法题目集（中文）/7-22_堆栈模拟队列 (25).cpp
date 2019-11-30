#include <iostream>
#include <stack>
using namespace std;

template<class T>
class Queue {
public:

    Queue(int n1, int n2) {
        this->sizeOfs1 = n1 < n2 ? n1 : n2;
        this->sizeOfs2 = n1 > n2 ? n1 : n2;
    }

    void AddQ(T item) {
        if (s1.size() < this->sizeOfs1) s1.push(item);
        else if (s1.size() == this->sizeOfs1 && s2.empty()) {
            while (!s1.empty()) { s2.push(s1.top()); s1.pop(); }
            s1.push(item);
        } else {
            cout << "ERROR:Full" << endl;
        }
    }

    T DeleteQ() {
        T result;
        if (!s2.empty()) {
            result = s2.top();
            cout << s2.top() << endl; s2.pop();
        } else if (!s1.empty()) {
            while (!s1.empty() && s2.size() < this->sizeOfs2) { s2.push(s1.top()); s1.pop(); }
            result = s2.top();
            cout << s2.top() << endl; s2.pop();
        } else {
            cout << "ERROR:Empty" << endl;
        }
        return result;
    }

private:
    int sizeOfs1, sizeOfs2;
    stack<T> s1, s2; // s1 小size负责Add输入, s2 大size负责Delete输出
};

int main() {
    int n1, n2, v;
    char ch;
    cin >> n1 >> n2;
    Queue<int> q = Queue<int>(n1, n2);
    while (cin >> ch && ch != 'T') {
        if (ch == 'A') {
            cin >> v;
            q.AddQ(v);
        } else if (ch == 'D') {
            q.DeleteQ();
        }
    }

    return 0;
}
