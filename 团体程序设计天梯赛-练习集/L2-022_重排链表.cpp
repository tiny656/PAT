#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data;
	int next;
};

vector<Node> nodes(10e5, Node{0, -1});

void PrintLinkList(int addr) {
	while (addr != -1) {
		printf("%05d %d ", addr, nodes[addr].data);
		if (nodes[addr].next == -1) printf("-1\n");
		else printf("%05d\n", nodes[addr].next);
		addr = nodes[addr].next;
	}
}

// addr2 means iterator from left to right
// addr1 means iterator from right to left
void DFS(int addr1, int &addr2, int &newHead, bool &isOk) {

	if (addr1 == -1) return;

	Node &n1 = nodes[addr1];

	// use recursive way to visit link list in reverse order
	DFS(n1.next, addr2, newHead, isOk);

	// if  already hit exit point
	if (isOk) return;

	// case for only one node or node Ln
	if (n1.next == -1) {
		if (addr1 != addr2) n1.next = addr2;
		newHead = addr1;
		return;
	}

	// case for even number of nodes
	if (addr1 == addr2) {
		nodes[addr1].next = -1;
		isOk = true;
		return;
	}

	// case for odd number of nodes
	if (nodes[addr2].next == addr1) {
		nodes[addr1].next = -1;
		isOk = true;
		return;
	}


	// swap nodes, like L1->Ln-1->L2, then move L1 to next L2
	Node &n2 = nodes[addr2];
	n1.next = n2.next;
	n2.next = addr1;
	addr2 = n1.next;
}



int main() {
	int startNode, n, addr, data, next;
	scanf("%d %d", &startNode, &n);
	for (int i = 0; i < n; i++) {
		cin >> addr >> data >> next;
		nodes[addr] = Node{data, next};
	}

	int newHead = -1;
	bool isOk = false;
	DFS(startNode, startNode, newHead, isOk);
	PrintLinkList(newHead);

	return 0;
}