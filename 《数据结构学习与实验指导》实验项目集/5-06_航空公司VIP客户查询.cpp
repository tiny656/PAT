#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
/*
BKDRHash链式hash 
*/
struct info
{
	char ID[18];
	int m;
};

vector<info> Hash[105971];

// BKDR Hash Function
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }
    return (hash % 105971);
}

void Add(char *ID, int mile)
{
	unsigned int hashNum = BKDRHash(ID);
	int find = 0,i;
	for(i = 0; i < Hash[hashNum].size(); i++)
	{
		if(!strcmp(Hash[hashNum][i].ID, ID))
		{
			Hash[hashNum][i].m += mile;
			find = 1;
			break;
		}
	}
	if(!find)
	{
		info tmpInfo;
		strcpy(tmpInfo.ID, ID);
		tmpInfo.m = mile;
		Hash[hashNum].push_back(tmpInfo);
	}
}

bool Find(char *ID,int &mile)
{
	int hashNum = BKDRHash(ID);
	int find = 0, i;
	for(i = 0; i < Hash[hashNum].size(); i++)
	{
		if(!strcmp(Hash[hashNum][i].ID,ID) )
		{
			find = 1;
			mile = Hash[hashNum][i].m;
			break;
		}
	}
	if(!find)	return false;
	else 		return true;
}

int main()
{
	int n,k;
	char ID[18];
	int mile;
	scanf("%d %d", &n, &k);
	while(n--)
	{
		scanf("%s %d", &ID[0], &mile);
		if(mile < k)
		{
			Add(ID, k);
		}
		else
		{
			Add(ID, mile);
		}
	}
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", &ID[0]);
		if(Find(ID,mile))
			printf("%d\n",mile);
		else
			printf("No Info\n");
	}
	return 0;
}

