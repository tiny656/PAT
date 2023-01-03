#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_map>
using namespace std;
// 搜索+简单剪枝，从后向前枚举是否是狼人，当枚举狼人达到要求，判断其他限制满足即为答案
class WolfGame {
public:
    int total, numberOfWolf, numberOfLiar;
    int actualNumberOfLiar;
    vector<int> assume;
    vector<vector<int>> id;
    vector<int> wolfIndex;
    vector<int> ans;
    vector<bool> isWolf;
    bool findAnswer;

    WolfGame(int n, int w, int l):total(n), numberOfWolf(w), numberOfLiar(l) { 
        this->assume.resize(n+1);
        this->id.resize(n+1);
        this->isWolf.resize(n+1);
        this->actualNumberOfLiar = 0;
        this->findAnswer = false;
    }

    void PrintAnswer() {
        if (this->findAnswer) {
            cout << this->ans[0];
            for (int i = 1; i < this->ans.size(); i++)
                cout << " " << this->ans[i];
            cout << endl;
        } else cout << "No Solution" << endl;
    }

    void Search(int idx) {
        if (this->findAnswer) return;
        if (this->actualNumberOfLiar > this->numberOfLiar) return; 
        if (this->wolfIndex.size() == this->numberOfWolf) {
            int lieWolf = 0, liarNumber = 0;
            for (int i = 1; i <= this->total; i++) {
                int cId = this->assume[i];
                if ((cId > 0 && this->isWolf[abs(cId)]) || (cId < 0 && !this->isWolf[abs(cId)])) {
                    lieWolf += this->isWolf[i] ? 1 : 0;
                    liarNumber += 1;
                }
            }
            if (lieWolf > 0 && lieWolf < this->numberOfWolf && liarNumber == this->numberOfLiar) {
                this->findAnswer = true;
                for (const auto &x :this->wolfIndex) ans.push_back(x);
            }
            return;
        }

        for (int i = 0; i < 2 && idx > 0; i++) { // 0 wolf, 1 not wolf
            if (i == 0) {
                this->isWolf[idx] = true;
                this->wolfIndex.push_back(idx);
            }
            int sym = (i == 0) ? 1 : -1;
            int tmp = this->actualNumberOfLiar;
            for (const auto &x : this->id[idx]) {
                this->actualNumberOfLiar += x*sym > 0 ? 1 : 0;
            }
            this->Search(idx-1);
            if (i == 0) {
                this->isWolf[idx] = false;
                this->wolfIndex.pop_back();
            }
            this->actualNumberOfLiar = tmp;
        }
    }
};

int main() {
    int n, w, l;
    cin >> n >> w >> l;
    WolfGame *g = new WolfGame(n, w, l);
    for (int i = 1; i <= n; i++) {
        cin >> g->assume[i];
        int sym = g->assume[i] > 0 ? 1 : -1;
        g->id[g->assume[i]*sym].push_back(sym*i);
    }

    g->Search(g->total);
    g->PrintAnswer();

    return 0;
} 
