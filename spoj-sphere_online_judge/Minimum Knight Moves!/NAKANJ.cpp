#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int N = 8, oo = 1e9;
	const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
	const int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
	auto valid = [](int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; };
	
	int t;
	cin >> t;
	while (t--) {
		string s, e;
		cin >> s >> e;
		array<int, 2> start = {s[0] - 'a', s[1] - '1'};
		array<int, 2> end = {e[0] - 'a', e[1] - '1'};
		vector<vector<int>> dist(N, vector<int>(N, oo));

		queue<array<int, 2>> q;
		q.push(start);
		dist[start[0]][start[1]] = 0;

		while (!q.empty()) {
			int x = q.front()[0], y = q.front()[1];
			q.pop();

			if (x == end[0] && y == end[1]) break;
			for (int i = 0; i < 8; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (valid(nx, ny) && dist[nx][ny] == oo) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({nx, ny});
				}
			}
		}

		cout << dist[end[0]][end[1]] << el;
	}
	
	return 0;
}
