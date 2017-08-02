#coding: utf-8 
 
# 中序遍历 
 
def inorder_traverse(node): 
    global ans 
    if node == -1: return 
    lchild = node_dict[node[1]] if node[1] in node_dict else -1 
    rchild = node_dict[node[2]] if node[2] in node_dict else -1 
    if lchild == -1 and rchild == -1: 
        ans += node[0] 
    else: 
        ans += '(' 
        inorder_traverse(lchild) 
        ans += node[0] 
        inorder_traverse(rchild) 
        ans += ')' 
 
n = int(raw_input()) 
tot = n*(n+1) / 2 
node_dict = {} 
 
for i in xrange(n): 
    data, left, right = raw_input().split() 
    left, right = int(left), int(right) 
    if left != -1: tot -= left 
    if right != -1: tot -= right 
    node_dict[i+1] = (data, left, right) 
 
root_id, ans = tot, '' 
inorder_traverse(node_dict[root_id]) 
if ans.startswith('('):
    print ans[1:-1]
else:
    print ans 
