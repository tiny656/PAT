#coding: utf-8
import Queue

# AVL树构造 + 完全二叉树判断(如果某一个节点子节点为空，后序再遇到非空子节点，则为非完全二叉树, 注意左子节点空，右子节点存在情况)


class TreeNode(object):

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.height = 0

class AVLTree(object):

    def __init__(self, n):
        self.size = n
        self.root = None

    def height(self, node):
        return 0 if node is None else node.height

    def insert(self, node, data):
        if node is None:
            node = TreeNode(data)
        elif data < node.data:
            node.left = self.insert(node.left, data)
            if self.height(node.left) - self.height(node.right) == 2:
                if data < node.left.data:
                    node = self.left_left_rotation(node)
                else:
                    node = self.left_right_rotation(node)
        elif data > node.data:
            node.right = self.insert(node.right, data)
            if self.height(node.right) - self.height(node.left) == 2:
                if data > node.right.data:
                    node = self.right_right_rotation(node)
                else:
                    node = self.right_left_rotation(node)
        node.height = max(self.height(node.left), self.height(node.right)) + 1
        return node

    def left_left_rotation(self, node):
        tmp = node.left
        node.left = tmp.right
        tmp.right = node
        node.height = max(self.height(node.left), self.height(node.right)) + 1
        tmp.height = max(self.height(tmp.left), self.height(node)) + 1
        return tmp


    def right_right_rotation(self, node):
        tmp = node.right
        node.right = tmp.left
        tmp.left = node
        node.height = max(self.height(node.left), self.height(node.right)) + 1
        tmp.height = max(self.height(tmp.right), self.height(node)) + 1
        return tmp

    def left_right_rotation(self, node):
        node.left = self.right_right_rotation(node.left)
        return self.left_left_rotation(node)

    def right_left_rotation(self, node):
        node.right = self.left_left_rotation(node.right)
        return self.right_right_rotation(node)

    def levelOrder(self):
        flag = False
        is_complete, ans = True, []
        q = Queue.Queue(maxsize=self.size)
        q.put(self.root)
        while not q.empty():
            c = q.get()
            ans.append(str(c.data))

            if c.left:
                if flag: is_complete = False
                q.put(c.left)
            else: flag = True

            if c.right:
                if flag: is_complete = False
                q.put(c.right)
            else: flag = True

        print ' '.join(ans)
        print 'YES' if is_complete else 'NO'

n = int(raw_input())
datas = map(int, raw_input().split())
avl_tree = AVLTree(n)
for data in datas:
    avl_tree.root = avl_tree.insert(avl_tree.root, data)
avl_tree.levelOrder()
