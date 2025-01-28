#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int oo = 1e9; // Infinity
	const int dr[] = {-1, 0, 1, 0};
	const int dc[] = {0, -1, 0, 1};

	int r, c;
	cin >> r >> c;

	auto valid = [&](int rr, int cc) { return rr >= 0 && rr < r && cc >= 0 && cc < c; };

	vector<string> forest(r);
	array<int, 2> start, end;
	vector<array<int, 2>> enemies;

	for (int i = 0; i < r; ++i) {
		cin >> forest[i];
		for (int j = 0; j < c; ++j) {
			if (forest[i][j] == 'S') start = {i, j};
			else if (forest[i][j] == 'E') end = {i, j};
			else if (forest[i][j] > '0' && forest[i][j] <= '9') {
				enemies.push_back({i, j});
			}
		}
	}

	vector<vector<int>> dist(r, vector<int>(c, oo));
	queue<array<int, 2>> q;
	q.push({end[0], end[1]});
	dist[end[0]][end[1]] = 0;

	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dr[i];
			int ny = y + dc[i];

			if (valid(nx, ny) && dist[nx][ny] == oo && forest[nx][ny] != 'T') {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}

	int mnBattles = 0, meDist = dist[start[0]][start[1]];
	for (auto enemy: enemies) {
		int enemyDist = dist[enemy[0]][enemy[1]];
		if (enemyDist <= meDist) mnBattles += forest[enemy[0]][enemy[1]] - '0';
	}

	return cout << mnBattles, 0;
}
