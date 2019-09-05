#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
/*
1.通过寻找入度为0的点寻找根
2.通过BFS判断最小堆性质
3.通过中序遍历判断二叉排序树性质 
*/

struct node
{
	int k1,k2;
	int left,right;
}tree[1005];

int in[1005];//入度 
vector<int> ans;
bool Judge1(int cur)
{
	queue<int> q;
	q.push(cur);
	while ( !q.empty() )
	{
		int ok = 1;
		int cur = q.front();
		q.pop();	
		//cout << tree[cur].k1 << " " << tree[cur].k2 << endl;
		//if(tree[cur].left != -1) 	cout << tree[tree[cur].left].k1 << " " << tree[tree[cur].left].k2 << endl;
		//if(tree[cur].right != -1)	cout << tree[tree[cur].right].k1 << " " << tree[tree[cur].right].k2 << endl;
		//cout << endl << endl;
		if (tree[cur].left != -1 && (tree[tree[cur].left].k1 >= tree[cur].k1 || tree[tree[cur].left].k2 <= tree[cur].k2))		ok = 0;
		if (tree[cur].right != -1 && (tree[tree[cur].right].k1 <= tree[cur].k1 || tree[tree[cur].right].k2 <= tree[cur].k2)) 	ok = 0;
		if (!ok)	return false;
		//加入左右孩子
		if (tree[cur].left != -1)	q.push(tree[cur].left); 
		if (tree[cur].right != -1)	q.push(tree[cur].right);
	}
	return true;
}

void Vis(int cur)
{
	if(cur != -1)
	{
		Vis(tree[cur].left);
		ans.push_back(tree[cur].k1);
		Vis(tree[cur].right);
	}
}


int main()
{
	int n,i,k1,k2,l,r,root;
	while (cin >> n)
	{
		memset(in, 0, sizeof(in));
		ans.clear();
		for (i = 0; i < n; i++)
		{
			cin >> k1 >> k2 >> l >> r;
			tree[i].k1 = k1;
			tree[i].k2 = k2;
			tree[i].left = l;
			tree[i].right = r;
			//cout << i << " " << tree[i].k1 << " " << tree[i].k2 << endl;
			in[l]++; in[r]++; 
		}
		root = -1;
		for (i = 0; i < n; i++)	
		{	if(!in[i])
			{
				root = i;
				break;
			}
		}
		
		int ok = Judge1(root);
		if ( root == -1 || !ok )
		{
			ok = 0;
		}
		else
		{
			Vis(root);
			for (i = 0; i < ans.size()-1; i++)
			{
				if(ans[i] >= ans[i+1])
				{
					ok = 0;
					break;
				}
			}
		}
		if(ok)	puts("YES");
		else	puts("NO");
	}	
	return 0;
}