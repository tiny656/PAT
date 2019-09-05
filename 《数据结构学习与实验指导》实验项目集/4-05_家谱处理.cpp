#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;
/*
建树问题 
*/
struct node
{
	string name;
	int dep;
	node *father;
	vector<node*> son;
	node(){};
};

map<string, node*> Hash;

void ConvertToWords(string ask, string words[])
{
	int i,j;
	string tmp = "";
	for(i = 0,j = 0; i < ask.size(); i++)
	{
		if(ask[i] == ' ')
		{
			words[j++] = tmp;
			tmp = "";		
		}
		else	tmp += ask[i];
	}
	if(tmp != "")	words[j++] = tmp;	
}

int main()
{
	string str;
	int n,m,i,cnt,lvl,j;
	node *curNode = NULL;
	cin >> n >> m;
	getchar();
	for(i = 0; i < n; i++)
	{
		getline(cin, str);
		cnt = 0;
		while(str[0] == ' ')
		{
			str = str.substr(1);
			cnt++;	
		}
		
		lvl = cnt >> 1;
		
		if(curNode == NULL)
		{
			curNode = new node();
			curNode->name = str;
			curNode->dep = lvl;
			curNode->father = NULL;
			Hash[ str ] = curNode;
		}
		else
		{
			int c = 0;
			if(lvl <= curNode->dep)
			{
				c = curNode->dep - lvl+1;
				for(j = 0; j < c; j++)
					curNode = curNode->father;
			}
			node *newNode = new node();
			newNode->name = str;
			newNode->father = curNode;
			newNode->dep = lvl;
			Hash[ str ] = newNode;
			curNode->son.push_back(newNode);
			curNode = newNode;					
		}
	}
	string ask;
	for(i = 0; i < m; i++)
	{
		getline(cin, ask);
		string words[6];
		ConvertToWords(ask, words);
		string X = words[0];
		string Y = words[5];
		if(words[3] == "child")
		{
			node *tmpNode = Hash[Y];
			int ok = 0;
			for(j = 0; j < tmpNode->son.size(); j++)
			{
				if(tmpNode->son[j]->name == X)
				{
					ok = 1;
					break;
				}	
			}
			if(ok)	cout << "True" << endl;
			else 	cout << "False" << endl;
		}
		else if(words[3] == "parent")
		{
			node *tmpNode = Hash[Y];
			if( (tmpNode->father != NULL) && (tmpNode->father->name == X) )	
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}
		else if(words[3] == "sibling")
		{
			node *tmpNode1 = Hash[X];
			node *tmpNode2 = Hash[Y];
			if((tmpNode1->father != NULL) && (tmpNode2->father != NULL)
				&& (tmpNode1->father->name == tmpNode2->father->name) )
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}
		else if(words[3] == "descendant")
		{
			node *tmpNode = Hash[X];
			int ok = 0;
			while(tmpNode != NULL)
			{
				if(tmpNode->father != NULL && tmpNode->father->name == Y)
				{
					ok = 1;
					break;
				}
				tmpNode = tmpNode->father;
			}
			if(ok)	cout << "True" << endl;
			else 	cout << "False" << endl;
		}
		else if(words[3] == "ancestor")
		{
			node *tmpNode = Hash[Y];
			int ok = 0;
			while(tmpNode != NULL)
			{
				if(tmpNode->father != NULL && tmpNode->father->name == X)
				{
					ok = 1;
					break;
				}
				tmpNode = tmpNode->father;
			}
			if(ok)	cout << "True" << endl;
			else 	cout << "False" << endl;
		}
	}
	return 0;	
}