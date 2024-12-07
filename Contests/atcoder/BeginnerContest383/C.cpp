#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define fst first
#define scd second
#define el '\n'

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int h, w, d;
	cin >> h >> w >> d;
	vector<string> grid(h);
	for (int i = 0; i < h; i++) cin >> grid[i];

	vector<vector<bool>> vis(h, vector<bool>(w, false));
	queue<pair<int, pair<int, int>>> q; // (dist, (i, j))
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == 'H') {
				q.push({0, {i, j}});
				vis[i][j] = true;
			}
		}
	}

	int ans = 0;
	while (!q.empty()) {
		auto node = q.front();
		int dist = node.fst;
		int x = node.scd.first, y = node.scd.scd;
		q.pop();

		ans += 1;
		if (dist < d) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && grid[nx][ny] != '#') {
					vis[nx][ny] = true;
					q.push({dist + 1, {nx, ny}});
				}
			}
		}
	}

	return cout << ans, 0;
}
