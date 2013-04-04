#include <iostream>
#include <string>
#include <vector>
using namespace std;

class stu
{
public:
    int grade;
    string name;
    string sex;
    string course;
    stu& operator = (const stu &a);
}tmp,Max,Min;

stu& stu::operator = (const stu &a)
{
    this->course = a.course;
    this->name = a.name;
    this->sex = a.sex;
    this->grade = a.grade;
    return *this;
}

int abs(int a)  {return a<0?-a:a;}

int main()
{
    int i,n;
    vector<stu> boy,girl;
    while(cin >> n)
    {
        boy.clear();    girl.clear();
        for(i = 0; i < n; i++)
        {
            cin >> tmp.name >> tmp.sex >> tmp.course >> tmp.grade;
            if(tmp.sex == "F")  girl.push_back(tmp);
            else boy.push_back(tmp);
        }
        int limitMax = -1, limitMin = 105;
        for(i = 0; i < girl.size(); i++)
        {
            if(girl[i].grade > limitMax)
            {
                limitMax = girl[i].grade;
                Max = girl[i];
            }
        }
        for(i = 0; i < boy.size(); i++)
        {
            if(boy[i].grade < limitMin)
            {
                limitMin = boy[i].grade;
                Min = boy[i];
            }
        }
        int ok = 1;
        if(limitMax == -1)
        {
            ok = 0;
            cout << "Absent" << endl;
        }
        else
        {
            cout << Max.name << " " << Max.course << endl;
        }

        if(limitMin == 105)
        {
            ok = 0;
            cout << "Absent" << endl;
        }
        else
        {
            cout << Min.name << " " << Min.course << endl;
        }
        if(ok)  cout << abs(Max.grade-Min.grade) << endl;
        else    cout << "NA" << endl;
    }
    return 0;
}
