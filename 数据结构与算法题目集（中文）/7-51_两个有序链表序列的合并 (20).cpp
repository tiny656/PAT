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
    while (scanf("%d", &v) == 1 && v != -1) {
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

Node* MergeLinkList(Node *s1, Node *s2) {
    Node *s3 = NULL, *tmp = NULL, *node;
    while (s1 != NULL || s2 != NULL) {
        if (s1 == NULL) {
            node = new Node(s2->data);
            s2 = s2->next;
        } else if (s2 == NULL) {
            node = new Node(s1->data);
            s1 = s1->next;
        } else if (s1->data < s2->data) {
            node = new Node(s1->data);
            s1 = s1->next;
        } else {
            node = new Node(s2->data);
            s2 = s2->next;
        }

        if (tmp == NULL) {
            s3 = node;
            tmp = node;
        } else {
            tmp->next = node;
            tmp = tmp->next;
        }
    }

    return s3;
}

int main() {
    auto s1 = BuildLinkList();
    auto s2 = BuildLinkList();
    auto s3 = MergeLinkList(s1, s2);
    bool firstPrint = true;
    if (s3 == NULL) printf("NULL\n");
    else {
        while (s3 != NULL) {
            if (firstPrint) {
                printf("%d", s3->data);
                firstPrint = false;
            } else {
                printf(" %d", s3->data);
            }
            s3 = s3->next;
        }
        printf("\n");
    }
    return 0;
}