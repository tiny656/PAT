#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct cov
{
	string d;
	int k;
};

void Convert(string str, int n, cov &ans)
{
	int i = 0, j;
	while(str[i] == '0' || str[i] == '.')	i++;
	if(i == str.size())
	{
		for(i = 1; i <= n; i++)		ans.d += "0";
		ans.k = 0;
	}
	else
	{
		int pos = i;
		int posDot = str.size();
		for(j = 1; j <= n; )
		{
			if(i != str.size())	
			{
				if(str[i] != '.')//注意不要把.加进去了 
				{
					ans.d += str[i];
					j++;
				}
				i++;
			}
			else
			{
				ans.d += "0";
				j++;
			}
		}
		for(i = 0; i < str.size(); i++)
		{
			if(str[i] == '.')
			{
				posDot = i;
				break;
			}
		}
		if(posDot > pos)	ans.k = posDot-pos;
		else				ans.k = (pos-posDot-1)*-1;
	}
}

int main()
{
	int n;
	string A,B;
	cin >> n >> A >> B;
	cov cvt1,cvt2;
	Convert(A,n,cvt1);
	Convert(B,n,cvt2);
	//cout << "0." << cvt1.d << "*10^" << cvt1.k << endl;
	//cout << "0." << cvt2.d << "*10^" << cvt2.k << endl;
	if(cvt1.d == cvt2.d && cvt1.k== cvt2.k)
		cout << "YES" << " 0." << cvt1.d << "*10^" << cvt1.k << endl;
	else
		cout << "NO" << " 0." << cvt1.d << "*10^" << cvt1.k << " 0." << cvt2.d << "*10^" << cvt2.k << endl;
	return 0;
}