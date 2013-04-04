#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct stu
{
    char ID[10];
    char name[10];
    int grade;
}tmp;

vector<stu> Student;

int cmp1(const stu &a, const stu &b)
{
    return strcmp(a.ID, b.ID) < 0;
}

int cmp2(const stu &a, const stu &b)
{
    if(!strcmp(a.name, b.name))
        return strcmp(a.ID, b.ID) < 0;
    return strcmp(a.name, b.name) < 0;
}

int cmp3(const stu &a, const stu &b)
{
    if(a.grade == b.grade)
        return strcmp(a.ID, b.ID) < 0;
    return a.grade < b.grade;
}

int main()
{
    int n,select;
    scanf("%d %d", &n, &select);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %s %d", tmp.ID, tmp.name, &tmp.grade);
        Student.push_back(tmp);
    }
    switch(select)
    {
        case 1: sort(Student.begin(), Student.end(), cmp1); break;
        case 2: sort(Student.begin(), Student.end(), cmp2); break;
        case 3: sort(Student.begin(), Student.end(), cmp3); break;
    }
    for(vector<stu>::iterator iter = Student.begin(); iter != Student.end(); iter++)
        printf("%s %s %d\n", iter->ID, iter->name, iter->grade);
    return 0;
}
