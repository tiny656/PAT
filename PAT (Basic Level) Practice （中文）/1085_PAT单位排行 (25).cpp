#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Record {
public:
	string univ;

	void update(int select, int score) {
		level[select].first += score;
		level[select].second += 1;
	}

	int studentNum() const {
		return level[0].second + level[1].second + level[2].second;
	}

	int weightScore() const {
		return int(double(level[0].first) / 1.5
			+ double(level[1].first)
			+ double(level[2].first) * 1.5);
	}

	bool operator< (const Record &o) {
		if (o.weightScore() == this->weightScore()) {
			if (o.studentNum() == this->studentNum())
				return this->univ < o.univ;
			else return this->studentNum() < o.studentNum();
		}
		else return this->weightScore() > o.weightScore();
	}

private:
	pair<int, int> level[3]; // basic, advance, top
};

int main() {
	int n, score, select, curRank;
	string id, univ;
	unordered_map<string, int> rankIndex;
	vector<Record> rankTable;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id >> score >> univ;
		transform(univ.begin(), univ.end(), univ.begin(), ::tolower);
		select = id[0] == 'B' ? 0 : (id[0] == 'A' ? 1 : 2);
		if (rankIndex.find(univ) == rankIndex.end()) {
			Record r = Record();
			r.univ = univ;
			r.update(select, score);
			rankTable.push_back(r);
			rankIndex[univ] = rankTable.size() - 1;
		} else { 
			rankTable[rankIndex[univ]].update(select, score);
		}
	}
	sort(rankTable.begin(), rankTable.end());
	cout << rankTable.size() << endl;
	for (int i = 0; i < rankTable.size(); i++) {
		if (i == 0) {
			cout << "1";
			curRank = 1;
		} else if (rankTable[i].weightScore() == rankTable[i - 1].weightScore())
			cout << curRank;
		else {
			cout << i + 1;
			curRank = i + 1;
		}
		cout << " " << rankTable[i].univ << " " << rankTable[i].weightScore() << " " << rankTable[i].studentNum() << endl;
	}

	return 0;
}