#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Student {
public :
	int id;
	int GE, GI, GALL;
	int prefer[10];
	int rank;
	int go;
};

vector<Student> student_info;
vector<int> ans[105];
int quato[105];

bool cmp( const Student &a, const Student &b ) {
	if ( a.GALL == b.GALL )
		return a.GE > b.GE;
	else
		return a.GALL > b.GALL;
}

int main() {
	int n, m, k, i, j;
	cin >> n >> m >> k;

	for ( i = 0; i < m; i++ )
		cin >> quato[i];

	Student instance_stu;

	for ( i = 0; i < n; i++ ) {
		instance_stu.id = i;
		memset( instance_stu.prefer, 0, sizeof( instance_stu.prefer ) );
		cin >> instance_stu.GE >> instance_stu.GI;
		instance_stu.GALL = instance_stu.GE + instance_stu.GI;

		for ( j = 0; j < k; j++ )
			cin >> instance_stu.prefer[j];

		student_info.push_back( instance_stu );
	}

	sort( student_info.begin(), student_info.end(), cmp );
	int before_admit = -1;

	for ( i = 0; i < student_info.size(); i++ ) {
		for ( j = 0; j < k; j++ ) {
			int prefer = student_info[i].prefer[j];
			//1.有配额直接admit
			//2.没有配额判断排序后前一个人的和自己排名是否相同，然后是否admit一样学校
			if ( quato[prefer] > 0 ||
			        ( before_admit == prefer
			          && student_info[i].GALL == student_info[i - 1].GALL
			          && student_info[i].GE == student_info[i - 1].GE ) ) {
				before_admit = prefer;
				quato[prefer]--;
				ans[prefer].push_back( student_info[i].id );
				break;
			}
		}
	}

	for ( i = 0; i < m; i++ ) {
		if ( ans[i].empty() )
			cout << endl;
		else {
			sort( ans[i].begin(), ans[i].end() );
			cout << ans[i][0];

			for ( j = 1; j < ans[i].size(); j++ )
				cout << " " << ans[i][j];

			cout << endl;
		}
	}

	return 0;
}