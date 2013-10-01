#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, string> info;

void Register(string user, string pwd)
{
	if(info.find(user) == info.end())
	{
		info[user] = pwd;
		cout << "New: OK" << endl;
	}
	else
	{
		cout << "ERROR: Exist" << endl;
	}
}

void Login(string user, string pwd)
{
	if(info.find(user) == info.end())
	{
		cout << "ERROR: Not Exist" << endl;
	}
	else
	{
		if(info[user] != pwd)
		{
			cout << "ERROR: Wrong PW" << endl;
		}
		else
		{
			cout << "Login: OK" << endl;
		}
	}
}

int main()
{
	int n,i;
	string cmd, user, pwd;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> cmd >> user >> pwd;
		if(cmd == "N")
		{
			Register(user, pwd);
		}
		else if(cmd == "L")
		{
			Login(user, pwd);
		}
	}
	return 0;
}