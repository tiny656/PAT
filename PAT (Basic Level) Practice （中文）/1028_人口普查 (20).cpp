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

class Person {
public:
	char name[20];
	int y, m ,d;
	bool operator<(const Person & other) const {
		if (this->y == other.y) {
			if (this->m == other.m) return this->d < other.d;
			else return this->m < other.m;
		} else return this->y < other.y;
	};
};

vector<Person> personList;

/*

*/
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		Person personIns;
		scanf("%s %d/%d/%d", personIns.name, &personIns.y, &personIns.m, &personIns.d);

		// pay attention to invalid age
		int age = 2014 - personIns.y;
		if (age > 200 || (age == 200 && (personIns.m < 9 || (personIns.m == 9 && personIns.d < 6)))) continue;
		if (age < 0 || (age == 0 && (personIns.m > 9 || (personIns.m == 9 && personIns.d > 6)))) continue;
		
		personList.push_back(personIns);
		
	}
	sort(personList.begin(), personList.end());
	if (personList.size() == 0)
		printf("0\n");
	else
		printf("%d %s %s\n", personList.size(), personList[0].name, personList[personList.size()-1].name);
	return 0;
}