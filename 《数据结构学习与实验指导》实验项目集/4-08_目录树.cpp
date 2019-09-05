#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
建树 以及 map的使用 
*/
struct node 
{
	int dep;
	map<string, node*> file;
	map<string, node*> content;
	node()
	{
		dep = 0;
	};
}*root;

void work(string str)
{
	node *curNode = root;
	string tmp = "";
	int i;
	for (i = 0; i < str.size(); i++)
	{
		if ( str[i] == '\\')
		{
			if (curNode->content[tmp] == NULL)
			{
				node *tmpNode = new node();
				tmpNode->dep = curNode->dep+1;
				curNode->content[tmp] = tmpNode;
				curNode = tmpNode;	
			}
			else
			{
				curNode = curNode->content[tmp];
			}
			tmp = "";					
		}
		else	tmp += str[i];
	}
	if (tmp != "")
	{
		if (curNode->file[tmp] == NULL)
		{
			node *tmpNode = new node();
			tmpNode->dep = curNode->dep+1;
			curNode->file[tmp] = tmpNode;
			curNode = tmpNode;	
		}
		else
		{
			curNode = curNode->file[tmp];
		}
	}
}

void printSpace(int n)
{
	while(n--)	cout << " ";
}


void dfs(node *curNode)
{
	if(curNode == NULL)	return;
	
	map<string , node*>::iterator iter1,iter2;
	for(iter1 = curNode->content.begin(); iter1 != curNode->content.end(); iter1++)
	{
		printSpace(curNode->dep * 2 + 2);
		cout << iter1->first << endl;
		dfs(iter1->second);	
	}
	for(iter2 = curNode->file.begin(); iter2 != curNode->file.end(); iter2++)
	{
		printSpace(curNode->dep * 2 + 2);
		cout << iter2->first << endl;
	}
}


int main()
{
	int n,i;
	string str;
	
	root = new node();
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> str;	
		work(str);
	}
	cout << "root" << endl;
	dfs(root);
	return 0;
}