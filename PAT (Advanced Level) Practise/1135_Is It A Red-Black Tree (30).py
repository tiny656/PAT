#coding: utf-8

# 1. 每一个节点非红即黑
# 2. 根是黑色
# 3. 每一个NULL的叶子节点是黑色
# 4. 如果一个节点是红色，那么孩子是黑色
# 5. 从任一节点到其每个叶子的所有简单路径都包含相同数目的黑色节点

class NodeColor:
    RED = 0
    BLACK = 1

    @staticmethod
    def getNodeColor(data):
        return NodeColor.BLACK if data >= 0 else NodeColor.RED

class Node(object):
    def __init__(self, data, color, parent=None, left=None, right=None):
        self.color = color
        self.parent = parent
        self.left = left
        self.right = right
        self.data = data

class Tree(object):
    def __init__(self, root):
        self.root = root
        self.firstBlackNumOfPath = None

    def insert(self, newNode, node):
        if newNode.data < node.data:
            if node.left is None:
                node.left = newNode
                newNode.parent = node
            else:
                self.insert(newNode, node.left)
        else:
            if node.right is None:
                node.right = newNode
                newNode.parent = node
            else:
                self.insert(newNode, node.right)

    # 中序遍历，用于调试
    def printInOrder(self, node):
        if node is None: return
        self.printPreOrder(node.left)
        print node.data, node.color
        self.printPreOrder(node.right)

    def isRootBlack(self):
        return self.root.color == NodeColor.BLACK

    # 是否红色节点的子节点都是黑色
    def isRedNodeChildBlack(self, root):
        if root is None: return True
        result = True
        if root.color == NodeColor.RED:
            result = ((root.left is None) or (root.left.color == NodeColor.BLACK)) \
                and ((root.right is None) or (root.right.color == NodeColor.BLACK))
        return result and self.isRedNodeChildBlack(root.left) and self.isRedNodeChildBlack(root.right)

    # 是否满足条件5
    def isBlackNumEq(self, node, curBlackNum):
        if node is None:
            if self.firstBlackNumOfPath is None:
                self.firstBlackNumOfPath = curBlackNum + 1
            return self.firstBlackNumOfPath == curBlackNum + 1

        # dfs + 回溯，记录根节点到NULL子节点的黑色节点数量
        if node.color == NodeColor.BLACK:
            curBlackNum += 1

        result = True
        result &= self.isBlackNumEq(node.left, curBlackNum)
        result &= self.isBlackNumEq(node.right, curBlackNum)

        if node.color == NodeColor.BLACK:
            curBlackNum -= 1
        return result


    def isRedBlackTree(self):
        return self.isRootBlack() \
            and self.isRedNodeChildBlack(self.root) \
            and self.isBlackNumEq(self.root, 0)

k = int(raw_input())
for i in xrange(k):
    n = int(raw_input())
    nodes = map(int, raw_input().split())
    tree = Tree(Node(abs(nodes[0]), NodeColor.getNodeColor(nodes[0])))
    for node in nodes[1:]:
        tree.insert(Node(abs(node), NodeColor.getNodeColor(node)), tree.root)
    # tree.printPreOrder(tree.root)
    print '%s' % 'Yes' if tree.isRedBlackTree() else 'No'
