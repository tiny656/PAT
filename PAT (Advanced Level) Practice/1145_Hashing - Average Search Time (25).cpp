#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// build prime table
class PrimeTable {
public:
	PrimeTable() {
		vector<bool> isPrime(maxn, true);
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i < maxn; i++) {
			if (!isPrime[i]) continue;
			for (int j = i + i; j < maxn; j += i) {
				isPrime[j] = false;
			}
		}
		for (int i = 0; i < isPrime.size(); i++) {
			if (isPrime[i]) prime.push_back(i);
		}
	}

	int findLargePrime(int n) {
		 return *(lower_bound(prime.begin(), prime.end(), n));
	}

private:
	const int maxn = 100004;
	vector<int> prime;
};

class HashTable {
public:
	HashTable(int key) {
		this->key = key;
		this->table.resize(key, -1);
	}

	// quadrtic probing
	// h = ((val % key) + di) % key
	// key: table size
	// di:0*0, 1*1, 2*2, 3*3, ..., i*i; i <= table size
	bool insert(int val) {
		for (int i = 0; i < this->table.size(); i++) {
			int h = (val % this->key + i * i) % this->key;
			if (this->table[h] == -1) {
				this->table[h] = val;
				return true;
			}
		}
		return false;
	}

	// similar method with insert
	int searchCount(int val) {
		int cnt = 0;
		for (int i = 0; i < this->table.size(); i++) {
			cnt++;
			int h = (val % this->key + i * i) % this->key;
			if (this->table[h] == -1 || this->table[h] == val) {
				return cnt;
			}
		}
		cnt += 1;
		return cnt;
	}

private:
	vector<int> table;
	int key;
};

int main() {
	int mSize, n, m, e;
	cin >> mSize >> n >> m;
	PrimeTable pt;
	mSize = pt.findLargePrime(mSize);
	HashTable ht(mSize);
	for (int i = 0; i < n; i++) {
		cin >> e;
		if (!ht.insert(e)) cout << e << " cannot be inserted." << endl;
	}
	int searchCnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> e;
		searchCnt += ht.searchCount(e);
	}
	cout << setiosflags(ios::fixed) << setprecision(1) << searchCnt / (double)m << endl;
	return 0;
}

