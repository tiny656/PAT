#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cctype>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;

class Command {
public:
	string op;
	int val;
}cmd_ins;

class Node {
public:
	Node *left;
	Node *right;
	int val;
} *root, *nodelist[40];

vector<Command> cmdList;
vector<int> postTravelArr;
stack<int> st;

void postTravel(Node *root) {
	if (root->left != NULL)
		postTravel(root->left);
	if (root->right != NULL)
		postTravel(root->right);
	postTravelArr.push_back(root->val);
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 2*n; i++) {
		cin >> cmd_ins.op;
		if (cmd_ins.op == "Push") {
			cin >> cmd_ins.val;
			st.push(cmd_ins.val);
		} else {
			cmd_ins.val = st.top();
			st.pop();
		}
		cmdList.push_back(cmd_ins);
		nodelist[cmd_ins.val] = new Node;
		nodelist[cmd_ins.val]->left = NULL;
		nodelist[cmd_ins.val]->right = NULL;
		nodelist[cmd_ins.val]->val = cmd_ins.val;
	}

	root = nodelist[cmdList[0].val];

	for (int i = 1; i < cmdList.size(); i++) {
		// attach much attention to Push operation
		// when two successive Push operation i-1 and i means Node i-1's left child is Node i
		// when one operation is Pop, and another operation is Push, so operation i-1 Pop and i Push means, Node i-1's right child is Node i 
		if (cmdList[i].op == "Push") {
			if (cmdList[i-1].op == "Push") nodelist[cmdList[i-1].val]->left = nodelist[cmdList[i].val];
			else nodelist[cmdList[i-1].val]->right = nodelist[cmdList[i].val];
		}
	}

	postTravel(root);
	cout << postTravelArr[0];
	for (int i = 1; i< postTravelArr.size(); i++) {
		cout << " " << postTravelArr[i];
	}
	cout << endl;
	return 0;
}