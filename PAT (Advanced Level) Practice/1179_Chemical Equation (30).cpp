#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void parse_input(
	vector<int> &reactants, 
	vector<int> &products,
	unordered_map<int, vector<vector<int>>> &reactions) {

	int n, m, k;
	cin >> n;
	reactants.resize(n);
	for (int i = 0; i < n; ++i) cin >> reactants[i];

	cin >> m;
	products.resize(m);
	// store products in reverse order, to reduce the time of vector::pop_back when searching
	for (int i = 0; i < m; ++i) cin >> products[m-i-1];

	cin >> k;
	string line;
	getline(cin, line); // ignore the newline character after k
	unordered_set<int> ignore_self_products;
	for (int i = 0; i < k; ++i) {
		int reactions_product;
		vector<int> reactions_reactants;

		string part;
		bool next_part_is_product = false;
		getline(cin, line);
		stringstream ss(line);
		// split the line by space, get reactants and product, store in reactions
		while (getline(ss, part, ' ')) {
			if (part == "+") continue;
			else if (part == "->") { next_part_is_product = true; continue; }

			if (next_part_is_product) reactions_product = stoi(part);
			else reactions_reactants.push_back(stoi(part));
		}

		// check if the product is the same as the reactants
		reactions[reactions_product].push_back(reactions_reactants);
		if (reactions_reactants.size() == 1 && *reactions_reactants.begin() == reactions_product)
			ignore_self_products.insert(reactions_product);
	}

	// fill in self reactions if not exist
	for (int i = 0; i < m; i++) {
		int product = products[i];
		if (ignore_self_products.find(product) != ignore_self_products.end()) continue;
		reactions[product].push_back(vector<int>{ product });
	}
}

// backtracking search
void search(
	vector<int> &remain_products,
	unordered_set<int> &remain_reactants,
	unordered_map<int, vector<vector<int>>> &reactions,
	vector<pair<int, vector<int>>> &solution,
	bool &is_found) {
	
	// if found solution, stop searching
	if (is_found) return;

	// if no more products remain, got a solution, set is_found flag
	if (remain_products.empty()) {
		is_found = true;
		return;
	}

	int product = remain_products.back();
	for (auto &reactant_set : reactions[product]) {
		// validation check if the reactants are all in remain_reactants
		bool is_valid_reaction = true;
		for (auto &reactant : reactant_set) {
			if (remain_reactants.find(reactant) == remain_reactants.end()) {
				is_valid_reaction = false;
				break;
			}
		}
		if (!is_valid_reaction) continue;

		// record context
		for (auto &reactant : reactant_set) remain_reactants.erase(reactant);
		remain_products.pop_back();
		solution.push_back({product, reactant_set});

		// search next
		search(remain_products, remain_reactants, reactions, solution, is_found);
		if (is_found) return; // check point for early stop if found solution

		// back
		for (auto &reactant : reactant_set) remain_reactants.insert(reactant);
		remain_products.push_back(product);
		solution.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);

	vector<int> reactants;
	vector<int> products;
	unordered_map<int, vector<vector<int>>> reactions;

	parse_input(reactants, products, reactions);

	// sort reactions by reactants order to find the 1st solution as best solution
	for (auto &reaction : reactions) {
		sort(reaction.second.begin(), reaction.second.end(), [&](const vector<int> &a, const vector<int> &b) {
			for (int j = 0; j < a.size() && j < b.size(); j++) {
				if (a[j] != b[j]) return a[j] < b[j];
			}
		});
	}

	auto r = unordered_set<int>(reactants.begin(), reactants.end());
	vector<pair<int, vector<int>>> solution;
	bool is_find = false;
	search(products, r, reactions, solution, is_find);

	for (auto &s : solution) {
		cout << setfill('0') << setw(2) << s.second[0];
		for (int i = 1; i < s.second.size(); i++) cout << " + " << setfill('0') << setw(2) << s.second[i];
		cout << " -> " << setfill('0') << setw(2) << s.first << endl;
	}

	return 0;
}