#coding: utf-8
import sys
sys.setrecursionlimit(2000)

# python 递归深度1000会跪，error: 返回非零
# 搜索二叉树的插入操作

class TreeNode(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree(object):

    def __init__(self, n):
        self.root = None
        self.max_dep = 0
        self.level_nodes = [0]*n

    def add(self, node, data, dep):
        self.max_dep = max(self.max_dep, dep)
        if node is None:
            node = TreeNode(data)
            self.level_nodes[dep] += 1
        elif data <= node.data:
            node.left = self.add(node.left, data, dep+1)
        else:
            node.right = self.add(node.right, data, dep+1)
        return node


n = int(raw_input())
data = map(int, raw_input().split())
bst = BinarySearchTree(n)
for d in data:
    bst.root = bst.add(bst.root, d, 0)
low_cnt = bst.level_nodes[bst.max_dep]
abo_cnt = 0 if bst.max_dep-1 < 0 else bst.level_nodes[bst.max_dep-1]
print '%d + %d = %d' % (low_cnt, abo_cnt, low_cnt+abo_cnt)
