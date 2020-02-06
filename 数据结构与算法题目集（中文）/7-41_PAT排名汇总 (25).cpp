#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

struct stu
{
    string ID;
    int grade;
}tmpStu;

struct rank_e
{
    string ID;
    int final_rank;
    int local_number;
    int local_rank;
}tmpRank;

vector<stu> localInfo;
vector<stu> allInfo;
vector<rank_e> RankInfo;
map<string , int> Hash;

int cmp1(const stu &a, const stu &b)
{
    return a.grade > b.grade;
}

int cmp2(const rank_e &a, const rank_e &b)
{
    if(a.final_rank == b.final_rank)
        return a.ID < b.ID;
    return a.final_rank < b.final_rank;
}

int main()
{
    int t,group,i,n,curGrade,curRank;
    cin >> group;
    for(t = 1; t <= group; t++)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> tmpStu.ID >> tmpStu.grade;
            localInfo.push_back(tmpStu);
            allInfo.push_back(tmpStu);
            tmpRank.ID = tmpStu.ID;
            tmpRank.local_number = t;
            RankInfo.push_back(tmpRank);
            Hash[tmpRank.ID] = RankInfo.size()-1;
        }

        sort(localInfo.begin(), localInfo.end(), cmp1);
        curGrade = -1;
        curRank = 1;
        for(i = 0; i < localInfo.size(); i++)
        {
            if(curGrade == localInfo[i].grade)
            {
                RankInfo[ Hash[localInfo[i].ID] ].local_rank = RankInfo[ Hash[localInfo[i-1].ID] ].local_rank;
            }
            else
            {
                RankInfo[ Hash[localInfo[i].ID] ].local_rank = curRank;
                curGrade = localInfo[i].grade;
            }
            curRank++;
        }
        localInfo.clear();
    }
    sort(allInfo.begin(), allInfo.end(), cmp1);
    curGrade = -1;
    curRank = 1;
    for(i = 0; i < allInfo.size(); i++)
    {
        if(curGrade == allInfo[i].grade)
        {
            RankInfo[ Hash[allInfo[i].ID] ].final_rank = RankInfo[ Hash[allInfo[i-1].ID] ].final_rank;
        }
        else
        {
            RankInfo[ Hash[allInfo[i].ID] ].final_rank = curRank;
            curGrade = allInfo[i].grade;
        }
        curRank++;
    }
    sort(RankInfo.begin(), RankInfo.end(), cmp2);
    cout << RankInfo.size() << endl;
    for(int i = 0; i < RankInfo.size(); i++)
    {
        cout << RankInfo[i].ID << " "
             << RankInfo[i].final_rank << " "
             << RankInfo[i].local_number << " "
             << RankInfo[i].local_rank << endl;
    }

    return 0;
}