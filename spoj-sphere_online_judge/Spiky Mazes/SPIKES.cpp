#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int oo = 1e9;
	const int dx[] = {-1, 1, 0, 0};
	const int dy[] = {0, 0, -1, 1};
	int n, m, j;
	cin >> n >> m >> j;
	array<int, 2> entrance = {-1,-1};
	array<int, 2> treasure = {-1,-1};
	vector<string> maze(n);
	for (int i = 0; i < n; ++i) {
		cin >> maze[i];
		for (int k = 0; k < m; ++k) {
			if (maze[i][k] == '@') entrance = {i,k};
			else if (maze[i][k] == 'x') treasure = {i,k};
		}
	}

	vector<vector<int>> spikesSoFar(n, vector<int>(m, oo));
	queue<array<int, 3>> q;
	q.push({entrance[0], entrance[1], 0});
	spikesSoFar[entrance[0]][entrance[1]] = 0;

	while (!q.empty()) {
		int x = q.front()[0], y = q.front()[1], spikes = q.front()[2];
		q.pop();

		if (x == treasure[0] && y == treasure[1] && spikes <= j / 2) {
			return cout << "SUCCESS", 0;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '#') {
				int nspikes = spikes;
				if (maze[nx][ny] == 's') nspikes++;
				if (nspikes < spikesSoFar[nx][ny] && nspikes <= j / 2) {
					spikesSoFar[nx][ny] = nspikes;
					q.push({nx, ny, nspikes});
				}
			}
		}
	}
	
	return cout << "IMPOSSIBLE", 0;
}
