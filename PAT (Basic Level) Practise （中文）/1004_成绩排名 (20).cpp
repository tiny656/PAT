#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
struct stu
{
  string name;
  int grade;
  string course;
  void setStu(string Name, string Course, int Grade)
  {
    name = Name;
    course = Course;
    grade = Grade;
  };
}high,low,tmp;

int main()
{
  int n,i;
  cin >> n;
  high.setStu("","",-100);
  low.setStu("","",200);
  for(i = 0; i < n; i++)
  {
    cin >> tmp.name >> tmp.course >> tmp.grade;
    if(tmp.grade > high.grade)
    {
      high.setStu(tmp.name, tmp.course, tmp.grade);
    }
    if(tmp.grade < low.grade)
    {
      low.setStu(tmp.name, tmp.course, tmp.grade);
    }
  }
  cout << high.name << " " << high.course << endl;
  cout << low.name << " " << low.course << endl;
  return 0;
}