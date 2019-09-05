#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <map>
using namespace std;

struct node
{
    string ID;
    node *child[1024];
    int len;
    node(string id);
};

node::node(string id)
{
    ID = id;
    memset(child,NULL,sizeof(child));
}

int ans[1024];

int main()
{
    int n,m,i,j,k;
    string ID,tmpID;

    map<string, node*> hash;//hash各个结点


    while(cin >> n >> m)
    {
        hash.clear();
        for(i = 0; i < m; i++)
        {
            cin >> ID >> k;

            node *cur;
            if(hash.count(ID))
            {
                cur = hash[ID];
            }
            else
            {
                cur = new node(ID);
                cur->len = 0;
                hash[ID] = cur;
            }

            for(j = 0; j < k; j++)
            {
                cin >> tmpID;
                if(hash.count(tmpID))
                {
                    cur->child[cur->len] = hash[tmpID];
                    cur->len++;
                }
                else
                {
                    cur->child[cur->len] = new node(tmpID);
                    hash[tmpID] = cur->child[cur->len];
                    (cur->child[cur->len])->len = 0;
                    cur->len++;
                }
            }
        }

        if(n == 1)    {cout << "1" << endl; continue;}
        //cout << "Begin " << endl;
        queue<node*> q;

        q.push(hash["01"]);

        int ansLen = 0;
        memset(ans,0,sizeof(ans));
        int tmp = 0, limit = 1, cnt = 0;

        while(!q.empty())
        {
            node *cur = q.front();
            q.pop();
            tmp++;
            //cout << cur->ID  << " " << cur->len << endl;
            for(i = 0; i < cur->len; i++)
            {
                if(cur->child[i] == NULL)
                {
                    ans[ansLen] += 1;
                }
                else
                {
                    cnt++;
                    q.push(cur->child[i]);
                }
            }

            if(cur->len == 0)
            {
                ans[ansLen] += 1;
            }

            if(tmp == limit)
            {
                tmp = 0;
                limit = cnt;
                cnt = 0;
                ansLen++;
            }
        }
        for(i = 0; i < ansLen - 1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << ans[i] << endl;
    }
    return 0;
}
