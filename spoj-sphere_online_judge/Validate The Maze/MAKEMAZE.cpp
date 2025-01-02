#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, ex, ey;
bool acc;
vector<vector<bool>> vis;
vector<vector<char>> adjmtx;
bool valid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y) {
	if (!valid(x, y) || vis[x][y] || adjmtx[x][y] != '.' || acc) return;
	if (x == ex && y == ey) {
		acc = true;
		return;
	}

	vis[x][y] = true;
	for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i]);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		acc = false;
		adjmtx.assign(n, vector<char>(m));
		vis.assign(n, vector<bool>(m, false));

		int openings = 0, sx, sy;
		sx = sy = ex = ey = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> adjmtx[i][j];
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
					if (adjmtx[i][j] == '.') {
						openings += 1;
						if (sx == -1 && sy == -1) {
							sx = i, sy = j;
						} else ex = i, ey = j;
					}
				}
			}
		}

		if (openings != 2) cout << "invalid" << el;
		else {
			dfs(sx, sy);
			cout << (acc? "valid": "invalid") << el;
		}
	}

	return 0;
}

