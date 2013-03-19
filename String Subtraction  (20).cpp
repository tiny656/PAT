#include <iostream>
#include <cstring>
using namespace std;

int flag['z'+1];
char str[10005],sub[10005];
int main()
{
	int i;
	gets(str);	gets(sub);
	memset(flag, 0, sizeof(flag));
	int len1 =  strlen(sub);
	for(i = 0; i < len1; i++)	flag[sub[i]] = 1;
	int len2 = strlen(str);
	for(i = 0; i < len2; i++)
	{
		if(!flag[str[i]])
		{
			printf("%c", str[i]);
		}
	}
	puts("");
	return 0;
}