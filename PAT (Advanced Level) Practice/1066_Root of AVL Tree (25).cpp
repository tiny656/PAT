#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:66777216")
#include <algorithm>
#include <string>
#include <complex>
#include <cassert>
#include <memory>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <deque>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <bitset>
using namespace std;
 
#if defined(_MSC_VER) || defined(__BORLANDC__)
    typedef unsigned __int64 uint64;
    typedef signed __int64 int64;
#else
    typedef unsigned long long uint64;
    typedef signed long long int64;
#endif
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef pair<int64,int64> PLL;
typedef vector<int64> VL;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pdd pair<double,double>
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define REP(i,n) FOR(i,1,(n))
#define REPT(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define IOS ios::sync_with_stdio(false)
 
const double pi = 3.1415926535897932384626433832795028841971;
const double EPS = 1E-9;
const int64 INF64 = (int64)1E18;
const int INF = 1000000000;
 
static inline bool get(int &v)
{
    int s = 1, c;
    while(!isdigit(c = getchar())&&c != '-')
    {
        if(c == EOF)
            break ;
    }
    if(c == EOF) return 0;
    if(c == '-') s = 0 , v = 0;
    else v = c^48;
    for(;isdigit(c = getchar());v = (v << 1) + (v << 3) + (c ^ 48));
    v = (s ? v : -v);
    return 1 ;
}
/*
AVLTree
四种操作
*/
class TreeNode
{
	public:
		TreeNode():lson(NULL),rson(NULL),height(0){}
		int val;
		int height;
		TreeNode *lson, *rson;
};


class AVLTree
{
	private:
		
		TreeNode *root;
		
		TreeNode* SingRotateLeft(TreeNode *&k2);//LL情况下旋转
		TreeNode* SingRotateRight(TreeNode *&k2);//RR情况下旋转
		TreeNode* DoubleRotateLR(TreeNode *&k3);//LR
		TreeNode* DoubleRotateRL(TreeNode *&k3);//RL
		void InsertNode(TreeNode *&node, int val);
		int Height(TreeNode *node);
	public:

		AVLTree():root(NULL){}
		void insert(int val);
		int GetRootVal();

};

int AVLTree::Height(TreeNode *node)
{
	if (node != NULL)	return node->height;
	return -1;
}

int AVLTree::GetRootVal()
{
	return root->val;
}

void AVLTree::insert(int val)
{
	InsertNode(root, val);
}


TreeNode* AVLTree::SingRotateLeft(TreeNode *&k2)
{
	TreeNode *k1;
	k1 = k2->lson;
	k2->lson = k1->rson;
	k1->rson = k2;

	k2->height = max(Height(k2->lson), Height(k2->rson))+1;
	k1->height = max(Height(k1->lson), Height(k1->rson))+1;
	
	if (root == k2)
		root = k1;
	return k1;
}

TreeNode* AVLTree::SingRotateRight(TreeNode *&k2)
{
	TreeNode *k1;
	k1 = k2->rson;
	k2->rson = k1->lson;
	k1->lson = k2;

	k2->height = max(Height(k2->lson), Height(k2->rson))+1;
	k1->height = max(Height(k1->lson), Height(k1->rson))+1;

	if (root == k2)
		root = k1;
	return k1;
}

TreeNode* AVLTree::DoubleRotateLR(TreeNode *&k3)
{
    k3->lson = SingRotateRight(k3->lson);
    return SingRotateLeft(k3);
}

TreeNode* AVLTree::DoubleRotateRL(TreeNode *&k3)
{
	k3->rson = SingRotateLeft(k3->rson);
    return SingRotateRight(k3);
}

void AVLTree::InsertNode(TreeNode *&node, int val)
{
	if (node == NULL)
	{
		node = new TreeNode();
		node->val = val;
		if (NULL == root)	root = node;
		return ;
	}

	if (node->val > val)//插入到左子树
	{
		InsertNode(node->lson, val);
		if (2 == Height(node->lson) - Height(node->rson))
		{
			if (val < node->lson->val)	node = SingRotateLeft(node);
			else						node = DoubleRotateLR(node);
		}
	}
	else if (node->val < val)//插入到右子树
	{
		InsertNode(node->rson, val);
		if (2 == Height(node->rson) - Height(node->lson))
		{
			if (val > node->rson->val)	node = SingRotateRight(node);
			else						node = DoubleRotateRL(node);
		}
	}
	node->height = max(Height(node->lson), Height(node->rson))+1;
}


void run()
{
	int n,e;
	get(n);
	AVLTree *tree = new AVLTree();
	FOR(i, 1, n)
	{
		get(e);
		tree->insert(e);
	}
	printf("%d\n", tree->GetRootVal());
}
 
 
int main()
{
#ifdef __DEBUG__
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st = clock();
#endif
    run();
#ifdef __DEBUG__
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}
