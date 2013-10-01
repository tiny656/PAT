http://blog.csdn.net/Hackbuteer1/article/details/7584838
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
using namespace std;

int A[100005],B[100005];

int findMidNum(int A[], int B[], int len)
{
	if(len == 1)			return A[0] > B[0] ? B[0] : A[0]; 
	int mid = (len-1) / 2;
	if(A[mid] == B[mid])		return A[mid];
	else if(A[mid] < B[mid])	return findMidNum(&A[len-mid-1], &B[0], mid+1);
	else					return findMidNum(&A[0], &B[len-mid-1], mid+1);
}
int main()
{
	int n,i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d", &B[i]);
	}
	int ans = findMidNum(A, B, n);
	cout << ans << endl;
	return 0;
}