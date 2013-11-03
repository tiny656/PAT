#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;
/*
hoffman树，权值最优二叉树 ，哈夫曼树 
*/


priority_queue<int,vector<int>, greater<int> > pq; 

int main()
{
	int n,i,e,ans = 0;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> e;		
		pq.push(e);
	}
	while(pq.size() != 1)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		ans += first+second;
		pq.push(first+second);
	}
	cout << ans << endl;
	return 0;
}