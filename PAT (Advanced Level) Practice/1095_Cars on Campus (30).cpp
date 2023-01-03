#include <bits/stdc++.h>
using namespace std;
/*
模拟，lambda表达式的a.time <= b.time就是段错误，
读入所有记录排序，去掉非法记录同时计算maxTime
遍历合法记录，与query time比较，得到车辆数量
 */
struct RecordItem {
    string plate;
    int time;
    int status; // 0:out
}recordItem;
vector<RecordItem> recordList;
vector<int> queryTime;
unordered_map<string, tuple<int, int, int>> carStatus; // tuple: 时间 序号，状态

int main(int argc, char const *argv[]) {
    int n, q, h, m, s;
    char plateStr[10], status[5];
    string line;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %s", plateStr, &h, &m, &s, status);
        recordItem.plate = plateStr;
        recordItem.time = h*60*60+m*60+s;
        recordItem.status = (status[0] == 'i') ? 1 : 0;
        recordList.push_back(recordItem);
        carStatus[recordItem.plate] = make_tuple(-1, -1, -1); // 初始状态
    }
    sort(recordList.begin(), recordList.end(),  [](const RecordItem &a, const RecordItem &b){return a.time < b.time;});
    for (int i = 0; i < q; i++) {
        scanf("%d:%d:%d", &h, &m, &s);
        queryTime.push_back(h*60*60+m*60+s);
    }
    int maxTime = 0;
    unordered_map<string, int> parkTime;
    unordered_map<int, bool> removeItem;
    for (int i = 0; i < recordList.size(); i++) {
        const RecordItem &item = recordList[i];
        string plate = item.plate;
        if (get<2>(carStatus[plate]) == -1) {
            // 不存在
            if (item.status == 1) {
                get<0>(carStatus[plate]) = item.time;
                get<1>(carStatus[plate]) = i;
                get<2>(carStatus[plate]) = 1;
            }
            else removeItem[i] = true;
        } else {
            // 存在
            if (item.status == 1) {
                if (get<1>(carStatus[plate]) != -1)
                    removeItem[get<1>(carStatus[plate])] = true;
                get<0>(carStatus[plate]) = item.time;
                get<1>(carStatus[plate]) = i;
            } else {
                int diff = item.time - get<0>(carStatus[plate]);
                if (parkTime.find(plate) == parkTime.end()) parkTime[plate] = diff;
                else parkTime[plate] += diff;
                maxTime = max(maxTime, parkTime[plate]);
                get<0>(carStatus[plate]) = -1;
                get<1>(carStatus[plate]) = -1;
                get<2>(carStatus[plate]) = -1;
            }
        }
    }
    // 没有出去的收尾清理,因为要配对
    for (auto it = carStatus.begin(); it != carStatus.end(); it++) {
        if (get<2>(it->second) != -1 && get<1>(it->second) != -1) removeItem[get<1>(it->second)] = true;
    }
    int queryIt = 0, cnt = 0;
    for (int i = 0; i < recordList.size(); i++) {
        if ((removeItem.find(i) == removeItem.end()) || (removeItem[i] == false) ) {
            while (queryIt < queryTime.size() && recordList[i].time > queryTime[queryIt]) {
                printf("%d\n", cnt);
                queryIt++;
            }
            if (recordList[i].status == 1) cnt++;
            else cnt--;
        }
    }
    for (int i = queryIt; i < queryTime.size(); i++) printf("%d\n", cnt);
    // get max time car
    vector<string> maxRecordList;
    for (auto it = parkTime.begin(); it != parkTime.end(); it++) {
        if (it->second == maxTime)
            maxRecordList.push_back(it->first);
    }
    sort(maxRecordList.begin(), maxRecordList.end());
    for (int i = 0; i < maxRecordList.size(); i++)
        cout << maxRecordList[i] << " ";
    printf("%02d:%02d:%02d\n", maxTime/60/60, maxTime/60%60, maxTime%60);
    return 0;
}
/*
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
*/
/*
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09 26409
*/