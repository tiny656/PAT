/*
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct stu
{
    string ID;
    int C,M,E,A;
}tmp;

int cmpC(const stu &a, const stu &b)
{
    return a.C > b.C;
}

int cmpM(const stu &a, const stu &b)
{
    return a.M > b.M;
}

int cmpE(const stu &a, const stu &b)
{
    return a.E > b.E;
}

int cmpA(const stu &a, const stu &b)
{
    return a.A > b.A;
}

vector<stu> Log;
map<string, int> Rank;
map<string, string> From;

int main()
{
    int n,k,i;
    while(cin >> n >> k)
    {
        Log.clear();
        Rank.clear();
        From.clear();
        for(i = 0; i < n; i++)
        {
            cin >> tmp.ID >> tmp.C >> tmp.M >> tmp.E;
            tmp.A = (tmp.C + tmp.M + tmp.E)/3;
            Log.push_back(tmp);
        }

        int score = -1;
        int rank = 0;
        sort(Log.begin(), Log.end(), cmpA);

        for(i = 0; i < Log.size(); i++)
        {
            if(Log[i].A != score)
            {
                rank = i+1;
            }
            score = Log[i].A;
            Rank[Log[i].ID] = rank;
            From[Log[i].ID] = 'A';
        }

        score = -1;
        rank = 0;
        sort(Log.begin(), Log.end(), cmpC);
        for(i = 0; i < Log.size(); i++)
        {
            if(Log[i].C != score)
            {
                rank = i+1;
            }
            score= Log[i].C;

            if(Rank[Log[i].ID] > rank)
            {
                Rank[Log[i].ID] = rank;
                From[Log[i].ID] = 'C';
            }

        }

        score = -1;
        rank = 0;
        sort(Log.begin(), Log.end(), cmpM);
        for(i = 0; i < Log.size(); i++)
        {
            if(Log[i].M != score)
            {
                rank = i+1;
            }
            score= Log[i].M;

            if(Rank[Log[i].ID] > rank)
            {
                Rank[Log[i].ID] = rank;
                From[Log[i].ID] = 'M';
            }
        }

        score = -1;
        rank = 0;
        sort(Log.begin(), Log.end(), cmpE);
        for(i = 0; i < Log.size(); i++)
        {
            if(Log[i].E != score)
            {
                rank = i+1;
            }
            score= Log[i].E;

            if(Rank[Log[i].ID] > rank)
            {
                Rank[Log[i].ID] = rank;
                From[Log[i].ID] = 'E';
            }

        }

        string queryID;
        for(i = 0; i < k; i++)
        {
            cin >> queryID;
            if(!Rank.count(queryID))
                cout << "N/A" << endl;
            else
                cout << Rank[queryID] << " " << From[queryID] << endl;
        }
    }
    return 0;
}

*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu
{
    string ID;
    int C,M,E,A;
}tmp;

int cmpC(const stu &a, const stu &b)
{
    return a.C > b.C;
}

int cmpM(const stu &a, const stu &b)
{
    return a.M > b.M;
}

int cmpE(const stu &a, const stu &b)
{
    return a.E > b.E;
}

int cmpA(const stu &a, const stu &b)
{
    return a.A > b.A;
}

vector<stu> rankC,rankM,rankE,rankA;

void query(string ID)
{
    string from = "";
    int bestRank = 50000, i;
    for(i = 0; i < rankA.size(); i++)
    {
        if(ID == rankA[i].ID)
        {
            int curGrade = rankA[i].A;
            while(curGrade == rankA[i].A)
            {
                i--;
            }
            if(i+2 < bestRank)
            {
                bestRank = i+2;
                from = "A";
            }
            break;
        }
    }
    for(i = 0; i < rankC.size(); i++)
    {
        if(ID == rankC[i].ID)
        {
            int curGrade = rankC[i].C;
            while(curGrade == rankC[i].C)
            {
                i--;
            }
            if(i+2 < bestRank)
            {
                bestRank = i+2;
                from = "C";
            }
            break;
        }
    }
    for(i = 0; i < rankM.size(); i++)
    {
        if(ID == rankM[i].ID)
        {
            int curGrade = rankM[i].M;
            while(curGrade == rankM[i].M)
            {
                i--;
            }
            if(i+2 < bestRank)
            {
                bestRank = i+2;
                from = "M";
            }
            break;
        }
    }
    for(i = 0; i < rankE.size(); i++)
    {
        if(ID == rankE[i].ID)
        {
            int curGrade = rankE[i].E;
            while(curGrade == rankE[i].E)
            {
                i--;
            }
            if(i+2 < bestRank)
            {
                bestRank = i+2;
                from = "E";
            }
            break;
        }
    }

    if(bestRank == 50000)  cout << "N/A" << endl;
    else                cout << bestRank << " " << from << endl;
}

int main()
{
    int n,k,i;
    while(cin >> n >> k)
    {
        rankC.clear();
        rankM.clear();
        rankE.clear();
        rankA.clear();
        for(i = 0; i < n; i++)
        {
            cin >> tmp.ID >> tmp.C >> tmp.M >> tmp.E;
            tmp.A = (tmp.C + tmp.M + tmp.E)/3;
            rankC.push_back(tmp);
            rankM.push_back(tmp);
            rankE.push_back(tmp);
            rankA.push_back(tmp);
        }
        stable_sort(rankC.begin(), rankC.end(), cmpC);
        stable_sort(rankM.begin(), rankM.end(), cmpM);
        stable_sort(rankE.begin(), rankE.end(), cmpE);
        stable_sort(rankA.begin(), rankA.end(), cmpA);

        string queryID;
        for(i = 0; i < k; i++)
        {
            cin >> queryID;
            query(queryID);
        }
    }
    return 0;
}

