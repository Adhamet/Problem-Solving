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

	vector<string> g(n);
	for (int i = 0; i < n; ++i) cin >> g[i];

	array<int, 2> s, e;
	cin >> s[0] >> s[1] >> e[0] >> e[1];
	s[0]--, s[1]--, e[0]--, e[1]--;

	if (s[0] == e[0] && s[1] == e[1]) return cout << 0, 0;

	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<array<int, 2>> q;
	dist[s[0]][s[1]] = 0;
	q.push(s);
	
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			for (int step = 1; step <= k; ++step) {
				int nx = x + dr[i] * step;
				int ny = y + dc[i] * step;

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
				if (g[nx][ny] == '#') break;

				if (dist[nx][ny] == -1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({nx, ny});
					if (nx == e[0] && ny == e[1]) return cout << dist[nx][ny], 0;
				} else if (dist[nx][ny] != dist[x][y] + 1) break;
			}
		}
	}

	return cout << -1, 0;
}
