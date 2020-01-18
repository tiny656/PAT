#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

enum NodeType {
    File,
    Directory
};

class Node {
public:
    NodeType type;
    string name;
    vector<Node*> subFiles;
    vector<Node*> subDirectories;

    Node(NodeType type, string name) {
        this->type = type;
        this->name = name;
    }

    // Build directory tree in recursive
    void Build(string path) {
        if (path.size() <= 0) return;
        string::size_type pos = path.find('\\');
        if (pos == path.npos) {
            this->TryAdd(File, path);
        } else if (pos == path.size()-1) {
            this->TryAdd(Directory, path.substr(0, pos));
        } else {
            string dirName = path.substr(0, pos);
            string left = path.substr(pos+1, path.size() - pos);
            Node* newNode = this->TryAdd(Directory, dirName);
            newNode->Build(left);
        }
    }

    // Try add node, check if node exists or not, return itself or new node
    Node* TryAdd(NodeType type, string name) {
        vector<Node*> &vec = type == File ? this->subFiles : this->subDirectories;
        for (Node* &node : vec) {
            if (node->name == name) return node;
        }
        Node* newNode = new Node(type, name);
        vec.push_back(newNode);
        return newNode;
    }

    // Print directory tree, before print sub nodes, sort them first
    void Print(int depth) {
        for(int i = 0; i < depth; i++) cout << "  ";
        cout << this->name << endl;
        auto cmp = [&](Node* a, Node* &b) { return a->name < b->name; };
        sort(this->subDirectories.begin(), this->subDirectories.end(), cmp);
        sort(this->subFiles.begin(), this->subFiles.end(), cmp);
        for (const auto &dir : this->subDirectories) dir->Print(depth+1);
        for (const auto &file : this->subFiles) file->Print(depth+1);
    }
};

int main() {
    int n;
    string s;
    Node* root = new Node(Directory, "root");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        root->Build(s);
    }
    root->Print(0);

    return 0;
}