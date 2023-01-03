#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int pic[1005][1005];
unordered_map<int, int> color_count;

int main() {
	int m, n, tol;
	scanf("%d%d%d", &m, &n, &tol);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &pic[i][j]);
			color_count[pic[i][j]] += 1;
		}
	}
	int count = 0;
	int posx = -1, posy = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool ok = true;
			if (color_count[pic[i][j]] != 1) continue;
			for (int k = 0; k < 8; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 0 && nx  < n && ny >= 0 && ny < m && abs(pic[i][j] - pic[nx][ny]) <= tol) {
					ok = false;
					break;
				}
			}
			if (ok) {
				count += 1;
				posx = i; posy = j;
			}
		}
	}
	if (count == 0)
		printf("Not Exist\n");
	else if (count > 1) 
		printf("Not Unique\n");
	else 
		printf("(%d, %d): %d\n", posy+1, posx+1, pic[posx][posy]); 

	return 0;
}
