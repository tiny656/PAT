#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, bool> character;
    string a, b;
    getline(cin, a); getline(cin, b);
    for (auto const &ch : a+b) {
        if (!character[ch]) cout << ch;
        character[ch] = true;
    }
    cout << endl;
    return 0;
}