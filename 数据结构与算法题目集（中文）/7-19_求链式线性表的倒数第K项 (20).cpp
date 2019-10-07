#include <iostream>
using namespace std;

class Node {
public:
    Node *next;
    int data;

    Node(int data):data(data) { }
};

Node* BuildLinkList() {
    int v;
    Node *s = NULL, *tmp = NULL;
    while (scanf("%d", &v) != EOF && v >= 0) {
        Node *node = new Node(v);
        if (tmp == NULL) {
            s = node;
            tmp = node;
        } else {
            tmp->next = node;
            tmp = tmp->next;
        }
    }
    return s;
}

int main() {
    int k;
    scanf("%d", &k);
    auto s = BuildLinkList();
    auto p1 = s, p2 = s;
    while (k != 0 && p1 != NULL) {
        p1 = p1 -> next;
        k--;
    }
    if (k != 0) printf("NULL\n");
    else {
        while (p1 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        printf("%d\n", p2->data);
    }
    return 0;
}