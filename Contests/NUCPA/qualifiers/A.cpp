#include <bits/stdc++.h>
using namespace std;
#define pi pair<int32_t, int32_t>
#define fst first
#define scd second
#define el '\n'

const int dr[] = {-1, 0, 1, 0}, oo = 1e9+7;
const int dc[] = {0, -1, 0, 1};
int32_t n, m;
bool valid(int32_t r, int32_t c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

int32_t main() {
	scanf("%d %d", &n, &m);

	char grid[n][m];
	vector<vector<vector<pi>>> goats(n, vector<vector<pi>>(m));
	vector<vector<vector<pi>>> wolves(n, vector<vector<pi>>(m));
	map<pi, int> wolfConns;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf(" %c", &grid[i][j]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int dir = 0; dir < 4; ++dir) {
				int32_t ni = dr[dir] + i;
				int32_t nj = dc[dir] + j;

				if (grid[i][j] == 'G' && valid(ni, nj) && grid[ni][nj] == 'W') {
					goats[i][j].push_back({ni, nj});
					wolfConns[{ni, nj}]++;
				} else if (grid[i][j] == 'W' && valid(ni, nj) && grid[ni][nj] == 'G') {
					wolves[i][j].push_back({ni, nj});
				}
			}
		}
	}

	priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<>> pq;
	for (auto &[pos, cnt] : wolfConns) {
		pq.push({cnt, pos});
	}

	int32_t ans = 0;
	set<pair<int32_t, int32_t>> blocked;

	while (!pq.empty()) {
		auto [_, wolf] = pq.top(); pq.pop();
		int wi = wolf.fst, wj = wolf.scd;

		if (blocked.count({wi, wj})) continue;

		pair<pi, int> mn = {{-1, -1}, oo};

		for (auto &[gi, gj] : wolves[wi][wj]) {
			if (blocked.count({gi, gj})) continue;
			if ((int)goats[gi][gj].size() < mn.scd) {
				mn = {{gi, gj}, (int)goats[gi][gj].size()};
			}
		}

		if (mn.fst.fst != -1) {
			ans++;
			blocked.insert(mn.fst);
		}
	}

	return printf("%d", ans), 0;
}
