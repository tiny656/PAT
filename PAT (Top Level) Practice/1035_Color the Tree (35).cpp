#include <bits/stdc++.h>
using namespace std;

enum C { RED, BLACK };
// (color, black height)
using P = pair<C, int>;

struct Node
{
    int v;
    Node *l = nullptr;
    Node *r = nullptr;
};


Node *build(const vector<int> &post, int l, int r) {
    if (l > r) return nullptr;
    int rootVal = post[r], p = l;
    while (p < r && post[p] < rootVal) ++p;
    Node *n = new Node{rootVal};
    n->l = build(post, l, p - 1);
    n->r = build(post, p, r - 1);
    return n;
}

vector<P> dfs(Node* n){
    if (!n) return {{BLACK, 1}};
    vector<P> L = dfs(n->l), R = dfs(n->r);
    // stateCode: color<<8 | blackHeight
    unordered_set<int> s;
    for (auto [c1, b1] : L)
        for (auto [c2, b2] : R)
            if (b1 == b2) {
                // parent can set black
                s.insert((BLACK<<8)|(b1+1));
                // parent can set red
                if(c1==BLACK && c2==BLACK) s.insert((RED<<8)|b1);
            }
    vector<P> res;
    for (int x : s) res.push_back({C(x >> 8), x & 255});
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    int K;
    cin >> K;
    while (K--) {
        int N;
        cin >> N;
        vector<int> post(N);
        for (int &x : post) cin >> x;
        Node *root = build(post, 0, N - 1);
        auto st = dfs(root);
        bool ok = any_of(st.begin(), st.end(), [&](const P &p) { return p.first == BLACK; });
        cout << (ok ? "Yes" : "No") << endl;
    }

    return 0;
}