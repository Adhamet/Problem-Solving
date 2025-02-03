#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int dr[] = {-1, 0, 1, 0};
	const int dc[] = {0, -1, 0, 1};
	int n, m, k;
	cin >> n >> m >> k;

	auto valid = [&](int r, int c) { return r >= 0 && r < n && c >= 0 && c < m; };

	set<array<int, 2>> lit;
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	for (int i = 0, x, y; i < k; ++i) {
		cin >> x >> y;
		x--, y--;
		lit.insert({x,y});
	}

	queue<array<int, 5>> q;
	q.push({0, 0, 0, -1, -1});
	vis[0][0] = true;

	int ans = INT_MAX;
	while (!q.empty()) {
		int x = q.front()[0], y = q.front()[1], cost = q.front()[2];
		int currLitRow = q.front()[3], currLitCol = q.front()[4];
		
		q.pop();
		if (x == n - 1 && y == m - 1) {
			ans = min(ans, cost);
			continue;
		}

		if (!lit.count({x, y})) continue;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dr[i], ny = y + dc[i];

			if (valid(nx,ny) && !vis[nx][ny]) {
				if (lit.count({nx, ny}) || currLitRow == nx || currLitCol == ny) {
					vis[nx][ny] = true;
					q.push({nx, ny, cost, currLitRow, currLitCol});
				} else {
					vis[nx][ny] = true;
					q.push({nx, ny, cost + 1, x+dr[i], -1});
					q.push({nx, ny, cost + 1, -1, y+dc[i]});
				}
			}
		}
	}

	return cout << (ans == INT_MAX? -1: ans), 0;
}
