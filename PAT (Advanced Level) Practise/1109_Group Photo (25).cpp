/* K为排数，开始弄错成每行人数，sigh!*/

/* 参考的简洁写法*/
#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    string name;
    int height;
};

vector<Person> personArr;

int main() {
    string name;
    int n, k, height, w;
    cin >> n >> k;
    if (k > n) k = 1;
    w = n / k;

    for (int i = 0; i < n; i++) {
        cin >> name >> height;
        personArr.push_back({name, height});
    }

    sort(personArr.begin(), personArr.end(), [&](const Person &a, const Person &b) {
        if (a.height == b.height) return a.name > b.name;
        else return a.height < b.height;
    });

    string ans, line;
    for (int i = 0; i < k; i++) {
        int lo = i*w, hi = (i+1)*w;
        if (hi + w > n) hi = n;
        string line = personArr[hi-1].name;
        for (int j = hi-2; j >= lo; j--) {
            if (j%2 == hi%2)
                line = personArr[j].name + " " + line;
            else
                line = line + " " + personArr[j].name;
        }
        ans = line + "\n" + ans;
    }
    cout << ans;
    return 0;
}



/* 最初的冗余版本 */
#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    string name;
    int height;
};

vector<Person> personArr;

int main() {
    string name;
    int n, k, height, num;
    cin >> n >> k;
    if (k > n) k = 1;
    num = n / k;
    swap(num, k);

    for (int i = 0; i < n; i++) {
        cin >> name >> height;
        personArr.push_back({name, height});
    }

    sort(personArr.begin(), personArr.end(), [&](const Person &a, const Person &b) {
        if (a.height == b.height) return a.name < b.name;
        else return a.height > b.height;
    });

    string ans;
    int offset = n % k;
    if (offset) {
        string line = "";
        line += personArr[0].name;
        for (int i = 1; i < k+offset; i++) {
            if (i % 2) line = personArr[i].name + " " + line;
            else line = line + " " + personArr[i].name;
        }
        ans = ans + line + "\n";
        num -= 1;
    }

    for (int i = 0; i < num; i++) {
        string line = "";
        line += personArr[(offset ? (i+1)*k+offset : i*k)].name;
        for (int j = 1; j < k; j++) {
            int pos =  (offset ? (i+1)*k+offset : i*k) + j;
            if (j % 2) line = personArr[pos].name + " " + line;
            else line = line + " " + personArr[pos].name;
        }
        ans = ans + line + "\n";
    }
    cout << ans;
    return 0;
}
