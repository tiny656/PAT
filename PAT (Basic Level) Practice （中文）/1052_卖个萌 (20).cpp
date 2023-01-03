#include <bits/stdc++.h>
using namespace std;

/*
注意字符串的处理
*/

vector<string> hand, eye, mouth;

void analyseEmoji(const string &emojiStr, vector<string> &part) {
    bool flag = false;
    string content = "";
    for (int i = 0; i < emojiStr.size(); i++) {
        char ch = emojiStr[i];
        if (ch == ' ') continue;
        if (ch == '[' || ch == ']') {
            flag = !flag;
            if (content != "") part.push_back(content);
            content = "";
        }
        else {
            if(flag) content += ch;
        }
    }
}

int main() {
    string handStr, eyeStr, mouthStr;

    getline(cin, handStr);
    getline(cin, eyeStr);
    getline(cin, mouthStr);

    analyseEmoji(handStr, hand);
    analyseEmoji(eyeStr, eye);
    analyseEmoji(mouthStr, mouth);
    int k, id[5];
    cin >> k;
    while (k--) {
        for (int i = 0; i < 5; i++) cin >> id[i];
        if (0 < id[0] && id[0] <= hand.size()
            && 0 < id[4] && id[4] <= hand.size()
            && 0 < id[1] && id[1] <= eye.size()
            && 0 < id[3] && id[3] <= eye.size()
            && 0 < id[2] && id[2] <= mouth.size()) {
            cout << hand[id[0]-1] << "(" << eye[id[1]-1] << mouth[id[2]-1] << eye[id[3]-1] << ")" << hand[id[4]-1] << endl;
        } else cout << "Are you kidding me? @\\/@" << endl;
    }
    return 0;
}

/*
[╮][╭][o][~\][/~][<][>]
[╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
*/