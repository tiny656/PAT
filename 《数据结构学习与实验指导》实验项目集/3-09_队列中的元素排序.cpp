#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Queue
{
public:
	queue<int> q;
	void Sort();
	void Print();
	void AddQ(int item);
};

void Queue::AddQ(int item)
{
	q.push(item);
}

void Queue::Sort()
{
	queue<int> q2;
	int len = q.size();
	while(len > 0) 
	{
 		int min = q.front();
 		q.pop();
        int turn = len - 1;//需要比较次数 
        while(turn > 0) 
		{
            int value = q.front();
            q.pop();
            if(value < min) 
			{
                q.push(min);
                min = value;
            } 
			else
			{
				q.push(value);
            }
			turn--;
        }
        len--;
        q2.push(min);
	}
	while(!q2.empty())
	{
		AddQ(q2.front());
		q2.pop();
	}
}

void Queue::Print()
{
	if(q.size() > 0)
	{
		printf("%d", q.front());
		q.pop();
		while(!q.empty())
		{
			printf(" %d", q.front());
			q.pop();
		} 
		printf("\n");
	} 
	else
	{
		printf("\n");
	}
}

int main()
{
	Queue q;
	int n,i,e;
	vector<int> v;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &e);
		//q.AddQ(e);	
		v.push_back(e);
	}
	sort(v.begin(),v.end());
	if(v.size() > 0)
	{
		printf("%d", v[0]);
		for(i = 1; i < v.size(); i++)
			printf(" %d", v[i]);
		printf("\n");
	} 
	else
	{
		printf("\n");
	}
	//q.Sort();
	//q.Print();
	return 0;
}


