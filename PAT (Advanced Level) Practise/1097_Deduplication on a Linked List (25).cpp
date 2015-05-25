#include <bits/stdc++.h>
using namespace std;
// 模拟链表操作，用cnt记录重复数量，isFirst记录是否第一个重复元素
struct node {
    int next;
    int key;
};
int main(int argc, char const *argv[]) {
    unordered_map<int, node> linklist;
    unordered_map<int, int> cnt;
    unordered_map<int, bool> isFirst;
    int head, addr, next;
    int n, key;
    scanf("%d%d", &head, &n);
    while (n--) {
        scanf("%d%d%d", &addr, &key, &next);
        cnt[abs(key)]++;
        linklist[addr] = {next, key};
    }

    int prevAddr = -1;
    int curAddr = head;
    int removeHead = -1;
    int removeCurAddr = -1;
    while (curAddr != -1) {
        int val = abs(linklist[curAddr].key);
        if (cnt[val] > 1) {
            if (!isFirst[val]) {
                isFirst[val] = true;
                prevAddr = curAddr;
                curAddr = linklist[curAddr].next;
            } else {
                if (removeHead == -1) {
                    removeHead = curAddr;
                    removeCurAddr = removeHead;
                } else {
                    linklist[removeCurAddr].next = curAddr;
                    removeCurAddr = curAddr;
                }
                linklist[prevAddr].next = linklist[curAddr].next;
                curAddr = linklist[curAddr].next;
                linklist[removeCurAddr].next = -1;
            }
        } else {
            prevAddr = curAddr;
            curAddr = linklist[curAddr].next;
        }
    }
    while (head != -1) {
        printf("%05d %d", head, linklist[head].key);
        if (linklist[head].next != -1)
            printf(" %05d\n", linklist[head].next);
        else
            printf(" -1\n");
        head = linklist[head].next;
    }
    while (removeHead != -1) {
        printf("%05d %d", removeHead, linklist[removeHead].key);
        if (linklist[removeHead].next != -1)
            printf(" %05d\n", linklist[removeHead].next);
        else
            printf(" -1\n");
        removeHead = linklist[removeHead].next;
    }

    return 0;
}