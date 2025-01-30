#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int dx[] = {0, 0, 1, -1};
	const int dy[] = {1, -1, 0, 0};
	
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> grid(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> grid[i][j];
			}
		}

		vector<vector<bool>> vis(n, vector<bool>(m, false));
		priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
					pq.push({grid[i][j], i, j});
					vis[i][j] = true;
				}
			}
		}

		int volume = 0, mxHeight = 0;
		while (!pq.empty()) {
			int h = pq.top()[0];
			int x = pq.top()[1];
			int y = pq.top()[2];
			pq.pop();

			mxHeight = max(mxHeight, h);
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
					vis[nx][ny] = true;
					if (grid[nx][ny] < mxHeight) volume += mxHeight - grid[nx][ny];
					pq.push({grid[nx][ny], nx, ny});
				}
			}
		}

		cout << volume << el;
	}
	
	return 0;
}
