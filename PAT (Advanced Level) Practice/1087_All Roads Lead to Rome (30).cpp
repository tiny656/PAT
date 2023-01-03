#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cctype>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;

const int maxn = 205;
const int INF = 0x3fffffff;
map<string, int> cityID;
vector<pair<string, int>> cityInfo;
vector<pair<int, int>> cityAdjList[maxn]; // adjacent list
vector<int> prevCity[maxn]; // store the prev city of the minimum dist path
int dist[maxn];
bool used[maxn];
int totMinDistPath = 0, endCity;
vector<int> minPathIns;
vector<int> minDistPath[maxn]; // store the minimmum dist paths


void djisktra(int n) {
	// default the city id 0 is the start city
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
		used[i] = false;
	}
	for (int i = 0; i < cityAdjList[0].size(); i++) {
		int curCity = cityAdjList[0][i].first;
		dist[curCity] = cityAdjList[0][i].second;
		prevCity[curCity].push_back(0);
	}
	
	dist[0] = 0;
	used[0] = true;

	for (int i = 1; i < n; i++) {
		// find the minimal distance city from dist[]
		int maxdist = INF;
		int curCity = 0;
		for (int j = 0; j < n; j++) {
			if (!used[j] && dist[j] < maxdist) {
				curCity = j;
				maxdist = dist[j];
			}
		}

		used[curCity] = true;
		// update the dist
		for (int j = 0; j < cityAdjList[curCity].size(); j++) {
			int adjCityID = cityAdjList[curCity][j].first;
			if (!used[adjCityID]) {
				int newdist = dist[curCity] + cityAdjList[curCity][j].second;
				if (newdist <= dist[adjCityID]) {
					if (newdist < dist[adjCityID]) {
						prevCity[adjCityID].clear();
						dist[adjCityID] = newdist;
					}
					prevCity[adjCityID].push_back(curCity);
				}
			}
		}
	}
}


void searchPath(int curCity) {
	// reach start city, end up the the recursion
	if (curCity == 0) {
		for (int i = minPathIns.size()-1; i >= 0; i--)
			minDistPath[totMinDistPath].push_back(minPathIns[i]);
		totMinDistPath++;
		return;
	}

	for (int i = 0; i < prevCity[curCity].size(); i++) {
		int prevCityID = prevCity[curCity][i];
		minPathIns.push_back(prevCityID);
		searchPath(prevCityID);
		minPathIns.pop_back();
	}
}

void printInfo() {
	for (int i = 0; i < cityInfo.size(); i++)
		cout << cityInfo[i].first << " : " << i << endl;
	for (int i = 0; i < cityInfo.size(); i++)
		cout << dist[i] << " " ;
	cout << endl;
	cout << "Total Min path : " << totMinDistPath << endl;
	for (int i = 0; i < totMinDistPath; i++) {
		for (int j = 0; j < minDistPath[i].size(); j++) {
			cout << minDistPath[i][j] << " ";
		}
		cout << endl;
	}
}

void printAns() {

	cout << totMinDistPath;
	if (totMinDistPath >= 1) {
		cout << " " << dist[endCity];
		int maxHappy = -1, printPathID = -1;
		double avgHappy = -1;
		for (int i = 0; i < totMinDistPath; i++) {
			int happyVal = 0;
			for (int j = 0; j < minDistPath[i].size(); j++) {
				int curCityID = minDistPath[i][j];
				happyVal += cityInfo[ curCityID ].second;
			}
			if (maxHappy < happyVal) {
				printPathID = i;
				maxHappy = happyVal;
				avgHappy = (double)happyVal / (double)(minDistPath[i].size()-1);
			}
			else if(maxHappy == happyVal) {
				double curAvgHappy = (double)happyVal / (double)(minDistPath[i].size()-1);
				if (curAvgHappy > avgHappy) {
					printPathID = i;
					avgHappy = curAvgHappy;
				}
			}
		}

		cout << " " << maxHappy << " " << (int)avgHappy << endl;
		for (int i = 0; i < minDistPath[printPathID].size()-1; i++) {
			int curCityID = minDistPath[printPathID][i];
			cout << cityInfo[curCityID].first << "->";
		}
		cout << "ROM" << endl;
	}	
}

int main() {
	int n, k, cityHappy;
	string startCity, cityName;
	cin >> n >> k >> startCity;
	cityID[startCity] = 0;
	cityInfo.push_back(make_pair(startCity, 0));
	for (int i = 1; i < n; i++) {
		cin >> cityName >> cityHappy;
		cityID[cityName] = i;
		if (cityName == "ROM") endCity = i;
		cityInfo.push_back(make_pair(cityName, cityHappy));
	}
	string cityA, cityB;
	int dis;
	for (int i = 0; i < k; i++) {
		cin >> cityA >> cityB >> dis;
		int aID = cityID[cityA];
		int bID = cityID[cityB];
		cityAdjList[aID].push_back(make_pair(bID, dis));
		cityAdjList[bID].push_back(make_pair(aID, dis));
	}

	djisktra(n);

	totMinDistPath = 0;
	minPathIns.push_back(endCity);
	searchPath(endCity);
	minPathIns.pop_back();

	printAns();

	return 0;
}