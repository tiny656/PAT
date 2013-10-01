#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int e[1005];
int ans[1005];
int okA,okB,lenA,lenB,len;

struct node
{
    int data;
    node *left;
    node *right;
    node();
    node(const int &val,node *lChild = NULL, node *rChild = NULL);
};

node::node()
{
    left = right = NULL;
}

node::node(const int &val,node *lChild,node *rChild)
{
    data = val;
    left = lChild;
    right = rChild;
}

void fA(node *root,int e[])
{
    if(root != NULL)
    {
        fA(root->left,e);
        e[lenA++] = root->data;
        fA(root->right,e);
    }
}

void fB(node *root,int e[])
{
    if(root != NULL)
    {
        fB(root->right,e);
        e[lenB++] = root->data;
        fB(root->left,e);
    }
}

bool testA(node *root)
{
    int tmp[1005];
    lenA = 0;
    fA(root,tmp);
    for(int i = 0; i < lenA-1; i++)
    {
        if(tmp[i] > tmp[i+1])
        {
            return false;
        }
    }
    return true;
}

bool testB(node *root)
{
    int tmp[1005];
    lenB = 0;
    fB(root,tmp);
    for(int i = 0; i < lenB-1; i++)
    {
        if(tmp[i] > tmp[i+1])
        {
            return false;
        }
    }
    return true;
}

void createA(node* &r,int e[],int preLeft,int preRight)
{
    if(preLeft > preRight)
    {
        r = NULL;
    }
    else
    {
        r = new node(e[preLeft]);
        int mid = preLeft + 1;
        if(mid <= preRight)
        {
            while(e[mid] < e[preLeft])
            {
                mid++;
                if(mid > preRight)
                {
                    mid = preRight+1;
                    break;
                }
            }
            createA(r->left,e,preLeft+1,mid-1);
            createA(r->right,e,mid,preRight);
        }
        else
        {
            r->left = NULL;
            r->right = NULL;
        }
    }
}


void createB(node* &r,int e[],int preLeft,int preRight)
{
    if(preLeft > preRight)
    {
        r = NULL;
    }
    else
    {
        r = new node(e[preLeft]);
        int mid = preLeft + 1;
        if(mid <= preRight)
        {
            while(e[mid] >= e[preLeft])
            {
                mid++;
                if(mid > preRight)
                {
                    mid = preRight+1;
                    break;
                }
            }
            createB(r->left,e,preLeft+1,mid-1);
            createB(r->right,e,mid,preRight);
        }
        else
        {
            r->left = NULL;
            r->right = NULL;
        }
    }
}

void print(node *root)
{
    if(root != NULL)
    {
        print(root->left);
        print(root->right);
        ans[len++] = root->data;
    }
}

int main()
{
    int n,i;
    while(cin >> n)
    {
        node *rootA,*rootB;
        for(i = 0; i < n; i++)
        {
            cin >> e[i];
        }
        createA(rootA,e,0,n-1);
        createB(rootB,e,0,n-1);
        int okA = testA(rootA);
        int okB = testB(rootB);
        len = 0;
        if(okA)
        {
            cout << "YES" << endl;
            print(rootA);
            cout << ans[0];
            for(i = 1; i < len; i++)
            {
                cout << " " << ans[i];
            }
            cout << endl;
        }
        else if(okB)
        {
            cout << "YES" << endl;
            print(rootB);
            cout << ans[0];
            for(i = 1; i < len; i++)
            {
                cout << " " << ans[i];
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}