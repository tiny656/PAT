#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<string,set<string> > note;
vector<string> vec;
void StringSplit(string s,char splitchar,vector<string>& vec)
{
    if(vec.size()>0)//保证vec是空的
       vec.clear();
    int length = s.length();
    int start=0;
    for(int i=0;i<length;i++)
    {
       if(s[i] == splitchar && i == 0)//第一个就遇到分割符
       {
           start += 1;
       }
       else if(s[i] == splitchar)
       {
           vec.push_back(s.substr(start,i - start));
           start = i+1;
       }
       else if(i == length-1)//到达尾部
       {
           vec.push_back(s.substr(start,i+1 - start));
       }
    }
}

int main()
{
    int n,i,j;
    int no;
    string ID,title,author,keywords,publiser,year;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        cin >> ID;
        getchar();
        getline(cin, title, '\n');
        //cout << title << endl;
        note[title].insert(ID);

        getline(cin, author, '\n');
        note[author].insert(ID);

        getline(cin, keywords, '\n');
        StringSplit(keywords,' ',vec);
        for(int j = 0; j < vec.size(); j++)
            note[vec[j]].insert(ID);

        getline(cin, publiser, '\n');
        note[publiser].insert(ID);

        getline(cin, year, '\n');
        note[year].insert(ID);
    }

    string ask;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d: ", &no);
        getline(cin, ask,'\n');
        cout << no << ": " << ask << endl;
        if(!note.count(ask))
        {
            puts("Not Found");
        }
        else
        {
            for(set<string>::iterator iter = note[ask].begin(); iter != note[ask].end(); iter++)
            {
                cout << *iter << endl;
            }
        }
    }
    return 0;
}
