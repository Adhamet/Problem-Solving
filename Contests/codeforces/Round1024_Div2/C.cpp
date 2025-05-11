#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define pii pair<int,int>
#define el '\n'

const int dr[] = {0, 1, 0, -1}; // right, down, left, up
const int dc[] = {1, 0, -1, 0};
int n;

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pii> spiral;

		int x, y;
		if (n%2==0) x=y=(n/2)-1;
		else x=y=(n/2);
		spiral.push_back({x,y});

		int currdir = 0, step = 1;
		while ((int)spiral.size() < n*n) {
			for (int i = 0; i < 2; ++i) { // dir
				int nx = x, ny = y;
				for (int j = 0; j < step; ++j) {
					nx += dr[currdir], ny += dc[currdir];
					spiral.push_back({nx, ny});
				}

				x = nx, y = ny;
				currdir = (currdir + 1) % 4;
			}
			step += 1;
		}

		while ((int)spiral.size() >= n*n) spiral.pop_back();

		int grid[n][n];
		for (int i = 0; i < n*n; ++i) {
			int x = spiral[i].first;
			int y = spiral[i].second;
			grid[x][y] = i;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) { cout << grid[i][j] << ' '; }
			cout << el;
		}
	}

	return 0;
}
