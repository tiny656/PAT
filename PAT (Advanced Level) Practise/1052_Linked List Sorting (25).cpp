#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct node
{
	int Addr;
	int Key;
	int Next;
}Linkedlist[100000];
vector<node> recorder;

int cmp(const node &a, const node &b)
{
	return a.Key < b.Key;
}

int main()
{
	int n,startHead,i,Addr,Key,Next;
	cin >> n >> startHead;
	if(startHead == -1)	//蛋疼的一个边界数据
	{
		cout << "0 -1" << endl;
		return 0;
	}

	for(i = 0; i < n; i++)
	{
		cin >> Addr >> Key >> Next;
		if(Addr == -1)	continue;
		Linkedlist[Addr].Addr = Addr;
		Linkedlist[Addr].Key = Key;
		Linkedlist[Addr].Next = Next;
	}
	int cur = startHead;
	while(cur != -1)//踢出非头链表地址所能到达节点
	{
		recorder.push_back(Linkedlist[cur]);
		cur =  Linkedlist[cur].Next;
	}
	sort(recorder.begin(), recorder.end(), cmp);
	printf("%d %05d\n", recorder.size(), recorder[0].Addr);
	for(i = 0; i < recorder.size()-1; i++)
	{
		printf("%05d %d %05d\n", recorder[i].Addr, recorder[i].Key, recorder[i+1].Addr);
	}
	printf("%05d %d -1\n", recorder[recorder.size()-1].Addr, recorder[recorder.size()-1].Key);
	return 0;
}