#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Person {
	int id, fatherId, motherId;
	string gender;

	Person():fatherId(-1), motherId(-1) {}
};

void Search(int id , unordered_map<int, Person> &persons, int count, unordered_set<int> &generation) {
	if (count == 0) return;
	generation.insert(id);
	Person p = persons[id];
	if (p.fatherId != -1)  Search(p.fatherId, persons, count-1, generation);
	if (p.motherId != -1) Search(p.motherId, persons, count-1, generation);
}

bool HasIntersection(const unordered_set<int> &s1, const unordered_set<int> &s2) {
	for (auto it = s1.begin(); it != s1.end(); it++) {
		if (s2.find(*it) != s2.end()) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	int n, k, id1, id2;
	string gender;
	unordered_map<int, Person> persons;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Person p;
		cin >> p.id >> p.gender >> p.fatherId >> p.motherId;
		persons[p.id] = p;
		// important check!!!
		persons[p.fatherId].gender = "M";
		persons[p.motherId].gender = "F";
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> id1 >> id2;

		if (persons[id1].gender == persons[id2].gender) cout << "Never Mind" << endl;
		else {
			unordered_set<int> generationOfP1, generationOfP2;
			Search(id1, persons, 5, generationOfP1);
			Search(id2, persons, 5, generationOfP2);
			bool hasIntersection = HasIntersection(generationOfP1, generationOfP2);

			if (!hasIntersection) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}