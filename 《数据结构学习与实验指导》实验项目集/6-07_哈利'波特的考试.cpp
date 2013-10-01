#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 100000;
int matrix[1005][1005];
int HengMax[1005];
int ShuMin[1005];
int main()
{
	int n,m,i,j,k,a,b,sp;
	cin >> n >> m;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			matrix[i][j] = maxn;
		}
		matrix[i][i] = 0;
	}
	for(i = 1; i <= m; i++)
	{
		cin >> a >> b >> sp;
		matrix[a][b] = matrix[b][a] = sp;
	}
	
	for(k = 1; k <= n; k++)
	for(i = 1; i <= n; i++)
	for(j = 1; j <= n; j++)
	{
		if(matrix[i][j] > matrix[i][k] + matrix[k][j])
		{
			matrix[i][j] = 	matrix[i][k] + matrix[k][j];
		}
	}
	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(matrix[i][j] == maxn)
			{
				cout << "0" << endl; 
				return 0;
			}
		}	 
	}
	
	for(i = 1; i <= n; i++)
	{
		int tmp = -1;
		for(j = 1; j <= n; j++)
		{
			if(i == j) continue;
			tmp = max(tmp, matrix[i][j]);
		}
		HengMax[i] = tmp;
	}
	for(j = 1; j <= n; j++)
	{
		int tmp = 0x7fffffff;
		for(i = 1; i <= n; i++)
		{
			if(i == j) continue;
			tmp = min(tmp, matrix[i][j]);
		}
		ShuMin[j] = tmp;
	}
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(matrix[i][j] == ShuMin[j] && matrix[i][j] == HengMax[i] && i != j)
			{
				cout << i << " " << matrix[i][j] << endl;
				return 0;
			}
		}
	}
	if(n == 1)	cout << "1" << endl;
	else	cout << "0" << endl;
	return 0;
}