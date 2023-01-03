#include <iostream>
#include <iomanip>
using namespace std;

class Record {
public:
	int id;
	int dis;
} Rookie{ -1, -1 }, Champion{ -1, 0x7fffffff };


int main() {
	int n, id, x, y, dis;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id >> x >> y;
		dis = x * x + y * y;
		if (dis < Champion.dis) {
			Champion.dis = dis;
			Champion.id = id;
		}
		if (dis > Rookie.dis) {
			Rookie.dis = dis;
			Rookie.id = id;
		}
	}
	cout << setfill('0') << setw(4) << Champion.id << " " << setfill('0') << setw(4) << Rookie.id << endl;
	return 0;
}