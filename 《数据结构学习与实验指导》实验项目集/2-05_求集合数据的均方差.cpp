#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;


vector<double> elem;

int main()
{
	int n,i;
	double e,tot = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%lf", &e);
		tot += e;
		elem.push_back(e);
	}
	double avg = tot / n;
	double tmp = 0.0;
	for(i = 0; i < n; i++)
	{
		tmp += (elem[i]-avg)*(elem[i]-avg);
	}
	printf("%.5lf\n", sqrt(tmp/n)); 
	return 0;
}