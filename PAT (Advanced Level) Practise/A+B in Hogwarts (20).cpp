#include <iostream>
#include <cstring>
using namespace std;

struct magic
{
	int A,B,C;
}Hog1,Hog2,Hog3;

int main()
{
	scanf("%d.%d.%d %d.%d.%d", &Hog1.A,&Hog1.B,&Hog1.C,&Hog2.A,&Hog2.B,&Hog2.C);
	int cnt = 0;
	Hog3.C = (Hog1.C + Hog2.C + cnt) % 29;
	cnt    = (Hog1.C + Hog2.C + cnt) / 29;
	Hog3.B = (Hog1.B + Hog2.B + cnt) % 17;
	cnt    = (Hog1.B + Hog2.B + cnt) / 17;
	Hog3.A = Hog1.A + Hog2.A + cnt;
	printf("%d.%d.%d\n",Hog3.A,Hog3.B,Hog3.C);
	return 0;
}